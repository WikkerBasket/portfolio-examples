#include "food.h"
#include <iostream>
#include <string>
#include <vector>

namespace foodworld {
    // --------------------------------Food-------------------------------------- \\

    Food::Food(std::string name, int calories, std::vector<std::string> flavors) {
        this->calories = calories;
        this->name = name;
        this->flavors = flavors;
    }

    bool Food::hasFlavor(std::string flavor) {
        for (std::string fl : this->flavors) {
            if (fl == flavor) {
                return true;
            }
        }
        return false;
    }


    // -----------------------------------Recipe------------------------------------- \\

    Recipe::Recipe(std::string name, int servings, std::vector<foodXrecipe> foods) {
        this->name = name;
        this->servings = servings;
        this->foods = foods;
    }

    void Recipe::showRecipe() {
        std::cout << this->name << "\n";
        std::cout << "Serves: " << this->servings << "\n";
        for (foodXrecipe a : this->foods) {
            std::cout << a.quantity << " " << a.food.name << ": " << a.food.getCalorieCount() << " calories. \n";
        }
        std::cout << "with a total calories count of: " << this->serveCalorie();
    }

    int Recipe::serveCalorie() {
        for (foodXrecipe a : this->foods) {
            totalCalories += a.food.getCalorieCount();
        }
        return totalCalories / this->servings;
    }
}