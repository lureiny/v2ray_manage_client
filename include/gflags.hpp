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
DECLARE_string(uuid);
DECLARE_string(query_pattern);
DECLARE_string(stats_name);
DECLARE_bool(reset);

#endif