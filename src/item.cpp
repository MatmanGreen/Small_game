#include "item.h"
#include "c.h"
#include <iostream>
using namespace std;

Item::Item(std::string name, int value): name_(name), value_(value) {}

int Item::get_value() const{return value_;}

void Item::set_value(int value){value_ = value;}

Potion::Potion(std::string name, int value, int add, PotionType type): Item(name, value), add_(add), type_(type) {}
void Potion::consum(Character& consumer)
{
    switch (type_)
    {
        case PotionType::Hp:
            consumer.set_hp(consumer.get_hp()+add_);
            break;
        case PotionType::Mp:
            consumer.set_mp(consumer.get_mp()+add_);
            break;
        case PotionType::Sp:
            consumer.set_sp(consumer.get_sp()+add_);
            break;
        default:
            cout << "smth went wrong";
            break;
    }
}

Equipment::Equipment(string name, int dura, int max_dura): name_(name), dura_(dura), max_dura_(max_dura) {}
Equipment::Equipment(string name, vector<BuffType> buffs, int dura, int max_dura): name_(name), buffs_(buffs), dura_(dura), max_dura_(max_dura) {}
std::string Equipment::get_name() const {return name_;}
int Equipment::get_dura() const {return dura_;}
int Equipment::get_max_dura() const {return max_dura_;}

void Equipment::set_dura(int durability) {dura_ = durability;}