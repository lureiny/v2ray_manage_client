#include "src/app/stats/stat.h"

#include <gtest/gtest.h>

#include "src/app/stats/command/command.pb.h"

namespace v2m {
namespace stat {
TEST(StatTest, Init01) {
  // Construct Stat by info.
  Stat v2m_stat(16893, 18752, "user", "stat_test");
  EXPECT_EQ("user", v2m_stat.GetType());
  EXPECT_EQ("stat_test", v2m_stat.GetLabel());
  EXPECT_EQ(16893, v2m_stat.GetDownlink());
  EXPECT_EQ(18752, v2m_stat.GetUplink());
}

TEST(StatTest, InitByV2rayStatAndUpdate) {
  // Construct Stat by v2ray::core::app::stats::command::Stat
  v2ray::core::app::stats::command::Stat v2ray_stat_downlink;
  v2ray_stat_downlink.set_name("user>>>stat_test>>>traffic>>>downlink");
  v2ray_stat_downlink.set_value(12345678);
  Stat v2m_stat(v2ray_stat_downlink);
  EXPECT_EQ("user", v2m_stat.GetType());
  EXPECT_EQ("stat_test", v2m_stat.GetLabel());
  EXPECT_EQ(12345678, v2m_stat.GetDownlink());

  // Update uplink.
  v2ray::core::app::stats::command::Stat v2ray_stat_uplink;
  v2ray_stat_uplink.set_name("user>>>stat_test>>>traffic>>>uplink");
  v2ray_stat_uplink.set_value(87654321);
  EXPECT_TRUE(v2m_stat.UpdateTraffic(v2ray_stat_uplink));
  EXPECT_EQ(87654321, v2m_stat.GetUplink());

  // Test update uplink with a different user's stat.
  v2ray::core::app::stats::command::Stat v2ray_stat_uplink1;
  v2ray_stat_uplink1.set_name("user>>>stat_test1>>>traffic>>>uplink");
  v2ray_stat_uplink1.set_value(87654321);
  EXPECT_FALSE(v2m_stat.UpdateTraffic(v2ray_stat_uplink1));
  EXPECT_EQ(87654321, v2m_stat.GetUplink());
}

}  // namespace stat
}  // namespace v2m
