#include "item.h"
#include "c.h"
#include <iostream>
using namespace std;

Item::Item(int value, int amount): value_(value), amount_(amount) {}

int Item::get_value() const{return value_;}
int Item::get_amount() const{return amount_;}

void Item::set_value(int value){value_ = value;}
void Item::set_amount(int amount){amount_ = amount;}

Potion::Potion(int value, int amount, int add, PotionType type): Item(value, amount), add_(add), type_(type) {}
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