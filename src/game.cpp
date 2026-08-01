#include <iostream>
#include "c.h"
#include "factory.h"
#include "utility.h"

using namespace std;

#ifdef _WIN32
#include <windows.h>
#endif


void clear()
{
    cout << "\033[2J\033[H";
}

bool cast_spell(Chars& chara, string spell)
{
    int index = chara.spell_known(spell);
    if(index < 0 || index > chara.spell_list_size())
        return false;
    else
    {
        if(chara.get_spell(index).get_cost() <= chara.get_mp())
        {
            chara.reduce_mp(chara.get_spell(index).get_cost());
            return true;
        }
        else
        {
            cout << "not enough mana" << endl;
            return false;
        }
    }
}

bool inti_fight(Chars& chara, Enemy& enemy)
{
    int input = 0;
    string spell;

    cout << enemy.get_name() << " has appeared" << endl;
    enemy.print_artwork();

    while(enemy.get_hp() > 0)
    {
        cout << "What do u want to do?:" << endl;
        cout << Util::ACTIONS << endl;
        cin >> input;
        clear();

        switch (input)
        {
            case 3:
                spell.clear();

                while (spell != "x")
                {
                    chara.print_spell_list();
                    cout << "Which spell do you want to cast? (x to exit)\n";
                    getline(cin >> ws, spell);

                    if (spell == "x")
                        break;

                    int index = chara.spell_known(spell);

                    if(cast_spell(chara, spell))
                        enemy.reduce_hp(chara.get_spell(index).get_dmg());
                }
                break;
                
            default:
                break;
        }
    }
    return true;
}

int main()
{
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    Chars C("M");
    Spell fire_ball("fire ball", 5, 10);
    C.add_spell(fire_ball);
    vector<Enemy> monsters = create_monsters();

    inti_fight(C, monsters[1]);
}