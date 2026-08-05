#include <iostream>
#include "c.h"
#include "factory.h"

#include "raylib.h"

using namespace std;

void clear()
{
    cout << "\033[2J\033[H";
}

inline string char_stats(Character& character)
{
    return character.get_name() + ":\n" + 
    "[hp] " + to_string(character.get_hp()) + "\n" + 
    "[mp] " + to_string(character.get_mp()) + "\n" +
    "[sp] " + to_string(character.get_sp()) + "\n";
}

void attack(Character& attacker, Enemy& target)
{
    cout << "You hit the Enemy for: " << attacker.get_str_stat() << endl;
    target.reduce_hp(attacker.get_str_stat());
}

void cast_spell(Character& caster, Enemy& target)
{
    int index = 0;
    int spell_type = 0;

    cout << "Which type of spell do u wanna cast: " << endl;
    cout << Util::SPELLTYPES;
    cin >> spell_type;
    switch (spell_type)
    {
        case 1:
        {
            if(caster.get_dmg_list_size() < 0)
            {
                cout << "No damage spells known" << endl;
                break;
            }
            caster.get_dmg_spell_list();
            cout << "Which spell do u wanna cast: ";
            cin >> index;

            if(index < 0 || index > caster.get_dmg_list_size())
                break;

            DmgSpell spell = caster.get_dmg_spell(index);
            caster.reduce_mp(spell.get_cost());
            target.reduce_hp(spell.get_value()+caster.get_int_stat());
            cout << "u casted a " << spell.get_name() << endl; 
        }
            break;

        case 2:
        {
            if(caster.get_heal_list_size() < 0)
            {
                cout << "No healing spells known" << endl;
                break;
            }
            cout << "Which spell do u wanna cast: ";
            caster.get_heal_spell_list();
            cin >> index;

            if(index < 0 || index > caster.get_heal_list_size())
                break;

            HealSpell spell = caster.get_heal_spell(index);
            caster.reduce_mp(spell.get_cost());
            caster.set_hp(caster.get_hp() + spell.get_value()+int(caster.get_int_stat()*0.25));
        }
            break;
        
        case 3:
        {
            if(caster.get_buff_list_size() < 0)
            {
                cout << "No buff spells known" << endl;
                break;
            }
            cout << "Which spell do u wanna cast: ";
            caster.get_buff_spell_list();
            cin >> index;

            if(index < 0 || index > caster.get_buff_list_size())
                break;

            BuffSpell spell = caster.get_buff_spell(index);
            caster.reduce_mp(spell.get_cost());
            caster.add_buff(spell.get_bufftype(),spell.get_value(), spell.get_duration());
        }
            break;

        case 4:
        {
            if(caster.get_debuff_list_size() < 0)
            {
                cout << "No debuff spells known" << endl;
                break;
            }
            cout << "Which spell do u wanna cast: ";
            caster.get_debuff_spell_list();
            cin >> index;

            if(index < 0 || index > caster.get_debuff_list_size())
                break;

            DebuffSpell spell = caster.get_debuff_spell(index);
            caster.reduce_mp(spell.get_cost());
            caster.add_debuff(spell.get_debufftype(),spell.get_value(), spell.get_duration());
        }
            break;
        
            default:
                cout << "Index not in range" << endl;
                break;
    }
}

void action(Character& attacker, Enemy& target)
{
    int input = 0;
    cout << "What do you want to do?" << endl;
    cout << Util::ACTIONS;
    cin>> input;

    switch (input)
    {
        case 1:
            attack(attacker, target);
            break;
        case 3:
            cast_spell(attacker, target);
            break;
        
        default:
            cout << "Index not in range" << endl;
            break;
    }
}

void fight(Character& Char, Enemy& enemy)
{
    cout << enemy << endl;
    cout <<  char_stats(Char) << endl;

    while(enemy.get_hp() > 0)
    {
        action(Char, enemy);
        //clear();
        cout << enemy << endl;
        cout <<  char_stats(Char) << endl;
    }

    cout << "U won the fight" << endl;
}

int main()
{
    Character C("M");
    DmgSpell fire_ball("fire ball", 10, 5, 1.0);
    C.add_dmg_spell(fire_ball);
    vector<Enemy> monsters = create_monsters();
    C.get_all_spell_list();

    fight(C, monsters[0]);
}