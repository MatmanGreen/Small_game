#ifndef ENEMY_H
#define ENEMY_H

#include "c.h"

class Enemy : public Character
{
    private:
        std::string_view artwork_;
    public:
        Enemy(
        std::string name,
        std::string_view artwork,
        int hp = 100,
        int mp = 50,
        int sp = 50,
        int str_stat = 5,
        int int_stat = 5,
        int dex_stat = 5,
        int speed = 5
    );

    void print_artwork() const;
};

#endif