#include <iostream>
#include <fstream>

#include "include/init.hpp"
#include "include/utils.hpp"

CosInit::CosInit() : error_code(0) {
    tips_list = {
        "You can find the default password in the passwd file.",
        "Maybe the coverter is useless :)",
        "'root' is the default user.",
        "Is this file system real?",
        "Columns make the calculator work."
    };
    
    std::ifstream profiles_file("configs/profiles.json");
    if (profiles_file.is_open()) {
        profiles_file >> profiles;
        hostname = profiles["hostname"];
        users = profiles["users"];
    } else {
        std::cerr << "Error: \033[31mCould not open profiles.json\033[0m" << std::endl;
        error_code = 1;
    }
    profiles_file.close();
    
    std::ifstream policys_file("configs/system_policys.json");
    if (policys_file.is_open()) {
        policys_file >> policys;
    } else {
        std::cerr << "Error: \033[31mCould not open profiles.json\033[0m" << std::endl;
        error_code = 1;
    }
    policys_file.close();
}