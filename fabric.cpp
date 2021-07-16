#include "fabric.h"
#include <string>
fabric::fabric(int income, std::string name_resurs, std::string name, int cost) : buildings(cost, name)
{
	this->income = income;
	this->name_resurs = name_resurs;

	
}
int fabric::get_income() const
{
	return this->income;
}
std::string fabric::get_name_resurs() const
{
	return this->name_resurs;
}
void fabric::set_income(int income)
{
	this->income = income;
}
void fabric::set_name_resurs(std::string name_resurs)
{
	this->name_resurs = name_resurs;
}
void fabric::set_name(std::string name)
{
	this->name = name;
}
fabric_consumes_resources::fabric_consumes_resources(int income, std::string name_resurs, std::string name, std::string producing_resource, int how_many_resurs_consume, int cost) : fabric(income, name_resurs, name, cost)
{
	this->producing_resource = producing_resource;
	this->how_many_resurs_consume = how_many_resurs_consume;
}
std::string fabric_consumes_resources::get_producing_resource() const  { return this->producing_resource; }
int fabric_consumes_resources::get_how_many_resurs_consume() const { return this->how_many_resurs_consume; }

