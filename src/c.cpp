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
    max_weight_ = 100 + dex_;
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
        if(active_buffs_[i].get_bufftype() == BuffType::Strength)
        {
            bonus += active_buffs_[i].get_value();
        }
    }
    return str_+bonus;
}
int Character::get_int_stat() const 
{
    int bonus = 0;
    for(size_t i = 0; i < active_buffs_.size(); i++)
    {
        if(active_buffs_[i].get_bufftype() == BuffType::Intelligence)
        {
            bonus += active_buffs_[i].get_value();
        }
    }
    return int_+bonus;
}
int Character::get_dex_stat() const 
{
    int bonus = 0;
    for(size_t i = 0; i < active_buffs_.size(); i++)
    {
        if(active_buffs_[i].get_bufftype() == BuffType::Dexterity)
        {
            bonus += active_buffs_[i].get_value();
        }
    }
    return dex_+bonus;
}
int Character::get_speed() const
{
    int bonus = 0;
    for(size_t i = 0; i < active_buffs_.size(); i++)
    {
        if(active_buffs_[i].get_bufftype() == BuffType::Speed)
        {
            bonus += active_buffs_[i].get_value();
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


void Character::get_spell_list() const
{
    for (size_t i = 0; i < spells_.size(); i++)
    {
        cout << i << ": " <<spells_[i]->get_name() << endl;
    }
}

void Character::add_buff(Buff buff) {active_buffs_.push_back(buff);}
void Character::add_debuff(Buff debuff) {active_buffs_.push_back(debuff);}