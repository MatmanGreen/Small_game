#include "factory.h"
#include "artwork.h"

std::vector<Enemy> create_monsters()
{
    return
    {
        Enemy ("A nice Devil",
                Artwork::DEVIL,
                40, 10, 30,
                6, 2, 5
                ),
        Enemy ("Endboss",
                Artwork::EARTHDRAGON,
                1000, 999, 999,
                999, 999, 999, 99
                ),
        Enemy ("Goofy Dragon",
                Artwork::GOOFYDRAGON,
                1, 1, 1,
                1, 1, 1, 1
            ),
    };
}