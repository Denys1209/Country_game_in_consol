#pragma once
#include <iostream>
#include <string>
#include <map>
#include <list>

#include "person.h"
#include "fabric.h"
#include "public_buildings.h"
#include "unit.h"
class country
{
protected:
	std::string name;
	std::string news;
	int all_person;
	int tax;
	int money;
	int income;
	std::map<std::string, int> all_resurs_income;
	std::map<std::string, int> all_welfare_your_population;
	std::map<std::string, int> all_welfare_how_many_person;
	std::map<std::string, int> benefits_for_the_population;
	std::map<std::string, int> army;
	int average_support = 0;
	int costs_army;
	std::list<person> population;
	int power = 0;

public:
	country(std::string name, int all_person);
	void update();
	void build_fabric(const fabric &build);
	void build_fabric_consumes_resources(const fabric_consumes_resources &build);
	void build_public_buildings(const public_buildings &build);
	void post_riot_consequences_calculation();
	void revolution();
	void set_money(int money);
	int get_money()const;
	void set_news(std::string);
	void set_tax(int tax);
	void buy_unit(const unit &un, int count);
	void sell_unit(const unit& un, int count);
	int get_power() const { return this->power; }
	int get_population() const { return this->all_person; }
	int get_how_many_this_resources_produce(const std::string& resources) { return this->all_resurs_income[resources]; }
	int get_how_many_this_unit(const std::string& unit) { return this->army[unit]; }
	std::string get_name() const;
	void seizure_of_the_country(country *coutry);
	void set_power(int power) { this->power = power; }

};

