#include <rpc.hpp>
#include <gflags.hpp>
#include <string>
#include <fstream>

#include "handler_service_client.hpp"
#include "stats_service_client.hpp"
#include "file_io.hpp"
#include "operation.hpp"

#include "rapidjson/rapidjson.h"
#include "common.hpp"

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/algorithm/string.hpp>

using v2ray::core::app::stats::command::QueryStatsResponse;

using namespace std;
using namespace rapidjson;

using redis::Stats;

string GenerateUUID()
{
    return to_string(boost::uuids::random_generator()());
}

int RPCHandlerService(operation_struct &operation_struct)
{
    HandlerServiceClient handler(grpc::CreateChannel(FLAGS_server, grpc::InsecureChannelCredentials()));
    if (operation_struct.inbound_tag == "")
    {
        cout << "one inbound tag is needed" << endl;
        return -1;
    }
    else if (FLAGS_write_config)
    {
        // Determine whether the v2ray config file exists
        ifstream fin(FLAGS_v2ray_config);
        if (!fin)
        {
            cout << "v2ray config file not exist." << endl;
            FLAGS_write_config = false;
        }
        // close ifstream
        fin.close();
    }

    if (operation_struct.type == ADD_USER_OPERATION)
    {
        if (operation_struct.email == "")
        {
            cout << "User name is needed when add user. The user name can be an email address." << endl;
            return -1;
        }
        else if (operation_struct.protocol != PROTOCOL_VLESS && operation_struct.protocol != PROTOCOL_VMESS)
        {
            cout << "Which protocol inbound is needed be alter? The protocol can be vless/vmess" << endl;
            return -1;
        }
        if (operation_struct.id == "")
        {
            operation_struct.id = GenerateUUID();
        }
        auto r = handler.AddUser(operation_struct.inbound_tag, operation_struct.email, operation_struct.protocol, operation_struct.id);
        if (!r)
        {
            cout << "Add user operation is failed." << endl;
            return -1;
        }
        if (FLAGS_write_config)
        {
            Document root;
            if (!ReadJson(FLAGS_v2ray_config.c_str(), &root))
            {
                return -1;
            }

            if (!AddUserToConfig(&root, operation_struct.inbound_tag, operation_struct.email, operation_struct.id))
            {
                return false;
            }

            return WriteJson(FLAGS_v2ray_config.c_str(), &root);
        }
    }
    else if (operation_struct.type == REMOVE_USER_OPERATION)
    {
        if (operation_struct.email == "")
        {
            cout << "User name is needed when remove user." << endl;
            return -1;
        }
        auto r = handler.RemoveUser(operation_struct.inbound_tag, operation_struct.email);
        if (!r)
        {
            cout << "Remove user operation is failed." << endl;
            return -1;
        }
        if (FLAGS_write_config)
        {
            Document root;
            if (!ReadJson(FLAGS_v2ray_config.c_str(), &root))
            {
                return -1;
            }

            if (!RemoveUserFromConfig(&root, operation_struct.inbound_tag, operation_struct.email))
            {
                return false;
            }

            return WriteJson(FLAGS_v2ray_config.c_str(), &root);
        }
    }
    else
    {
        cout << "Unsupport operation: " << operation_struct.type << endl;
        return -1;
    }
    return 0;
}

int RPCStatsService(operation_struct &operation_struct, QueryStatsResponse *query_stats_response_pointer)
{
    StatsServiceClient stats(grpc::CreateChannel(FLAGS_server, grpc::InsecureChannelCredentials()));

    if (operation_struct.type == QUERY_STATS_REQUEST_OPERATION)
    {
        if (!stats.QueryStats(operation_struct.query, operation_struct.reset, query_stats_response_pointer))
        {
            // TODO 抛出异常
            return -1;
        }
    }
    else if (operation_struct.type == GET_STATS_REQUEST_OPERATION)
    {
        if (operation_struct.stats_name == "")
        {
            cout << "stats name can not be empty. It should like \"(user|inbound|outbound)>>>[tag]>>>traffic>>>(uplink|downlink).\"" << endl;
            // TODO 抛出异常
            return -1;
        }
        if (!stats.GetStats(operation_struct.stats_name, operation_struct.reset))
        {
            return -1;
        }
    }
    else if (!stats.GetSysStats())
    {
        // TODO 抛出异常
        return -1;
    }
    return 0;
}