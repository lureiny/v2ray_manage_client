#include <string>
#include <cstdio>
#include <iostream>

#include "file_io.hpp"

#include "rapidjson/rapidjson.h"
#include "rapidjson/writer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/prettywriter.h"

using namespace std;
using namespace rapidjson;

bool ReadJson(const char *file, rapidjson::Document *root)
{
    FILE *fp = fopen(file, "r");
    if (!fp)
    {
        cout << "Config file open to read failed " << file << endl;
        return false;
    }
    char read_buffer[BUFFER_SIZE];
    FileReadStream file_read_stream(fp, read_buffer, sizeof(read_buffer));

    root->ParseStream(file_read_stream);

    fclose(fp);

    return true;
}

bool WriteJson(const char *file, rapidjson::Document *root)
{
    FILE *fp = fopen(file, "w");
    if (!fp)
    {
        cout << "Config file open to write failed " << file << endl;
        return false;
    }
    char writer_buffer[BUFFER_SIZE];
    FileWriteStream file_writer_stream(fp, writer_buffer, sizeof(writer_buffer));

    PrettyWriter<FileWriteStream> writer(file_writer_stream);

    root->Accept(writer);

    fclose(fp);
}