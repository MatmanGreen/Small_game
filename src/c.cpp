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
      str_(str_stat),
      int_(int_stat),
      dex_(dex_stat),
      speed_(speed)
{
    max_hp_ = hp+dex_;
    max_mp_ = mp+int_;
    max_sp_ = sp+str_;
    hp_ = max_hp_;
    mp_ = max_mp_;
    sp_ = max_sp_;
}

string Character::get_name() const {return name_;}

int Character::get_hp() const {return hp_;}
int Character::get_mp() const {return mp_;}
int Character::get_sp() const {return sp_;}

void Character::set_max_hp(int hp) {max_hp_ = hp;}
void Character::set_max_mp(int mp) {max_mp_ = mp;}
void Character::set_max_sp(int sp) {max_sp_ = sp;}

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

void Character::set_hp(int hp) 
{
    if(max_hp_ < hp)
        hp_ = max_hp_;
    else
        hp_ = hp;
}
void Character::set_mp(int mp) 
{
    if(max_mp_ < mp)
        mp_ = max_mp_;
    else
        mp_ = mp;
}
void Character::set_sp(int sp)
{
    if(max_sp_ < sp)
        sp_ = max_sp_;
    else
        sp_ = sp;
}
/*
void Character::add_hp(int hp) {hp_ += hp;}
void Character::add_mp(int mp) {mp_ += mp;}
void Character::add_sp(int sp) {sp_ += sp;}
*/

void Character::reduce_hp(int hp) {hp_ -= hp;}
void Character::reduce_mp(int mp) {mp_ -= mp;}
void Character::reduce_sp(int sp) {sp_ -= sp;}

void Character::print_stats()
{
    cout << name_ << " (hp:" << hp_ <<", mp:" << mp_ << ", sp:" << sp_ << ")"; 
}


// Abilitys
void Character::get_skill_list() const
{
    for (size_t i = 0; i < skill_list_.size(); i++)
    {
        cout << i << ": " << skill_list_[i].get_name() << endl;
    }
    
}
void Character::add_skill(Ability& skill){skill_list_.push_back(skill);}
int Character::get_skill_list_size(){return skill_list_.size();}
const Ability& Character::get_skill(int index) {return skill_list_[index];}


// Spells 
void Character::get_dmg_spell_list() const
{
    for(size_t i = 0; i < dmg_spells_.size(); i++)
    {
        cout << i << ": " << dmg_spells_[i].get_name() << endl;
    }
}
void Character::add_dmg_spell(DmgSpell& spell){dmg_spells_.push_back(spell);}
int Character::get_dmg_list_size(){return dmg_spells_.size();}
const DmgSpell& Character::get_dmg_spell(int index) const{return dmg_spells_[index];}

void Character::get_heal_spell_list() const
{
    for(size_t i = 0; i < heal_spells_.size(); i++)
    {
        cout << i << ": " << heal_spells_[i].get_name() << endl;
    }
}
void Character::add_heal_spell(HealSpell& spell){heal_spells_.push_back(spell);}
int Character::get_heal_list_size(){return heal_spells_.size();}
const HealSpell& Character::get_heal_spell(int index) const{return heal_spells_[index];}

void Character::get_buff_spell_list() const
{
    for(size_t i = 0; i < buff_spells_.size(); i++)
    {
        cout << i << ": " << buff_spells_[i].get_name() << endl;
    }
}
void Character::add_buff_spell(BuffSpell& spell){buff_spells_.push_back(spell);}
int Character::get_buff_list_size(){return buff_spells_.size();}
const BuffSpell& Character::get_buff_spell(int index) const{return buff_spells_[index];}

void Character::get_debuff_spell_list() const
{
    for(size_t i = 0; i < debuff_spells_.size(); i++)
    {
        cout << i << ": " << debuff_spells_[i].get_name() << endl;
    }
}
void Character::add_debuff_spell(DebuffSpell& spell){debuff_spells_.push_back(spell);}
int Character::get_debuff_list_size(){return debuff_spells_.size();}
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
void Character::add_debuff(BuffType type, int value, int duration)
{
    active_debuffs_.push_back({type, value, duration});
}
