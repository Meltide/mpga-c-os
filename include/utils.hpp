#pragma once

#include <sstream>
#include <string_view>
#include <vector>
#include <iomanip>
#include <random>
#include <thread>
#include <chrono>
#include <algorithm>

#include <cstdlib>
#include <cstdint>

inline int randint(int min, int max) {
    static std::random_device genr;
    static std::mt19937 gen(genr());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

inline std::string choice(const std::vector<std::string>& options) {
    if (options.empty()) return "";
    return options[randint(0, options.size() - 1)];
}

inline void sleep(double time) {
    std::this_thread::sleep_for(std::chrono::nanoseconds(static_cast<long long>(time * 1e9)));
}

inline void clear() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

inline std::string decode_base64(const std::string& encoded) {
    const auto base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                             "abcdefghijklmnopqrstuvwxyz"
                             "0123456789+/";
    
    std::vector<uint8_t> decoded;
    int val = 0, valb = -8;
    
    for (uint8_t c : encoded) {
        if (c == '=') break;
        if (std::isspace(c)) continue;
        
        const auto* ptr = std::strchr(base64_chars, c);
        if (!ptr) throw std::runtime_error("Invalid base64 character");
        
        val = (val << 6) + (ptr - base64_chars);
        valb += 6;
        
        if (valb >= 0) {
            decoded.push_back(uint8_t((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    
    std::stringstream result;
    for (auto content: decoded) {
        result << content;
    }
    
    return result.str();
}

inline std::string currentTime(const std::string& format) {
    auto now = std::chrono::system_clock::now();
    time_t t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(localtime(&t), format.c_str());
    return ss.str();
}

constexpr inline size_t hash(std::string_view in) {
    size_t hash = 5381;
    for (char c: in)
        hash = (hash << 5) + hash + c;
    return hash;
}