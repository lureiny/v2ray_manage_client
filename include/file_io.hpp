#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <string>

const int BUFFER_SIZE = 65536 * 4;

bool ReadJson(const char *file, rapidjson::Document *root);

bool WriteJson(const char *file, rapidjson::Document *root);

#endif