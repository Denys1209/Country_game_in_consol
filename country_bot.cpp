#include "country_bot.h"
#include "setting.h" 
void country_bot::update_game_bot()
{
	
	if (this->average_support < 55) 
	{
		this->set_tax(this->tax - 1);
	}
	else
	{
		this->set_tax(this->tax + 1);
	}
	if (this->income < 1000) 
	{
		this->sell_unit(ALL_UNIT[rand() % HOW_MANY_UNIT], 3);
	}
	fabric& fab = ALL_FABRIC[rand() % HOW_MUCH_FABRIC];
	if (fab.get_cost() < this->money) {
		this->build_fabric(fab);
	}
	fabric_consumes_resources& fab_con_res = ALL_FABRIC_CONSUMES_RESOURCES[rand() % HOW_MUCH_FABRIC_CONSUMES_RESOURCES];
	if (all_resurs_income[fab_con_res.get_name_resurs()] >= this->all_resurs_income[fab_con_res.get_name_resurs()] && fab_con_res.get_cost() < this->money)
	{
		this->build_fabric_consumes_resources(fab_con_res);
	}
	if (this->income > 10000) 
	{
		this->buy_unit(ALL_UNIT[rand() % HOW_MANY_UNIT], 5);
	}
}
country_bot::country_bot(std::string name, int all_person) : country(name, all_person){}