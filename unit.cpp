#include "unit.h"


unit::unit(int maintanance, int price, int power, std::string name)
{
	this->maintenance = maintanance;
	this->price = price;
	this->power = power;
	this->name = name;
}
int unit::get_price() const { return this->price; }
int unit::get_power() const { return this->power; }
int unit::get_maintenance() const { return this->maintenance; }
std::string unit::get_name() const { return this->name; }
void unit::print_opis() const { 
	
}

