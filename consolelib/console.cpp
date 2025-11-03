#include "console.hpp"
#include <iostream>

CONSOLE_API void Console::print(const char* text)
{
    std::cout << text << std::endl;
}