#pragma once
#include "buildings.h"
#include <string> 
class public_buildings : public buildings
{
private:
	int cost;
	std::string name;
	int add_community_support;
	std::string which_class_brings_more_support;


public:
	public_buildings(std::string name, int cost, int add_community_support, std::string which_class_brings_more_support);
	int get_add_community_support() const;
	std::string get_which_class_brings_more_support() const;
};

