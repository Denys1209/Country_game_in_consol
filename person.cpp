#include "person.h"
#include <random>
#include "time.h"
#include <string>

person::person() 
{
	
	this->salary = rand() % 1000;
	this->government_support = rand() % 50 + 50;
	this->bunt = 0;
	if (this->salary > 800) 
	{
		this->welfare = "A";
	}
	else if (this->salary > 600)
	{
		this->welfare = "B";
	}
	else if (this->salary > 400)
	{
		this->welfare = "C";
	}
	else if (this->salary > 200)
	{
		this->welfare = "D";
	}
	else 
	{
		this->welfare = "E";
	}

}
int person::get_salary() const { return this->salary; };
std::string person::get_welfare() const { return this->welfare; };
int person::get_government_support()const { return this->government_support; };
int person::get_living_wage()const
{
	if (this->welfare == "E")
	{
		return 130;
	}
	else if (this->welfare == "D")
	{
		return 300;
	}
	else if (this->welfare == "C")
	{
		return 450;
	}
	else if (this->welfare == "B")
	{
		return 650;
	}
	else if (this->welfare == "A")
	{
		return 750;
	}
};
void person::calculate_government_support(int tax)
{
	if ((this->salary - tax) < this->get_living_wage()) 
	{
		if (this->get_government_support() < 50) { this->bunt += 1; }
		else if (this->bunt > 0) { this->bunt -= 1; }
		this->government_support  -= (this->get_living_wage() - (this->salary - tax)) / 100;
		return;
	}
	else 
	{
		this->government_support += 1;
		if (this->government_support > 100) 
		{
			this->government_support-=1;
		}
	}

}
void person::set_government_support(int new_government_support) 
{
	this->government_support = new_government_support;
}
int person::get_bunt() const { return this->bunt; }
void person::set_bunt(int bunt) { this->bunt = bunt; }