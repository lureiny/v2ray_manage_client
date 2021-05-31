#ifndef COMMON_HPP
#define COMMON_HPP

#include <string>
#include <vector>
#include <regex>

#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "redis.pb.h"
#include "app/stats/command/command.pb.h"
#include "local_stats.pb.h"

const std::regex REGEX("(user|inbound|outbound)>>>(\\S+)>>>traffic>>>(downlink|uplink)");

bool FindInbound(rapidjson::Document *root, rapidjson::Value **node, const std::string &inbound_tag);

bool AddUserToConfig(rapidjson::Document *root, const std::string &tag, const std::string &email, const std::string &id);

bool RemoveUserFromConfig(rapidjson::Document *root, const std::string &tag, const std::string &email);

// 获取结果从v2ray stat 转换成redis stats
void ParseV2rayStatToRedisStats(v2ray::core::app::stats::command::QueryStatsResponse *, std::vector<redis::Stats> &);

// 合并本地结果
void MergeLocalStats(local::LocalStats *new_local_stats, local::LocalStats *old_local_stats);

// 统计、合并、更新本地统计信息
bool CountLocalStats(const std::string &local_file);

#endif