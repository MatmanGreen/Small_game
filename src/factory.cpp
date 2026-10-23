#include "factory.h"
#include "artwork.h"

std::vector<Enemy> create_monsters()
{
    std::vector<Enemy> monsters;
    monsters.reserve(3);

    monsters.emplace_back(
        "A nice Devil", Artwork::DEVIL,
        40, 10, 30, 6, 2, 5
    );

    monsters.emplace_back(
        "Endboss", Artwork::EARTHDRAGON,
        1000, 999, 999, 999, 999, 999, 99
    );

    monsters.emplace_back(
        "Goofy Dragon", Artwork::GOOFYDRAGON,
        1, 1, 1, 1, 1, 1, 1
    );

    return monsters;
}

//std::vector<Buff> all_buffs

std::vector<std::unique_ptr<Spell>> create_spells()
{
        std::vector<std::unique_ptr<Spell>> spells;

        spells.push_back(std::make_unique<DmgSpell>("Fireball", 15, 5, 1.0f));
        spells.push_back(std::make_unique<DmgSpell>("Icicle", 20, 10, 1.0f));
        spells.push_back(std::make_unique<HealSpell>("Light Heal", 10, 20, 1.0f));
        //spells.push_back(std::make_unique<BuffSpell>("Second Brain", 10, 20, 1.0, buff));
        return spells;
}

std::vector<Potion> create_potions()
{
        return
        {
                Potion ("Small Health Potion", 5, 10, PotionType::Hp),
                Potion ("Small Magika Potion", 5, 10, PotionType::Mp),
                Potion ("Small Stamina Potion", 5, 10, PotionType::Sp),
        };
}