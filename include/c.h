#ifndef C_H
#define C_H

#pragma once

#include <string>
#include <memory>

#include "spell.h"
#include "utility.h"
#include "ability.h"

class Character
{
    private:
        std::string name_;

        int hp_;
        int mp_;
        int sp_;

        int max_hp_;
        int max_mp_;
        int max_sp_;

        int str_;
        int int_;
        int dex_;
        
        int speed_;
        int max_weight_;
        int weight_;

        std::vector<Ability> skill_list_;


        std::vector<std::unique_ptr<Spell>> spells_;

        std::vector<Buff> active_buffs_;
        std::vector<Buff> active_debuffs_;

    public:
        Character(std::string name,
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

        void set_max_hp(int hp);
        void set_max_mp(int mp);
        void set_max_sp(int sp);

        int get_str_stat() const;
        int get_int_stat() const;
        int get_dex_stat() const;
        int get_speed() const;
        int get_max_weight() const;
        int get_weight() const;

        void set_hp(int hp);
        void set_mp(int mp);
        void set_sp(int sp);

        /*
        void add_hp(int hp);
        void add_mp(int mp);
        void add_sp(int sp);
        */

        void reduce_hp(int hp);
        void reduce_mp(int mp);
        void reduce_sp(int sp);

        void print_stats();

        
        void get_skill_list() const;
        void add_skill(Ability& skill);
        int get_skill_list_size();
        const Ability& get_skill(int index);

        void get_spell_list() const;
        //void add_spell(std::unique_ptr spell)

        void add_buff(Buff buff);
        void add_debuff(Buff debuff);

        //int spell_list_size() const;
        //void print_spell_list() const;

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