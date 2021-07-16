#include "public_buildings.h"
#include <string>

public_buildings::public_buildings(std::string name, int cost, int add_community_support, std::string which_class_brings_more_support) : buildings(cost, name)
{
	this->add_community_support = add_community_support;
	this->which_class_brings_more_support = which_class_brings_more_support;
}



int public_buildings::get_add_community_support() const
{
	return this->add_community_support;
}
std::string public_buildings::get_which_class_brings_more_support() const
{
	return this->which_class_brings_more_support;
}
