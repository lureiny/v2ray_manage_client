#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "local_stats.pb.h"
#include <string>

const int BUFFER_SIZE = 65536 * 4;

bool ReadJson(const char *file, rapidjson::Document *root);

bool WriteJson(const char *file, rapidjson::Document *root);

// 读取本地统计结果
bool ReadLocalStats(const std::string &local_file, local::LocalStats &local_stats);

// 更新本地统计结果，写入文件
bool WriteLocalStats(const std::string &local_file, local::LocalStats &local_stats);

#endif