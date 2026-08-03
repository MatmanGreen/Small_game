#include <iostream>
#include "c.h"
#include "factory.h"
#include "utility.h"

#include "raylib.h"

using namespace std;


int main()
{

    Character C("M");

    vector<Enemy> monsters = create_monsters();
}