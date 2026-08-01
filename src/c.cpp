#include "c.h"
#include <iostream>
using namespace std;


Chars::Chars(std::string name,
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

string Chars::get_name() const {return name_;}

int Chars::get_hp() const {return hp_;}
int Chars::get_mp() const {return mp_;}
int Chars::get_sp() const {return sp_;}

int Chars::get_speed() const {return speed_;}

void Chars::set_hp(int hp) {hp_ = hp;}
void Chars::set_mp(int mp) {mp_ = mp;}
void Chars::set_sp(int sp) {sp_ = sp;}

void Chars::reduce_hp(int hp) {hp_ -= hp;}
void Chars::reduce_mp(int mp) {mp_ -= mp;}
void Chars::reduce_sp(int sp) {sp_ -= sp;}

void Chars::print_stats()
{
    cout << name_ << " (hp:" << hp_ <<", mp:" << mp_ << ", sp:" << sp_ << ")"; 
}

int Chars::spell_known(std::string name)
{
    for(size_t i = 0; i < spell_list_char_.size(); i++)
    {
        if(spell_list_char_[i].get_name() == name)
            return i;
    }
    return -1;
}
int Chars::spell_list_size() const
{
    return spell_list_char_.size();
}
void Chars::print_spell_list() const
{
    for(size_t i = 0; i < spell_list_char_.size(); i++)
    {
        cout << i+1 << ": " << spell_list_char_[i].get_name() << endl;
    }
}
void Chars::add_spell(Spell& spell)
{
    spell_list_char_.push_back(spell);
}
const Spell& Chars::get_spell(int index) const {return spell_list_char_.at(index);}