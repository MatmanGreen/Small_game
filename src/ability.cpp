#include "ability.h"

Ability::Ability(std::string name, int value, int cost): name_(name), value_(value), cost_(cost) {}
std::string Ability::get_name() const{return name_;}
int Ability::get_value() const{return value_;} 
int Ability::get_cost() const{return cost_;}