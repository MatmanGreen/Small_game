#include "c.h"
#include <iostream>
using namespace std;


Character::Character(std::string name,
             int hp,
             int mp,
             int sp,
             int str_stat,
             int int_stat,
             int dex_stat,
             int speed)
    : name_(name),
      hp_(hp),
      mp_(mp),
      sp_(sp),
      str_(str_stat),
      int_(int_stat),
      dex_(dex_stat),
      speed_(speed)
{}

string Character::get_name() const {return name_;}

int Character::get_hp() const {return hp_;}
int Character::get_mp() const {return mp_;}
int Character::get_sp() const {return sp_;}

int Character::get_str_stat() const 
{
    int bonus = 0;
    for(size_t i = 0; i < active_buffs_.size(); i++)
    {
        if(active_buffs_[i].type == BuffType::Strength)
        {
            bonus += active_buffs_[i].value;
        }
    }
    return str_+bonus;
}
int Character::get_int_stat() const 
{
    int bonus = 0;
    for(size_t i = 0; i < active_buffs_.size(); i++)
    {
        if(active_buffs_[i].type == BuffType::Intelligence)
        {
            bonus += active_buffs_[i].value;
        }
    }
    return int_+bonus;
}
int Character::get_dex_stat() const 
{
    int bonus = 0;
    for(size_t i = 0; i < active_buffs_.size(); i++)
    {
        if(active_buffs_[i].type == BuffType::Dexterity)
        {
            bonus += active_buffs_[i].value;
        }
    }
    return dex_+bonus;
}
int Character::get_speed() const
{
    {
    int bonus = 0;
    for(size_t i = 0; i < active_buffs_.size(); i++)
    {
        if(active_buffs_[i].type == BuffType::Speed)
        {
            bonus += active_buffs_[i].value;
        }
    }
    return speed_+bonus;
}

}

void Character::set_hp(int hp) {hp_ = hp;}
void Character::set_mp(int mp) {mp_ = mp;}
void Character::set_sp(int sp) {sp_ = sp;}

void Character::reduce_hp(int hp) {hp_ -= hp;}
void Character::reduce_mp(int mp) {mp_ -= mp;}
void Character::reduce_sp(int sp) {sp_ -= sp;}

void Character::print_stats()
{
    cout << name_ << " (hp:" << hp_ <<", mp:" << mp_ << ", sp:" << sp_ << ")"; 
}


void Character::get_dmg_spell_list() const
{
    for(size_t i = 0; i < dmg_spells_.size(); i++)
    {
        cout << i << ": " << dmg_spells_[i].get_name() << endl;
    }
}
void Character::add_dmg_spell(DmgSpell& spell){dmg_spells_.push_back(spell);}
const DmgSpell& Character::get_dmg_spell(int index) const{return dmg_spells_[index];}

void Character::get_heal_spell_list() const
{
    for(size_t i = 0; i < heal_spells_.size(); i++)
    {
        cout << i << ": " << heal_spells_[i].get_name() << endl;
    }
}
void Character::add_heal_spell(HealSpell& spell){heal_spells_.push_back(spell);}
const HealSpell& Character::get_heal_spell(int index) const{return heal_spells_[index];}

void Character::get_buff_spell_list() const
{
    for(size_t i = 0; i < buff_spells_.size(); i++)
    {
        cout << i << ": " << buff_spells_[i].get_name() << endl;
    }
}
void Character::add_buff_spell(BuffSpell& spell){buff_spells_.push_back(spell);}
const BuffSpell& Character::get_buff_spell(int index) const{return buff_spells_[index];}

void Character::get_debuff_spell_list() const
{
    for(size_t i = 0; i < debuff_spells_.size(); i++)
    {
        cout << i << ": " << debuff_spells_[i].get_name() << endl;
    }
}
void Character::add_debuff_spell(DebuffSpell& spell){debuff_spells_.push_back(spell);}
const DebuffSpell& Character::get_debuff_spell(int index) const{return debuff_spells_[index];}

void Character::get_all_spell_list() const
{
    get_dmg_spell_list();
    get_heal_spell_list();
    get_buff_spell_list();
    get_debuff_spell_list();
}

void Character::add_buff(BuffType type, int value, int duration)
{
    active_buffs_.push_back({type, value, duration});
}
