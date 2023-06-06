// CreatureFeature.cpp
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "rollerFunctions.h"

int main()
{

start_game:
    char input = ' ';
    Enemy e1;
    Enemy e2;
    Player p1 = { "Grilby", 100, 50 };
    Combat c1;
    e1.rollEnemy();
    Sleep(1000);
    e2.rollEnemy();
    std::vector<Enemy> enList = {e1, e2};

    c1.runCombat(p1, enList);

play_again:
    std::cout << "\n" << "Play again? Y\\N" << "\n";
    std::cin >> input;
    input = tolower(input);

    if (input == 'y') {
        goto start_game;
    }
    else if (input == 'n') {
        return 0;
    }
    else { goto play_again; }
}

