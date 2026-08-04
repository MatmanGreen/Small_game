#include "spell.h"
#include "c.h"
#include "enemy.h"

Spell::Spell(std::string name, int value, int cost, float chance): 
    name_(name), value_(value), cost_(cost), chance_(chance) {}

std::string Spell::get_name() const
{
    return name_;
}
int Spell::get_value() const
{
    return value_;
}
int Spell::get_cost() const
{
    return cost_;
}
float Spell::get_chance() const
{
    return chance_;
}

DmgSpell::DmgSpell(std::string name, 
            int value, 
            int cost, 
            float chance)
            : Spell (name,
            value, 
            cost, 
            chance) 
{
}

void DmgSpell::action(Character& caster, Enemy& target)
{
    target.reduce_hp(value_+int(caster.get_int_stat()*0.25));
}

HealSpell::HealSpell(std::string name, 
            int value, 
            int cost, 
            float chance)
            : Spell (name,
            value, 
            cost, 
            chance) 
{
}

void HealSpell::action(Character& caster, Enemy&)
{
    caster.set_hp(caster.get_hp()+value_+int(caster.get_int_stat()*0.25));
}

BuffSpell::BuffSpell(std::string name, 
            int value, 
            BuffType type,
            int cost, 
            float chance)
            : Spell (name,
            value, 
            cost, 
            chance),
            type_(type)
{
} 
void BuffSpell::action(Character& caster, Enemy&)
{

}


DebuffSpell::DebuffSpell(std::string name, 
            int value, 
            BuffType type,
            int cost, 
            float chance)
            : Spell (name,
            value, 
            cost, 
            chance),
            type_(type)
{
} 