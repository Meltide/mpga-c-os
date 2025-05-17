#pragma once

#include <string>
#include <vector>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

class CosInit {
protected:
    const std::string
    VERSION = "1.0",
    SHELL_VERSION = "1.0",
    CORE_VERSION = "20250517";

    int error_code = 0;
    std::vector<std::string> tips_list;
    json profiles, policys;
    
public:
    std::string hostname, user;
    json users;
    
    CosInit();
};