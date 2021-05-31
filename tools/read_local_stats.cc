#include "redis.pb.h"
#include "local_stats.pb.h"
#include "file_io.hpp"

#include <iostream>

using local::LocalStats;
using redis::Stats;

using namespace std;

int main(int argc, char **argv)
{

    if (argc <= 1)
    {
        cout << "Please input local stats file." << endl;
        return -1;
    }
    LocalStats local_stat;
    if (!ReadLocalStats(argv[1], local_stat))
    {
        return -1;
    }
    cout << "online" << endl;
    for (size_t index = 0; index < local_stat.online().stats_size(); ++index)
    {
        cout << "Name: " << local_stat.online().stats(index).name() << endl;
        cout << "Type: " << local_stat.online().stats(index).type() << endl;
        cout << "Downlink: " << local_stat.online().stats(index).downlink() << endl;
        cout << "Uplink: " << local_stat.online().stats(index).uplink() << endl;
        cout << endl;
    }

    cout << "offline" << endl;
    for (size_t index = 0; index < local_stat.history().stats_size(); ++index)
    {
        cout << "Name: " << local_stat.history().stats(index).name() << endl;
        cout << "Type: " << local_stat.history().stats(index).type() << endl;
        cout << "Downlink: " << local_stat.history().stats(index).downlink() << endl;
        cout << "Uplink: " << local_stat.history().stats(index).uplink() << endl;
    }
}
