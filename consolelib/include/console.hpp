#ifndef __CONSOLE_HPP__
#define __CONSOLE_HPP__

#ifdef _WIN32
    #ifdef BUILDING_CONSOLE_DLL
        #define CONSOLE_API __declspec(dllexport)
    #else
        #define CONSOLE_API __declspec(dllimport)
    #endif
#else
    #define CONSOLE_API
#endif

class Console
{
    public:
    static CONSOLE_API void print(const char* text);
};

#endif // __CONSOLE_HPP__