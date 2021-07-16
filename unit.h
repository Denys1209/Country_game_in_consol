#pragma once
#include <string>
class unit
{
private:
	int maintenance;
	int price;
	int power;
	std::string name;
public:
	unit(int maintanance, int price, int power, std::string name);
	int get_price() const;
	int get_maintenance() const;
	int get_power() const;
	std::string get_name() const;
	void print_opis() const;
};

