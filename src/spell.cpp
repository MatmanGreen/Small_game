#include "spell.h"

Spell::Spell(std::string name, int dmg, int cost): name_(name), dmg_(dmg), cost_(cost) {}

std::string Spell::get_name() const
{
    return name_;
}
int Spell::get_dmg() const
{
    return dmg_;
}
int Spell::get_cost() const
{
    return cost_;
}