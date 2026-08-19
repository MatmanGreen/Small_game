#ifndef UTILITY_H
#define UTILITY_H

class Character;

#include <string_view>
#include <string>
#include <iostream>


namespace Util
{
inline constexpr std::string_view ACTIONS = R"ART(
[1] ATTACK     [2] ABILITY 
[3] SPELL      [4] ITEM    
)ART";

inline constexpr std::string_view SPELLTYPES = R"ART(
[1] DAMAGE     [2] HEAL 
[3] BUFF       [4] DEBUFF    
)ART";
}

enum class BuffType
{
    Strength,
    Intelligence,
    Dexterity,
    Speed
};

enum class PotionType
{
    Hp,
    Mp,
    Sp
};

struct ActiveBuff
{
    BuffType type;
    int value;
    int remaining_turns;
};

struct ActiveDebuff
{
    BuffType type;
    int value;
    int remaining_turns;
};

#endif