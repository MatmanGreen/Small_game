#ifndef ITEM_H
#define ITEM_H

#include "utility.h"
#include <vector>

class Character;

class Item
{
    private:
        int value_;
        int amount_;
    public:
        Item(int value, int amount);
        int get_value() const;
        int get_amount() const;

        void set_value(int value);
        void set_amount(int amount);
};

class Potion : public Item
{
    private:
        int add_;
        PotionType type_;
    public:
        Potion(int value, int amount, int add, PotionType type);
        void consum(Character& consumer);
};

#endif