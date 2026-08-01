#ifndef C_H
#define C_H

#include <string>
#include <vector>
#include "spell.h"

class Chars
{
    private:
        std::string name_;
        std::vector<Spell> spell_list_char_;

        int hp_;
        int mp_;
        int sp_;

        int str_;
        int int_;
        int dex_;
        
        int speed_;

    public:
        Chars(std::string name,
            int hp = 100,
            int mp = 50,
            int sp = 50,
            int str_stat = 5,
            int int_stat = 5,
            int dex_stat = 5,
            int speed = 5);
        
        std::string get_name() const;

        int get_hp() const;
        int get_mp() const;
        int get_sp() const;
        int get_speed() const;

        void set_hp(int hp);
        void set_mp(int mp);
        void set_sp(int sp);

        void reduce_hp(int hp);
        void reduce_mp(int mp);
        void reduce_sp(int sp);

        void print_stats();

        int spell_known(std::string name);
        int spell_list_size() const;
        void print_spell_list() const;
        void add_spell(Spell& spell);
        const Spell& get_spell(int index) const;

        // STILL HAVE TO ADD THE ABILITY CLASS AND THE ABILITY VECTOR
        //void get_ability_list() const;
        //int ability_known(std::string name);
        //void add_ability(Ability& ability);
        //const Ability& get_ability(int index) const;
        
        // STILL HAVE TO ADD THE ITEM CLASS AND THE ITEM VECTOR
        //void get_item_list() const;
        //void add_item(Item& item);
        //const Item& get_item(int index) const;

        
        
};


#endif