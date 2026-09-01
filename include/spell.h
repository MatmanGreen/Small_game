#ifndef SPELL_H
#define SPELL_H

class Character;
class Enemy;
#include <string>
#include "utility.h"

class Buff
{
    private:
        BuffType type_;
        int value_;
        int turns_left_;
    public:
        Buff(BuffType type, int value, int turns_left);

        BuffType get_bufftype() const;
        int get_value() const;
        int get_turns_left() const;

        bool is_active();
        void tick();
};

class Spell
{
    protected:
        std::string name_;
        std::string cast_text_;
        std::string description_;
        int value_;
        int cost_;
        float chance_;
    public:
        Spell(std::string name, 
            int value, 
            int cost, 
            float chance
            );

        std::string get_name() const;
        int get_value() const;
        int get_cost() const;
        float get_chance() const;
        virtual void action(Character& caster, Enemy& target) = 0;
};

class DmgSpell : public Spell
{
    public:
        DmgSpell(
            std::string name,
            //std::string text_
            int value,
            int cost,
            float chance
        );

        virtual void action(Character& caster, Enemy& target) override;
};

class HealSpell : public Spell
{
    public:
        HealSpell(
            std::string name,
            //std::string text_
            int value,
            int cost,
            float chance
        );

        virtual void action(Character& caster, Enemy& target) override;
};

class BuffSpell : public Spell
{
    private:
        Buff buff_;
    public:
        BuffSpell(
            std::string name,
            int value,
            int cost,
            float chance,
            Buff buff
        );

        int get_duration() const;
        Buff& get_buff() const;
        void action(Character& caster, Enemy& target);
};

class DebuffSpell : public Spell
{
    private:
        Buff debuff_;
    public:
        DebuffSpell(
            std::string name,
            int value,
            int cost,
            float chance,
            Buff debuff
        );

        int get_duration() const;
        Buff& get_debuff() const;
        void action(Character& caster, Enemy& target);        
};

#endif