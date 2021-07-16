#include <iostream>
#include "country_pleyr.h"
#include "country.h"
#include <random>
#include "time.h"
#include "setting.h"
#include <algorithm>

void update_all_bot_country()
{
    for (int i = 0; i < ALL_COUNTRY.size(); ++i)
    {
        ALL_COUNTRY[i].update_game_bot();
        ALL_COUNTRY[i].update();
    };
}
int main()
{
    srand(time(NULL));
    country_pleyr s("NAME", 1000);
    while (true) {
        s.menu(ALL_COUNTRY);
        update_all_bot_country();
        s.update();
    }
    return 0;
}
