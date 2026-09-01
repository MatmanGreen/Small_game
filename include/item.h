#ifndef ITEM_H
#define ITEM_H

#include "utility.h"
#include <vector>

class Character;

class Item
{
    private:
        std::string name_;
        int value_;
        int amount_;
    public:
        Item(std::string name, int value);
        std::string get_name() const;
        int get_value() const;

        void set_value(int amount);
};

class Potion : public Item
{
    private:
        int add_;
        PotionType type_;
    public:
        Potion(std::string name, int value, int add, PotionType type);
        void consum(Character& consumer);
};

class Equipment
{
    private:
        std::string name_;
        std::vector<BuffType> buffs_;
        //std::vector<BuffType> debuffs_;
        int dura_;
        int max_dura_;
    public:
        Equipment(std::string name, int dura, int max_dura);
        Equipment(std::string name, std::vector<BuffType> buffs, int dura, int max_dura);
        std::string get_name() const;
        void get_buffs() const;
        int get_dura() const;
        int get_max_dura() const;

        void set_dura(int durability);
};



#endif