#include <iostream>
#include "c.h"
#include "factory.h"
#include "utility.h"

#include "raylib.h"

using namespace std;


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
    cout << Util::SPELLTYPES << endl;
    cin >> spell_type;
    switch (spell_type)
    {
        case 1:
        {
            if(caster.get_dmg_list_size() >= 0)
            {
                cout << "No damage spells known" << endl;
                break;
            }
            cout << "Which spell do u wanna cast: ";
            caster.get_dmg_spell_list();
            cin >> index;

            if(index < 1 || index > caster.get_dmg_list_size())
                break;

            DmgSpell spell = caster.get_dmg_spell(index);
            caster.reduce_mp(spell.get_cost());
            target.reduce_hp(spell.get_value()+caster.get_int_stat());
        }
            break;

        case 2:
        {
            if(caster.get_heal_list_size() >= 0)
            {
                cout << "No healing spells known" << endl;
                break;
            }
            cout << "Which spell do u wanna cast: ";
            caster.get_heal_spell_list();
            cin >> index;

            if(index < 1 || index > caster.get_heal_list_size())
                break;

            HealSpell spell = caster.get_heal_spell(index);
            caster.reduce_mp(spell.get_cost());
            caster.add_hp(spell.get_value()+int(caster.get_int_stat()*0.25));
        }
            break;
        
        case 3:
        {
            if(caster.get_buff_list_size() >= 0)
            {
                cout << "No buff spells known" << endl;
                break;
            }
            cout << "Which spell do u wanna cast: ";
            caster.get_buff_spell_list();
            cin >> index;

            if(index < 1 || index > caster.get_buff_list_size())
                break;

            BuffSpell spell = caster.get_buff_spell(index);
            caster.reduce_mp(spell.get_cost());
            caster.add_buff(spell.get)
        }
            break;
    }
}

void action(Character& attacker, Enemy& target)
{
    int input = 0;
    cout << "What do you want to do?" << endl;
    cout << Util::ACTIONS << endl;
    cin>> input;

    switch (input)
    {
        case 1:
            attack(attacker, target);
            break;
        case 3:
            
            
            
    }
}

int main()
{

    Character C("M");

    vector<Enemy> monsters = create_monsters();
}