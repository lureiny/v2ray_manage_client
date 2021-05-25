#ifndef FLAGS_H_
#define FLAGS_H_
#include <gflags/gflags.h>

DECLARE_string(server);
DECLARE_bool(write_config);
DECLARE_string(operation);
DECLARE_string(inbound_tag);
DECLARE_string(v2ray_config);
DECLARE_string(protocol);
DECLARE_string(name);
DECLARE_string(id);
DECLARE_string(query_pattern);
DECLARE_string(stats_name);
DECLARE_bool(reset);
DECLARE_bool(cluster_mode);
DECLARE_string(redis_server);
DECLARE_int32(redis_port);
DECLARE_string(redis_user);
DECLARE_string(redis_password);
DECLARE_string(redis_channel);
DECLARE_string(local_stats_file);
DECLARE_uint64(update_local_stats_time);

#endif