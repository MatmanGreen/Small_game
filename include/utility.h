#ifndef UTILITY_H
#define UTILITY_H

#include <string_view>
#include <string>
#include <iostream>


namespace Util
{
inline constexpr std::string_view ACTIONS = R"ART(
[1] ATTACK     [2] ABILITY 
[3] SPELL      [4] ITEM    
)ART";
}

void clear()
{
    std::cout << "\033[2J\033[H";
}

#endif