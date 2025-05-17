#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

#include "include/utils.hpp"
#include "include/init.hpp"
#include "include/foxShell.hpp"

class Cos: public CosInit {
public:
    using CosInit::CosInit;
    
    void print_startup_info() {
        std::vector<std::string> print_list = {
            "\033[2m\nMPGA C-OS Open Source System V" + VERSION + "\033[0m",
            "\033[34m __  __  ___   ___    _",
            "|  \\/  || _ \\ / __|  /_\\",
            "| |\\/| ||  _/| (_ | / _ \\",
            "|_|  |_||_|   \\___|/_/ \\_\\\033[0m",
            "\n\033[33mA fake system based on C++\033[0m\n",
            "Tip: " + choice(tips_list),
            policys["show_ad"]
            ?"\n\033[36mAlso try PyOS's improved version by minqwq and bibimingming!\033[0m\n"
            :""
        };
        
        for (const auto& msg : print_list) {
            std::cout << msg << std::endl;
            sleep(0.05);
        }
    }
    
    void login() {
        while (true) {
            std::cout << hostname << " login: ";
            std::getline(std::cin, user);
            
            if (users.find(user) != users.end())
                break;
            else
                std::cerr << "\033[31mUnknown username.\033[0m\n";
        }
        
        while (true) {
            std::string input_passwd;
            std::cout << "Password: ";
            std::getline(std::cin, input_passwd);
            
            if (input_passwd == decode_base64(users[user])) {
                std::cout << "Last login: \033[36m" << currentTime("%y/%m/%d %H:%M:%S") << "\033[0m\n\n";
                break;
            } else
                std::cerr << "\033[31mPassword incorrect.\033[0m\n";
        }
    }
    
    void start_shell() {
        std::string cmd;
        
        while (true) {
            std::cout << generate_prompt(user, hostname);
            std::getline(std::cin, cmd);
            
            switch (hash(cmd)) {
                case hash("exit"):
                    std::cout << "\n";
                    login();
                    break;
                case hash("restart"): run();break;
                case hash("shutdown"): exit(0);
                default:
                    std::cerr << "Error: " << "\033[31mUnknown command: '" << cmd << "'\033[0m\n";
            }
        }
    }
    
    void run() {
        clear();
        print_startup_info();
        login();
        start_shell();
    }
};

int main() {
    #ifdef _WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut != INVALID_HANDLE_VALUE) {
            DWORD dwMode = 0;
            if (GetConsoleMode(hOut, &dwMode)) {
                dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
                SetConsoleMode(hOut, dwMode);
            }
        }
    #endif

    Cos system;
    system.run();
    
    return 0;
}