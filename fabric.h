#pragma once
#include <iostream>
#include <string>
#include "buildings.h"
class fabric : public buildings
{
protected:
	int income;
	std::string name_resurs;
	std::string name;
	int cost;
	
public:
	fabric(int income, std::string name_resurs, std::string name, int cost);
	int get_income() const;
	std::string  get_name_resurs() const ;
	void set_income(int income);
	void set_name_resurs(std::string name_resurs);
	void set_name(std::string name);

	
};
class fabric_consumes_resources :public fabric
{
private:
	std::string producing_resource;
	int how_many_resurs_consume;
public:
	fabric_consumes_resources(int income, std::string name_resurs, std::string name, std::string producing_resource, int how_many_resurs_consume, int cost);
	std::string  get_producing_resource() const;
	int get_how_many_resurs_consume() const;

};

