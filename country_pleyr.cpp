#include "country_pleyr.h"
#include "setting.h"
#include <algorithm> 
#include <vector>
country_pleyr::country_pleyr(std::string name, int population) : country(name, population)
{
}
void country_pleyr::menu(std::vector<country_bot>& ALL_COUNTRY)
{
	while (true) {
		
		system("cls");
		std::string choice;
		std::cout << "money = " << this->money << "    population = " << this->all_person << "   income = " << this->income << "   average support = " << this->average_support<<"   name country = "<<this->name << std::endl;
		std::cout << "1)taxes" << std::endl << "2)next move" << std::endl << "3)warehouse" << std::endl << "4)construction" << std::endl << "5)world market" << std::endl << "6)population" << std::endl <<"7)benefits for the population"<<std::endl<< "8)army"<<std::endl<<"9)news"<<std::endl<<"10)world" << std::endl << "exit)exit" << std::endl;
		std::cin >> choice;
		if (choice == "1")
		{
			this->menu_tax();
		}
		else if (choice == "2")
		{
			break;
		}
		else if (choice == "3")
		{
			this->menu_income();

		}
		else if (choice == "4")
		{
			this->menu_fabric();
		}
		else if (choice == "5")
		{
			this->menu_warehouse();
		}
		else if (choice == "6")
		{
			this->menu_welfare();
		}
		else if (choice == "7")
		{
			this->menu_benefits_for_the_population();
		}
		else if (choice == "8")
		{
			this->menu_army();
		}
		else if (choice == "9") 
		{
			this->menu_news();
		}
		else if (choice == "10")
		{
			this->world_menu(ALL_COUNTRY);
		}
		else if (choice == "exit")
		{
			exit(EXIT_SUCCESS);
		}
	}
	if (this->money < -1000)
	{
		this->end_game("you have no money to maintain armies\nthe army rebelled and smashed you");
	}
	if (this->average_support <= 25)
	{
		this->end_game("the people rebelled and humbled you");
	}

}
void country_pleyr::menu_tax()
{
	system("cls");
	std::cout << "tax = " << this->tax << std::endl;
	std::cout << "change tax" << std::endl;
	std::cin >> this->tax;
	this->set_tax(this->tax);
}

