#pragma once

#include <string>
#include "utils.hpp"

std::string generate_prompt(std::string user, std::string hostname) {
    return
    "[" + currentTime("%m/%d %H:%M:%S") + "] \033[32m" + user + "\033[0m@" + hostname + "\033[34m ~\033[0m> ";
}