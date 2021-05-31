#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>

#include "file_io.hpp"

#include "rapidjson/rapidjson.h"
#include "rapidjson/writer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/prettywriter.h"

#include "local_stats.pb.h"

using namespace std;
using namespace rapidjson;
using namespace local;

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

bool WriteLocalStats(const string &local_file, LocalStats &local_stats)
{
    fstream output(local_file, ios::out | ios::binary | ios::trunc);
    if (!output)
    {
        cout << "Local stats file open to write failed: " << local_file << endl;
    }
    if (!local_stats.SerializeToOstream(&output))
    {
        cout << "Write to local stats file failed." << endl;
        return false;
    }
    output.close();
    return true;
}

bool ReadLocalStats(const string &local_file, LocalStats &local_stats)
{
    fstream input(local_file, ios::in | ios::binary);
    if (!input)
    {
        cout << "Local stats file open to read failed: " << local_file << endl;
        return false;
    }
    if (!local_stats.ParseFromIstream(&input))
    {
        cout << "Read local stats file parse failed." << endl;
        return false;
    }
    return true;
}