#pragma once
#include "country.h"
class country_bot : public country
{
private:
	bool die = false;
public:
	void update_game_bot();
	country_bot(std::string name, int all_person);
};

