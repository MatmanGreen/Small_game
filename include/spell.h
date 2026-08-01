#ifndef SPELL_H
#define SPELL_H

#include <string>

class Spell
{
    private:
        std::string name_;
        int dmg_;
        int cost_;
        //int chance_;
    public:
        Spell(std::string name, int dmg, int cost);

        std::string get_name() const;
        int get_dmg() const;
        int get_cost() const;
};


#endif