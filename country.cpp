#include "country.h"
#include <string>
#include <stdlib.h>
#include "setting.h"
#include <sstream>
#include "person.h"
#include <algorithm>
country::country(std::string name, int population)
{
	this->name = name;
	this->all_person = population;
	this->tax = 10;
	this->money =1000;
	this->income = int(this->all_person * 10) /100* this->tax;
	for (int i = 0; i < HOW_MUCH_RESURS; i++) 
	{
		this->all_resurs_income[ALL_NAME_RESURS[i]] = 0;
	}
	for (int i = 0; i < this->all_person; i++) 
	{
		this->population.push_back(person());
	}
	for (person &i : this->population)
	{
		this->all_welfare_your_population[i.get_welfare()] += 1;
	}
	for (int i = 0; i < ALL_WELFARE; ++i) 
	{
		this->all_welfare_your_population[ALL_NAME_WALFABE[i]] = 0;
		this->all_welfare_how_many_person[ALL_NAME_WALFABE[i]] = 0;
		this->benefits_for_the_population[ALL_NAME_WALFABE[i]] = 0;
	}
	for (const unit& i : ALL_UNIT) 
	{
		this->army[i.get_name()] = rand()%9+1;
	}
	this->update();
}
void country::update() 
{
	
	this->average_support = 0;
	this->income = 0;
	this->costs_army = 0;
	this->power = 0;
	this->post_riot_consequences_calculation();
	for (const std::string& i : ALL_NAME_WALFABE) 
	{
		this->all_welfare_your_population[i] = 0;
	}
	for (person& i : this->population)
	{
		this->all_welfare_your_population[i.get_welfare()] += 1;
	}
	for (auto &i : ALL_NAME_WALFABE)
	{
		this->all_welfare_your_population[i] = 0;
		this->all_welfare_how_many_person[i] = 0;
	}
	for (person &i : this->population) 
	{
		int tax_income = i.get_salary() / 100 * (this->tax-i.get_bunt() - this->benefits_for_the_population[i.get_welfare()]);
		this->income += tax_income;
		i.calculate_government_support(tax_income);
		this->average_support += i.get_government_support();
		this->all_welfare_your_population[i.get_welfare()] += i.get_government_support();
		this->all_welfare_how_many_person[i.get_welfare()] +=1;

	}
	
	for (int i = 0; i < HOW_MUCH_RESURS; i++)
	{

		this->income += cost_all_resurs[ALL_NAME_RESURS[i]] * this->all_resurs_income[ALL_NAME_RESURS[i]];
	}
	for (auto& i : ALL_NAME_WALFABE)
	{
		this->all_welfare_your_population[i] /= all_welfare_how_many_person[i];
	}
	for (const unit& i : ALL_UNIT)
	{
		this->costs_army += this->army[i.get_name()] * i.get_maintenance();
		this->power += this->army[i.get_name()] * i.get_power();
	}
	
	this->income -= costs_army;
	this->money += this->income;
	
	if (this->average_support < 25)
	{
		this->revolution();
	}
	for (int i = this->all_person; i < this->all_person + int(this->all_person / 100); i++)
	{
		this->population.push_back(person());
	}
	if (this->income < 1000) 
	{
		std::for_each(this->population.begin(), this->population.end(), [&effor = income](person &i)
		{
			i.set_government_support((i.get_government_support() + effor / 1000));
		});
	}
	if (this->money < 1000)
	{
		std::for_each(this->population.begin(), this->population.end(), [&effor = money](person& i)
		{
			i.set_government_support((i.get_government_support() + 1));
		});
	}
	
	this->all_person = this->population.size();
	this->average_support = this->average_support / this->all_person;
	if(this->average_support > 100) 
	{
		this->average_support = 100;
	}

}
void country::build_public_buildings(const public_buildings &build)
{
	this->money -= build.get_cost();
	std::for_each(this->population.begin(), this->population.end(), [&effor = build](person& i)
	{
		if (i.get_welfare() == effor.get_which_class_brings_more_support())
		{
			i.set_government_support(i.get_government_support() + effor.get_add_community_support() * 2);
		}
		else
		{
			i.set_government_support(i.get_government_support() + effor.get_add_community_support());
		}
	});

}
void country::build_fabric_consumes_resources(const fabric_consumes_resources &build) 
{
	this->money -= build.get_cost();
	this->all_resurs_income[build.get_producing_resource()] += build.get_income();
	this->all_resurs_income[build.get_name_resurs()] -= build.get_how_many_resurs_consume();
}
void country::build_fabric(const fabric &build)
{
	this->money -= build.get_cost();
	this->all_resurs_income[build.get_name_resurs()] += build.get_income();
}

void country::post_riot_consequences_calculation()
{
	if (this->money < -1000) 
	{
		
	}
	if (this->all_welfare_your_population[ALL_NAME_WALFABE[0]] < 50) 
	{
		if (this->all_resurs_income[ALL_NAME_RESURS[rand() % HOW_MUCH_RESURS]] != 0) 
		{
			this->all_resurs_income[ALL_NAME_RESURS[rand() % HOW_MUCH_RESURS]] -= 1;
		}
	}
}
void country::revolution() 
{
	if (this->all_person < 500) 
	{
		this->name = "the revolution " + this->name;
	}
	else 
	{
		this->all_person = int(this->all_person / 2);
		auto it = std::begin(population);
		std::advance(it, this->all_person);
		this->population.erase(it, this->population.end());
		std::for_each(this->population.begin(), this->population.end(), [](person& i)
		{
			i.set_government_support(i.get_government_support() + 50);
		});
		for (int i = 0; i < HOW_MUCH_RESURS; i++)
		{
			if (this->all_resurs_income[ALL_NAME_RESURS[i]] != 0) {
				this->all_resurs_income[ALL_NAME_RESURS[i]] = int(this->all_resurs_income[ALL_NAME_RESURS[i]]/2);
			}
		}
		for (const std::string& i : ALL_NAME_UNIT) 
		{
			this->army[i] = (this->army[i] / 2);
		}
		
	}
}
void country::set_money(int money)
{
	this->money = money;
}
int country::get_money()const 
{
	return this->money;
}
void country::set_news(std::string news) 
{
	this->news = news;
}

void country::set_tax(int tax)
{
	if (tax > 100)
	{
		this->tax = tax;
	}
	else if (tax < 0)
	{
		this->tax = 0;
	}
}

void country::buy_unit(const unit& un, int count)
{
	this->army[un.get_name()] += count;
	this->money -= count * un.get_price();
	this->power += count * un.get_power();
}
void country::sell_unit(const unit& un, int count) 
{
	this->army[un.get_name()] -= count;
	if (this->army[un.get_name()] < 0)
	{
		this->power -= (count+ this->army[un.get_name()]) * un.get_power();
		this->army[un.get_name()] = 0;

	}
	else {
		this->power -= count * un.get_power();
	}
}
std::string country::get_name() const { return this->name; }

void country::seizure_of_the_country(country* coutry)
{
	this->power -= coutry->get_power();
	for (int i = 0; i < coutry->get_population(); ++i) 
	{
		this->population.push_back(person());
	}
	for (auto &i:ALL_NAME_RESURS)
	{
		this->all_resurs_income[i] += coutry->get_how_many_this_resources_produce(i)/2;
	}
	for (auto& i : ALL_NAME_UNIT) 
	{
		this->army[i] -= coutry->get_how_many_this_unit(i);
		if (this->army[i] < 0) 
		{
			this->army[i] = 0;
		}
	}
	this->money += coutry->get_money() / 2;
	
}
