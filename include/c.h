#ifndef C_H
#define C_H

#include <string>
#include <vector>
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

        std::vector<Ability> skill_list_;

        std::vector<DmgSpell> dmg_spells_;
        std::vector<HealSpell> heal_spells_;
        std::vector<BuffSpell> buff_spells_;
        std::vector<DebuffSpell> debuff_spells_;

        std::vector<ActiveBuff> active_buffs_;
        std::vector<ActiveDebuff> active_debuffs_;

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


        void get_dmg_spell_list() const;
        void add_dmg_spell(DmgSpell& spell);
        int get_dmg_list_size();
        const DmgSpell& get_dmg_spell(int index) const;

        void get_heal_spell_list() const;
        void add_heal_spell(HealSpell& spell);
        int get_heal_list_size();
        const HealSpell& get_heal_spell(int index) const;

        void get_buff_spell_list() const;
        void add_buff_spell(BuffSpell& spell);
        int get_buff_list_size();
        const BuffSpell& get_buff_spell(int index) const;

        void get_debuff_spell_list() const;
        void add_debuff_spell(DebuffSpell& spell);
        int get_debuff_list_size();
        const DebuffSpell& get_debuff_spell(int index) const;

        void get_all_spell_list() const;

        void add_buff(BuffType type, int value, int duration);
        void add_debuff(BuffType type, int value, int duration);

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