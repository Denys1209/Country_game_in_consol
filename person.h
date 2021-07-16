#pragma once
#include <string>

#include <string>


class person
{
private:
	int salary;
	std::string welfare;
	int government_support;
	int bunt;
public:
	person();
	int get_salary() const;
	std::string get_welfare() const;
	int get_government_support() const;
	int get_living_wage() const;
	void calculate_government_support(int tax);
	void set_government_support(int new_government_support);
	int get_bunt() const;
	void set_bunt(int bunt);
};

