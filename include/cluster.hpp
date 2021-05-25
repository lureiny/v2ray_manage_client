#ifndef CLUSTER_HPP
#define CLUSTER_HPP

#include "gflags.hpp"

// 进入集群模式
int Cluster();

// 配合集群模式应用的自动更新统计信息
void AutoUpdasteLocalStats();

#endif