#pragma once

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

inline void SetStdinEcho(bool enable = true) {
#ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    if (!enable)
        mode &= ~ENABLE_ECHO_INPUT;
    else
        mode |= ENABLE_ECHO_INPUT;
    SetConsoleMode(hStdin, mode);
#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if (!enable)
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}

inline std::string GetHiddenInput() {
    SetStdinEcho(false);
    std::string input;
#ifdef _WIN32
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!input.empty()) {
                input.pop_back();
                std::cout << "\b \b";
            }
        } else {
            input.push_back(ch);
            std::cout << '*';
        }
    }
#else
    std::cin >> input;
#endif
    SetStdinEcho(true);
    std::cout << std::endl;
    return input;
}