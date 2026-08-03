#ifndef SPELL_H
#define SPELL_H

class Character;
class Enemy;
#include <string>

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
            int dmg, 
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
        std::string type_;
    public:
        BuffSpell(
            std::string name,
            int value,
            std::string type,
            int cost,
            float chance
        );

        virtual void action(Character& caster, Enemy& target) override;

};

class DebuffSpell : public Spell
{
    private:
        std::string type_;
    public:
        DebuffSpell(
            std::string name,
            int value,
            std::string type,
            int cost,
            float chance
        );

        virtual void action(Character& caster, Enemy& target) override;

};
#endif