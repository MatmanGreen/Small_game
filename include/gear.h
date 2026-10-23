#ifndef GEAR_H
#define GEAR_H

#include <string>
#include "utility.h"

class Gear
{
    protected:
        const std::string name_;
        const int value_;
        const BuffType buff1_;
        const BuffType buff2_;
        GearSlot slot_;
    public:
        Gear(std::string name, int value);
        Gear(std::string name, int value, BuffType buff1);
        Gear(std::string name, int value, BuffType buff1, BuffType buff2);

        std::string get_name() const;
        //int get_value() const;
        BuffType get_buff1() const;
        BuffType get_buff2() const;

        void equip(GearSlot slot);
        GearSlot get_slot() const;

};

class Sword : public Gear
{
    public:
        int get_dmg() const;
};

class Armor : public Gear
{
    public:
        int get_armor() const;
};

class Ring : public Gear
{
    private:
        BuffType buff3_;
    public:
        BuffType get_buff3() const;
};

class Bracelet : public Gear
{
    private:
        BuffType buff3_;
    public:
        BuffType get_buff3() const;
};

#endif