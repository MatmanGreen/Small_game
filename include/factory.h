#ifndef MONSTER_FACTORY_H
#define MONSTER_FACTORY_H

#include <vector>
#include <memory>
#include "enemy.h"
#include "spell.h"
#include "item.h"


enum class MonsterId
{
    Devil,
    Earthdragon,
    Goofydragon,
};
std::vector<Enemy> create_monsters();

enum class SpellId
{
        Fireball,
        Icicle,
        LightHeal,
};
std::vector<std::unique_ptr<Spell>> create_spells();

enum class PotionId
{
    Hp,
    Mp,
    Sp,
};
std::vector<Potion> create_potions();

#endif