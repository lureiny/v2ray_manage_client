#pragma once

#include <assert.h>

#include <regex>
#include <string>

#include "src/app/stats/command/command.pb.h"

namespace v2m {
namespace stat {
const std::regex kRegexForTraffic("(user|inbound|outbound)>>>(\\S+)>>>traffic>>>(downlink|uplink)");

class Stat {
 public:
  Stat(int64_t downlink, int64_t uplink, std::string type, std::string label)
      : downlink_(downlink), uplink_(uplink), type_(type), label_(label) {}

  // Init from v2ray::core::app::stats::command::Stat
  Stat(const v2ray::core::app::stats::command::Stat& v2ray_stat) {
    std::smatch smatch_result = ParseV2rayStatValue(v2ray_stat.name());
    assert(smatch_result.size() == 4);

    // Init label_ and type_.
    label_ = smatch_result[2];
    type_ = smatch_result[1];
    SetTraffic(smatch_result, v2ray_stat.value());
  }

  // Update stat's link data.
  bool UpdateTraffic(const v2ray::core::app::stats::command::Stat& v2ray_stat) {
    std::smatch smatch_result = ParseV2rayStatValue(v2ray_stat.name());
    if (smatch_result.size() != 4) {
      return false;
    }

    return SetTraffic(smatch_result, v2ray_stat.value());
  }

  inline int64_t GetDownlink() { return downlink_; }
  inline int64_t GetUplink() { return uplink_; }
  inline std::string GetType() { return type_; }
  inline std::string GetLabel() { return label_; }

 private:
  int64_t downlink_;
  int64_t uplink_;
  // The stats's type, user or inbound or outbound.
  std::string type_;
  // The label_ is the v2ray user's email or inbound/outbound's tag.
  std::string label_;

  inline std::smatch ParseV2rayStatValue(const std::string& traffic_info) {
    std::smatch smatch_result;
    std::regex_search(traffic_info, smatch_result, kRegexForTraffic);
    return smatch_result;
  }

  inline bool SetTraffic(const std::smatch& smatch_result, int64_t link_data) {
    if (!(smatch_result[2] == label_ && smatch_result[1] == type_)) {
      return false;
    }

    if (smatch_result[3] == "downlink") {
      downlink_ = link_data;
    } else {
      uplink_ = link_data;
    }
    return true;
  }
};
}  // namespace stat
}  // namespace v2m
