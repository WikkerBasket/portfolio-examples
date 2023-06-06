#include <iostream>
#include <string>
#include <vector>
#pragma once

namespace foodworld {
    class Food {
    public:
        Food(std::string name, int calories, std::vector<std::string> flavors);
        int getCalorieCount() { return calories; }
        bool hasFlavor(std::string flavor);

        Food operator+(const Food& food) const {
            std::vector<std::string> bothFlavors;
            for (std::string s : flavors) { bothFlavors.push_back(s); }
            for (std::string s : food.flavors) { bothFlavors.push_back(s); }
            Food newfood = { name + " and " + food.name, calories + food.calories, bothFlavors };
            return newfood;
        }
        std::string name;
        std::vector<std::string> flavors;
    private:
        int calories;
    };

    struct foodXrecipe {
        Food food;
        double quantity;
    };

    class Recipe {
    public:
        Recipe(std::string name, int servings, std::vector<foodXrecipe> foods);
        std::string name;
        void showRecipe();
        int serveCalorie();
    private:
        int totalCalories;
        int servings;
        std::vector<foodXrecipe> foods;
    };
}