void country_pleyr::menu_fabric()
{
	std::string choice;
	system("cls");
	std::cout << "1)small business" << std::endl << "2)fabric" << std::endl << "3)public buildings" << std::endl;
	std::cout << "exit)exit construction" << std::endl;
	std::cin >> choice;
	system("cls");
	if (choice == "1") {
		this->menu_byild_fabric();
	}
	else if (choice == "2")
	{
		this->menu_byild_fabric_consumes_resources();
	}
	else if (choice == "3")
	{
		this->menu_byild_public_buildings();
	}
}
void country_pleyr::menu_warehouse()
{
	system("cls");
	std::string choice;
	for (int i = 0; i < HOW_MUCH_RESURS; i++)
	{
		std::cout << "Cost " << ALL_NAME_RESURS[i] << " = " << cost_all_resurs[ALL_NAME_RESURS[i]] << std::endl;
	}
	std::cout << "exit)exit build fabric" << std::endl;
	std::cin >> choice;
}
void country_pleyr::menu_welfare() 
{
	std::string choice;
	system("cls");
	for (auto& i : ALL_NAME_WALFABE) {
		std::cout <<i <<" = " << this->all_welfare_your_population[i]<<"\t"<<"how many people = "<< this->all_welfare_how_many_person[i]<< std::endl;
	}
	std::cout << "exit)exit menu" << std::endl;
	std::cin >> choice;
}
void country_pleyr::menu_income() 
{
	std::string choice;
	system("cls");
	for (int i = 0; i < HOW_MUCH_RESURS; i++)
	{
		std::cout << ALL_NAME_RESURS[i] << " : income = " << this->all_resurs_income[ALL_NAME_RESURS[i]] << std::endl;
	}
	std::cout << "1)exit warehouse" << std::endl;
	std::cin >> choice;
}
void country_pleyr::menu_benefits_for_the_population() 
{
	std::string choice;
	int number;
	bool tru;
	while (true) {
		tru = false;
		system("cls");
		std::cout << "exit)exit" << std::endl;
		for (int i = 0; i < ALL_WELFARE; ++i)
		{
			std::cout << ALL_NAME_WALFABE[i] << " = " << benefits_for_the_population[ALL_NAME_WALFABE[i]] << std::endl;
		}
		std::cout << "benefits for whom:";
		std::cin >> choice;
		if (choice == "exit") 
		{
			return;
		}
		std::cout << std::endl;
		std::for_each(std::begin(ALL_NAME_WALFABE), end(ALL_NAME_WALFABE), [&effor = tru, choice](const std::string & i) {
			if (i == choice) 
			{
				effor = true;
			}
		});
		if (tru == true)
		{
			std::cout << "how much should you raise: ";
			std::cin >> number;
			benefits_for_the_population[choice] = number;
		}
	}
}
void country_pleyr::menu_army() 
{
	system("cls");
	std::string choice;
	std::cout << "cost army = " << this->costs_army<<"   power = "<<this->power << std::endl;
	std::cout << "1)hired troops" << std::endl;
	std::cout << "2)disband units" << std::endl;
	std::cout << "3)what the army is made of" << std::endl;
	std::cout << "else)exit menu" << std::endl;
	std::cin >> choice;
	if (choice == "1") {
		this->menu_hired_troops();}
	else if (choice == "2") { this->menu_disband_units(); }
	else if (choice == "3") { this->menu_what_the_army_is_made_of(); }
	else { return; }

}
void country_pleyr::menu_hired_troops() 
{
	
	std::string choice;
	while (true) {
		system("cls");
		std::cout << "your money = " << this->money << std::endl;
		int count = 0;
		std::cout << "e)exit menu" << std::endl;
		std::for_each(begin(ALL_NAME_UNIT), end(ALL_NAME_UNIT), [&count](const std::string& i) {
			count++;
			std::cout << count << ")" << i << std::endl; });
		count = 0;
		std::cin >> choice;
		const char* chr = choice.c_str();
		int number_fabric = chr[0] - '0';
		if (*chr == 'e')
		{
			return;
		}
		if (number_fabric-1 > HOW_MANY_UNIT or number_fabric - 1 < 0)
		{
			std::cout << "pls, enter correct number";
		}
		else 
		{
			std::cout << ALL_UNIT[number_fabric - 1].get_name() << "\n" << "\tprice = " << ALL_UNIT[number_fabric - 1].get_price() << "\n" << "\tpower = " << ALL_UNIT[number_fabric - 1].get_power() << "\tmaintenance = "<<  ALL_UNIT[number_fabric - 1].get_maintenance()<< "\n";
			std::cout << "Do you want buy this units n/y" << std::endl;
			std::cin >> choice;
			while (choice == "y") 
			{
				std::cout << "How many unit do you want to buy" << std::endl;
				std::cin >> count;
				if (ALL_UNIT[number_fabric - 1].get_price() * count < this->money) {
					this->buy_unit(ALL_UNIT[number_fabric - 1], count);
					break;
				}
				else 
				{
					std::cout << "you don't have enough money" << std::endl;
				}
				
			}

		}

	}
}
void country_pleyr::menu_disband_units() 
{
	std::string choice;
	while (true) 
	{
		system("cls");
		unsigned int count = 0;
		std::cout << "e)exit menu" << std::endl;
		std::for_each(begin(ALL_NAME_UNIT), end(ALL_NAME_UNIT), [&count](const std::string& i) {
			count++;
			std::cout << count << ")" << i << std::endl; });
		std::for_each(begin(ALL_NAME_UNIT), end(ALL_NAME_UNIT), [&effor = this->army](const std::string& i) {
			std::cout << i << " = " << effor[i] << std::endl; });
		count = 0;
		std::cin >> choice;
		const char* chr = choice.c_str();
		int number_fabric = chr[0] - '0';
		if (*chr == 'e')
		{
			return;
		}
		if (number_fabric - 1 > HOW_MANY_UNIT or number_fabric - 1 < 0)
		{
			std::cout << "pls, enter correct number";
		}
		else
		{
			std::cout << ALL_UNIT[number_fabric - 1].get_name() << "\n";
			std::cout << "Do you want disband this units n/y" << std::endl;
			std::cin >> choice;
			if (choice == "y")
			{
				
				std::cout << "How many unit do you want to disband" << std::endl;
				std::cin >>count;
				this->sell_unit(ALL_UNIT[number_fabric - 1], count);

			}

		}
	}
}
void country_pleyr::menu_what_the_army_is_made_of()
{
	char i;
	std::for_each(begin(ALL_NAME_UNIT), end(ALL_NAME_UNIT), [&effor = this->army](const std::string& i) {
		std::cout <<i<<" = " << effor[i] <<std::endl; });
	std::cin >> i;
}
void country_pleyr::menu_byild_public_buildings()
{
	std::string choice;
	while (true) {
		system("cls");
		for (int i = 0; i < HOW_MUCH_PUBLIC_BUILDINGS; i++)
		{
			std::cout << i + 1 << ") " << ALL_PUBLIC_BUILDINGS[i].get_name() << std::endl;
		}
		std::cout << "exit)exit construction" << std::endl;
		std::cin >> choice;
		const char* chr = choice.c_str();
		int number_fabric = (chr[0] - '0') - 1;
		if (number_fabric <= HOW_MUCH_PUBLIC_BUILDINGS && number_fabric >= 0) {
			std::cout << ALL_PUBLIC_BUILDINGS[number_fabric].get_name() << std::endl << " cost = " << ALL_PUBLIC_BUILDINGS[number_fabric].get_cost() << std::endl << " add community support = " << ALL_PUBLIC_BUILDINGS[number_fabric].get_add_community_support() << std::endl << "which class brings more support = " << ALL_PUBLIC_BUILDINGS[number_fabric].get_which_class_brings_more_support() << std::endl;
			std::cout << "buy y/n" << std::endl;
			std::cin >> choice;
			if (choice == "y") {
				this->build_public_buildings(ALL_PUBLIC_BUILDINGS[number_fabric]);
			}
		}
		else
		{
			break;
		}
	}
}
void country_pleyr::menu_byild_fabric_consumes_resources()
{
	std::string choice;
	while (true) {
		system("cls");
		for (int i = 0; i < HOW_MUCH_FABRIC_CONSUMES_RESOURCES; i++)
		{
			std::cout << i + 1 << ") " << ALL_FABRIC_CONSUMES_RESOURCES[i].get_name() << std::endl;
		}
		std::cout << "exit)exit construction" << std::endl;
		std::cin >> choice;
		const char* chr = choice.c_str();
		int number_fabric = chr[0] - '0';
		if (number_fabric <= HOW_MUCH_FABRIC_CONSUMES_RESOURCES && number_fabric > 0) {
			std::cout << ALL_FABRIC_CONSUMES_RESOURCES[number_fabric - 1].get_name() << std::endl << " income resurs = " << ALL_FABRIC_CONSUMES_RESOURCES[number_fabric - 1].get_producing_resource() << std::endl << " consumes resource = " << ALL_FABRIC_CONSUMES_RESOURCES[number_fabric - 1].get_name_resurs() << std::endl << " how much resource consumes = " << ALL_FABRIC_CONSUMES_RESOURCES[number_fabric - 1].get_how_many_resurs_consume() << std::endl << " how much resource it produces = " << ALL_FABRIC_CONSUMES_RESOURCES[number_fabric - 1].get_income() << std::endl << " cost = " << ALL_FABRIC_CONSUMES_RESOURCES[number_fabric - 1].get_cost() << std::endl;
			std::cout << "buy y/n" << std::endl;
			std::cin >> choice;
			if (choice == "y") {
				this->build_fabric_consumes_resources(ALL_FABRIC_CONSUMES_RESOURCES[number_fabric - 1]);
			}
		}
		else
		{
			break;
		}
	}

}
void country_pleyr::menu_byild_fabric()
{
	std::string choice;
	while (true) {
		system("cls");
		for (int i = 0; i < HOW_MUCH_FABRIC; i++)
		{
			std::cout << i + 1 << ")" << ALL_FABRIC[i].get_name() << std::endl;
		}
		std::cout << "exit)exit construction" << std::endl;
		std::cin >> choice;
		const char* chr = choice.c_str();
		int number_fabric = chr[0] - '0';
		if (number_fabric <= HOW_MUCH_FABRIC && number_fabric > 0) {
			std::cout << ALL_FABRIC[number_fabric - 1].get_name() << std::endl << " income resurs = " << ALL_FABRIC[number_fabric - 1].get_name_resurs() << std::endl << " income = " << ALL_FABRIC[number_fabric - 1].get_income() << std::endl << " cost = " << ALL_FABRIC[number_fabric - 1].get_cost() << std::endl;
			std::cout << "buy y/n" << std::endl;
			std::cin >> choice;
			if (choice == "y") {
				this->build_fabric(ALL_FABRIC[number_fabric - 1]);
			}
		}
		else
		{
			break;
		}
	}
}
void country_pleyr::menu_news() 
{	system("cls");
	std::cout << "-1)exit_menu" << std::endl;
	std::string offset;
	std::cout << this->news << std::endl;
	std::cin >> offset;
}
void country_pleyr::world_menu(std::vector<country_bot> &ALL_COUNTRY)
{
	while (true) {
		system("cls");
		int count = 0;
		std::cout<<"-1)exit"<<std::endl;
		std::for_each(ALL_COUNTRY.begin(), ALL_COUNTRY.end(), [&count = count](country_bot& country)
		{
			++count;
			std::cout << count << ")" << country.get_name() << std::endl;
		});
		std::cout << "please select a country:";
		std::cin >> count;
		count -= 1;
		if (count < 0) 
		{
			return;
		}
		if (ALL_COUNTRY.size() > count) {
			system("cls");
			std::cout << "power = " << ALL_COUNTRY[count].get_power()<<"\tour power = "<<this->power << std::endl;
			std::cout << "population = " << ALL_COUNTRY[count].get_population() << std::endl;
			std::cout << "what resources does this country produce:" << std::endl;
			std::for_each(std::begin(ALL_NAME_RESURS), std::end(ALL_NAME_RESURS), [&effor = ALL_COUNTRY[count]](const std::string &name_resurs)
			{
				std::cout << name_resurs << " = "<< effor.get_how_many_this_resources_produce(name_resurs)<< std::endl;
			});
			std::cout << "if you want to capture this country lead 1 else -1" << std::endl;
			if (ALL_COUNTRY[count].get_power() < this->power)
			{
				this->seizure_of_the_country(&ALL_COUNTRY[count]);
				this->set_news("we captured the country of "+ ALL_COUNTRY[count].get_name());
				ALL_COUNTRY.erase(
					std::remove_if(std::begin(ALL_COUNTRY), std::end(ALL_COUNTRY), [effor = ALL_COUNTRY[count].get_name()](const country_bot& country){
					if (effor == country.get_name())
					{
						return true;
					}
					return false;
				}), std::end(ALL_COUNTRY));
			}
			else 
			{
				this->end_game("We lost the wars of " + ALL_COUNTRY[count].get_name() + "\nlong live the new greatest government of " + ALL_COUNTRY[count].get_name());
			}

			std::cin >> count;
		}
	}
}

void country_pleyr::end_game(std::string why) 
{
	system("cls");
	std::cout << why << std::endl;
	exit(EXIT_SUCCESS);
}
