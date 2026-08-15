#ifndef ABILITY_H
#define ABILITY_H

#include <vector>
#include <string>

class Ability
{
    private:
        std::string name_;
        int value_;
        int cost_;
    public:
        Ability(std::string name, int value, int cost);
        std::string get_name() const;
        int get_value() const;
        int get_cost() const;
};

#endif