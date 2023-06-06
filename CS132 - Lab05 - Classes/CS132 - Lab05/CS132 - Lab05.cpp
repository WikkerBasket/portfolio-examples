// CS132 - Lab03.cpp
#include <iostream>
#include <string>
#include <vector>
#include "food.h"

using namespace foodworld;
int main()
{
    std::vector<std::string> flavorlist{ "blank" };

    Food spaghetti("Spaghetti", 360, flavorlist);
    foodXrecipe spag = { spaghetti, 1 };

    Food tomato("Tomato", 80, {"robust","sweet","tangy"});
    foodXrecipe tom = { tomato, 3 };

    Food basil("Basil", 10, {"herb", "savory", "bright"});
    foodXrecipe bas = { basil, 2 };

    Food yellowOnion("Yellow Onion", 120, flavorlist);
    foodXrecipe yel = { yellowOnion, 1 };

    Food garlic("Garlic Clove", 20, flavorlist);
    foodXrecipe gar = { garlic, 1 };

    std::vector<foodXrecipe> ingredients = { spag, tom, bas, yel, gar };

    Recipe mammaSpaghett("Mom's Spaghetti", 6, ingredients);

    mammaSpaghett.showRecipe();

    Food tombas = tomato + basil;


    std::cout << "\n\n";
    std::cout << "\n" << tombas.name << " " << tombas.getCalorieCount();
    for (std::string s : tombas.flavors) { std::cout << ", " << s; };


}