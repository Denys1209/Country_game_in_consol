#pragma once
#include <string>
#include "fabric.h"
#include "public_buildings.h"
#include "unit.h"
#include <map>
#include "country_bot.h"
#include <vector>
#include <algorithm>
static const int HOW_MUCH_RESURS = 5;
static const int HOW_MUCH_FABRIC = 3;
static const int ALL_WELFARE = 5;
static const int HOW_MUCH_FABRIC_CONSUMES_RESOURCES = 2;
static const int HOW_MUCH_PUBLIC_BUILDINGS = 4;
static const int HOW_MANY_UNIT = 3;
static const std::string ALL_NAME_RESURS[HOW_MUCH_RESURS] = {"number_1", "number_2", "number_3", "number_4" , "number_5" };
static const std::string ALL_NAME_WALFABE[ALL_WELFARE] = {"A", "B", "C", "D", "E"};
static const std::string ALL_NAME_UNIT[HOW_MANY_UNIT] = { "infantryman", "artillery", "tanks" };
static fabric ALL_FABRIC[HOW_MUCH_FABRIC] = {fabric(100, ALL_NAME_RESURS[0], "fabric_1", 1000), fabric(100, ALL_NAME_RESURS[1], "fabric_2", 1000) , fabric(100, ALL_NAME_RESURS[2], "fabric_3", 1000) };
static fabric_consumes_resources ALL_FABRIC_CONSUMES_RESOURCES[HOW_MUCH_FABRIC_CONSUMES_RESOURCES] = { fabric_consumes_resources(100, ALL_NAME_RESURS[2], "fabric_1",ALL_NAME_RESURS[3], 10, 1000), fabric_consumes_resources(100, ALL_NAME_RESURS[0], "fabric_1",ALL_NAME_RESURS[4], 10, 1000) };
static public_buildings ALL_PUBLIC_BUILDINGS[HOW_MUCH_PUBLIC_BUILDINGS] = { public_buildings("number_1", 1000, 3, "A"), public_buildings("number_2", 1000, 3, "B"), public_buildings("number_3", 1000, 3, "C"), public_buildings("number_4", 1000, 3, "D") };
static std::map<std::string, int> cost_all_resurs = { {ALL_NAME_RESURS[0], 100},  {ALL_NAME_RESURS[1], 200}, {ALL_NAME_RESURS[2], 250}, {ALL_NAME_RESURS[3], 400}, {ALL_NAME_RESURS[4], 350}, };
static const unit ALL_UNIT[HOW_MANY_UNIT] = { unit(10, 100, 1, ALL_NAME_UNIT[0]), unit(100, 1000, 10, ALL_NAME_UNIT[1]), unit(500, 5000, 50, ALL_NAME_UNIT[2]), };
static std::vector<country_bot> ALL_COUNTRY = { country_bot("NAME_0", 1000), country_bot("NAME_1", 1000), country_bot("NAME_2", 1000) };

