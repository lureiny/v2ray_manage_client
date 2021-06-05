#ifndef OPERATION_HPP
#define OPERATION_HPP

#include <string>

struct operation_struct
{
    std::string type = "";
    std::string inbound_tag = "";
    std::string email = "";
    std::string protocol = "";
    std::string id = "";
    std::string stats_name = "";
    bool reset = false;
    std::string query = "";
};

#endif