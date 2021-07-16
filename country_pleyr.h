#pragma once
#include "country.h"
#include "country_bot.h"
#include <vector>
class country_pleyr : public country
{
public:
	country_pleyr(std::string name, int population);
	void menu(std::vector<country_bot>& ALL_COUNTRY);
	void menu_tax();
	void menu_fabric();
	void menu_warehouse();
	void menu_welfare();
	void menu_income();
	void menu_benefits_for_the_population();
	void menu_army();
	void menu_hired_troops();
	void menu_disband_units();
	void menu_byild_public_buildings();
	void menu_byild_fabric_consumes_resources();
	void menu_byild_fabric();
	void menu_what_the_army_is_made_of();
	void menu_news();
	void world_menu(std::vector<country_bot>& ALL_COUNTRY);
	void end_game(std::string why);
};

