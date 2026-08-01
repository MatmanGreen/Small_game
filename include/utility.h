#ifndef UTILITY_H
#define UTILITY_H

#include <string_view>

namespace Util
{
    inline constexpr std::string_view ACTIONS = R"ART(
▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌
▐ 1) ATTACK     2) ABILITY ▌
▐ 3) SPELL      4) ITEM    ▌
▐▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌
)ART";
}

#endif