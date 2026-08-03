#include "enemy.h"

#include <iostream>
#include <utility>
using namespace std;


Enemy::Enemy(
    string name,
    string_view artwork,
    int hp,
    int mp,
    int sp,
    int str_stat,
    int int_stat,
    int dex_stat,
    int speed
)
    : Character(
          std::move(name),
          hp,
          mp,
          sp,
          str_stat,
          int_stat,
          dex_stat,
          speed
      ),
      artwork_(artwork)
{
}

void Enemy::print_artwork() const
{
    
    std::cout << artwork_ << '\n';
    cout << get_name() << " HP: " << get_hp() << endl;
}
