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
    cout << get_name() << " has " << get_hp() << " hp" << endl;
}

string_view Enemy::get_artwork() const {return artwork_;}

ostream& operator<<(ostream& stream, Enemy& enemy)
{
    stream << enemy.get_artwork() << endl 
    << enemy.get_name() << " has " << enemy.get_hp() << " hp";
    return stream;
}