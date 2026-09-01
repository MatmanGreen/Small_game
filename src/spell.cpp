#include "spell.h"
#include "c.h"
#include "enemy.h"

Buff::Buff(BuffType type, int value, int turns_left): 
    type_(type), value_(value), turns_left_(turns_left) {}

BuffType Buff::get_bufftype() const {return type_;}
int Buff::get_value() const {return value_;}
int Buff::get_turns_left() const {return turns_left_;}

bool Buff::is_active() {if(turns_left_ <= 0) return false; else return true;}
void Buff::tick() {--turns_left_;}


Spell::Spell(std::string name, int value, int cost, float chance): 
    name_(name), value_(value), cost_(cost), chance_(chance) {}

std::string Spell::get_name() const {return name_;}
int Spell::get_value() const {return value_;}
int Spell::get_cost() const {return cost_;}
float Spell::get_chance() const {return chance_;}

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

/*
BuffSpell::BuffSpell(std::string name, 
            int value,
            int cost, 
            float chance,
            Buff buff)
            : Spell(name, value, cost, chance),
            buff_(buff)
{} 

int BuffSpell::get_duration() const {return buff_.get_turns_left();}
void BuffSpell::action(Character& caster, Enemy&)
{
    caster.add_buff(get_bufftype(), get_value(), get_duration());
}
BuffType BuffSpell::get_bufftype() const {return buff_.get_bufftype();}

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

int DebuffSpell::get_duration() const {return duration_;}
void DebuffSpell::action(Character&, Enemy& target)
{
    target.add_debuff(get_debufftype(), get_value(), get_duration());
}
BuffType DebuffSpell::get_debufftype() const {return type_;}
*/

BuffSpell::BuffSpell(std::string name, int value, int cost, float chance, Buff buff):
    Spell(name, value, cost, chance), buff_(buff) {}

int BuffSpell::get_duration() const {return buff_.get_turns_left();}
void BuffSpell::action(Character& caster, Enemy& target)
{
    caster.add_buff(buff_);
}

DebuffSpell::DebuffSpell(std::string name, int value, int cost, float chance, Buff debuff):
    Spell(name, value, cost, chance), debuff_(debuff) {}

int DebuffSpell::get_duration() const {return debuff_.get_turns_left();}
void DebuffSpell::action(Character& caster, Enemy& target)
{
    caster.add_debuff(debuff_);
}