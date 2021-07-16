#pragma once
#include <string>
#include <iostream>

class buildings
{
private:
	int cost;
	std::string name;
public:
	buildings(int cost, std::string name);
	std::string get_name() const;
	int get_cost() const;
};

