#include <iostream>
#include <gflags/gflags.h>
#include <fstream>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "handler_service_client.hpp"
#include "stats_service_client.hpp"
#include "gflags.hpp"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

// define flags
DEFINE_string(server, "localhost:10085", "v2ray Api address");
DEFINE_bool(write_config, false, "write to v2ray config");
DEFINE_string(operation, "", "The operation that you want to do. \
             It can be \"add_user\", \"remove_user\", \"get_sys_stats\", \"query_stats\",\"get_stats\".");
DEFINE_string(inbound_tag, "", "The tag of the inbound which you want to alter.");
DEFINE_string(v2ray_config, "/usr/local/etc/v2ray/config.json", "The config file of v2ray.");
DEFINE_string(protocol, "", "The protocol of inbound config. It can be vmess/vless");
DEFINE_string(name, "", "The inbound user that will be add/remove.");
DEFINE_string(uuid, "", "The uuid is needed when add user. If uuid is not entered, program will random generate one.");
DEFINE_string(query_pattern, "", "The pattern of query stats. If \"operation=query_stats\", it is needed. It can be empty.");
DEFINE_string(stats_name, "", "The pattern of get stats. If \"operation=get_stats\", it is needed. It can not be empty");
DEFINE_bool(reset, false, "Whether to reset stats account");

string GenerateUUID()
{
    return to_string(boost::uuids::random_generator()());
}

int RPCHandlerService()
{
    HandlerServiceClient handler(grpc::CreateChannel(FLAGS_server, grpc::InsecureChannelCredentials()));
    if (FLAGS_inbound_tag == "")
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
            return -1;
        }
        // close ifstream
        fin.close();
    }

    if (FLAGS_operation == ADD_USER_OPERATION)
    {
        if (FLAGS_name == "")
        {
            cout << "User name is needed when add user. The user name can be an email address." << endl;
            return -1;
        }
        else if (FLAGS_protocol != PROTOCOL_VLESS && FLAGS_protocol != PROTOCOL_VMESS)
        {
            cout << "Which protocol inbound is needed be alter? The protocol can be vless/vmess" << endl;
            return -1;
        }
        if (FLAGS_uuid == "")
        {
            FLAGS_uuid = GenerateUUID();
        }
        auto r = handler.AddUser(FLAGS_inbound_tag, FLAGS_name, FLAGS_protocol, FLAGS_uuid);
        if (!r)
        {
            cout << "Add user operation is failed." << endl;
            return -1;
        }
    }
    else if (FLAGS_operation == REMOVE_USER_OPERATION)
    {
        if (FLAGS_name == "")
        {
            cout << "User name is needed when remove user." << endl;
            return -1;
        }
        auto r = handler.RemoveUser(FLAGS_inbound_tag, FLAGS_name);
        if (!r)
        {
            cout << "Remove user operation is failed." << endl;
            return -1;
        }
    }
    else
    {
        cout << "Unsupport operation: " << FLAGS_operation << endl;
        return -1;
    }
}

int RPCStatsService()
{
    StatsServiceClient stats(grpc::CreateChannel(FLAGS_server, grpc::InsecureChannelCredentials()));

    if (FLAGS_operation == QUERY_STATS_REQUEST_OPERATION)
    {
        if (!stats.QueryStats(FLAGS_query_pattern, FLAGS_reset))
        {
            // TODO 抛出异常
            return -1;
        }
    }
    else if (FLAGS_operation == GET_STATS_REQUEST_OPERATION)
    {
        if (FLAGS_stats_name == "")
        {
            cout << "stats name can not be empty" << endl;
            // TODO 抛出异常
            return -1;
        }   
        if (!stats.GetStats(FLAGS_stats_name, FLAGS_reset))
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

int main(int argc, char **argv)
{
    gflags::SetVersionString("0.5");
    string usage_message = "add or remove v2ray inbound user. Query stats info.";
    gflags::SetUsageMessage(usage_message);
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    int code = 0;

    if (FLAGS_operation == "")
    {
        cout << "Operation parameter missing." << endl;
        code = -1;
    }
    else if (FLAGS_operation == ADD_USER_OPERATION || FLAGS_operation == REMOVE_USER_OPERATION)
    {
        code = RPCHandlerService();
    }
    else if (FLAGS_operation == QUERY_STATS_REQUEST_OPERATION ||
             FLAGS_operation == GET_STATS_REQUEST_OPERATION ||
             FLAGS_operation == SYS_STATS_REQUEST_OPERATION)
    {
        code = RPCStatsService();
    }
    else
    {
        cout << "Unsupport operation: " << FLAGS_operation << endl;
        code = -1;
    }

    return code;
}