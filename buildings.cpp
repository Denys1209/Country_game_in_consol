#include "buildings.h"
#include <string>
buildings::buildings(int cost, std::string name)
{
	this->cost = cost;
	this->name = name;
}
std::string buildings::get_name() const
{
	return this->name;
}
int buildings::get_cost() const
{
	return this->cost;
}

