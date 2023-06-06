#include "rollerFunctions.h"
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

// ---------------------------------------Enemy---------------------------------------- \\

Enemy::Enemy() {}
Enemy::~Enemy() {}

Enemy::Enemy(std::string n, std::string t, int h, int d) {
    this->name = n;
    this->type = t;
    this->damage = d;
    this->health = h;
}

void Enemy::rollEnemy() {
    srand(time(NULL));
    std::vector<std::string> typeList = { "Undead", "Fairy", "Goblin", "Elven" };
    int randType = rand() % typeList.size();

    this->type = typeList[randType];

    if (this->type == "Undead") {
        std::vector<std::string> undeadNames = { "Zomborg","Boney","Smellgrave","Gwibble" };
        int randType = rand() % undeadNames.size();

        this->name = undeadNames[randType];
        this->health = 50;
        this->damage = 10;
        this->ac = 10;
    }
    else if (this->type == "Fairy") {
        std::vector<std::string> fairyNames = { "Weela","Booba","Pelfiz","Grobble" };
        int randType = rand() % fairyNames.size();

        this->name = fairyNames[randType];
        this->health = 20;
        this->damage = 20;
        this->ac = 14;
    }
    else if (this->type == "Goblin") {
        std::vector<std::string> goblinNames = { "Sneezle","Orglor","Grizz","Glonk" };
        int randType = rand() % goblinNames.size();

        this->name = goblinNames[randType];
        this->health = 25;
        this->damage = 5;
        this->ac = 12;
    }
    else if (this->type == "Elven") {
        std::vector<std::string> elvenNames = { "Estruss","Mindar","Wylan","Lorenna" };
        int randType = rand() % elvenNames.size();

        this->name = elvenNames[randType];
        this->health = 85;
        this->damage = 17;
        this->ac = 16;
    }
}

int Enemy::getHealth() { return this->health; }

std::string Enemy::getType() { return this->type; }

void Enemy::getEnemy() {

    std::cout << " " << this->name << "   " << this->type << "\n ---------------- \n ";
    std::cout << " " << this->health << "   |   " << this->damage << " \n\n";
}

// ---------------------------------------Dice---------------------------------------- \\

void Dice::returnDice() { for (int a : rolledVal) { std::cout << a; } }

void Dice::rollDice(int d, int q)
{
    srand(time(NULL));
    std::vector<int> diceType = { 2,4,6,8,10,12,20,100 };
    bool pass = false;
    rolledVal.clear();

    for (int a : diceType) {
        if (a == d) {
            pass = true;
        }
    }

    if (pass == false) {
        std::cout << "Unrecognized dice type.\n";
        return;
    }
    else if (pass == true) {
        for (int i = 0; i < q; i++) {
            this->rolledVal.push_back(1 + rand() % d);
            Sleep(200);
        }
        return;
    }
}

// -------------------------------Combat----------------------------- \\

Combat::Combat() {}

void Combat::runCombat(Player p, std::vector<Enemy> e) {
    char playerIn = ' ';
    bool uiLock = false;
    bool attack = false;
    int enemyCount = 0;
    int pHealth = p.getHealth();
    int actionPoints = 1;

    system("cls");

    do {
        while (uiLock == false && actionPoints > 0) {
        pre_loop:
            for (Enemy a : e) {
                if (a.getHealth() <= 0) {
                    auto it = std::find_if(e.begin(), e.end(), [&](Enemy& g) { return g.name == a.name; });
                    e.erase(it);
                    goto pre_loop;
                }
                a.getEnemy();
                std::cout << "\n";
            }
            if (p.getHealth() <= 0) {
                std::cout << "You have died!";
                Sleep(500);
                return;
            }
            else if (e.empty()) {
                std::cout << "Victory!!";
                Sleep(500);
                return;
            }
            std::cout << " HP \t Damage\n";
            std::cout << "__________________\n\n";
            p.getPlayer();
            std::cout << "__________AP:" << actionPoints << "__________\n";
            std::cout << "A:attack\tS:skill\nI:item\t\tQ:quit\n";
            std::cin >> playerIn;
            playerIn = tolower(playerIn);
            switch (playerIn) {
            case 'a':
                uiLock = true;
                attack = true;
                break;
            case 's':
                break;
            case 'i':
                break;
            case 'q':
                goto exit_loop;
            default:
                std::cout << "Unknown Action!\n";
                Sleep(500);
            }
            system("cls");
        }
        while (attack == true && actionPoints > 0) {
            for (Enemy a : e) {
                a.getEnemy();
                std::cout << "\n";
            }
            std::cout << " HP \t Damage\n";
            std::cout << "__________________\n\n";
            p.getPlayer();
            std::cout << "__________AP:"<< actionPoints <<"________(B to go back)____\n";
            for (Enemy a : e) {
                std::cout << ++enemyCount << ". " << a.name << "\t";
            }
            std::cout << "\n";
            std::cin >> playerIn;
            playerIn = tolower(playerIn);
            try {
                if (playerIn == 'b') {
                    uiLock = false;
                    attack = false;
                }
                else {
                    int pChar = playerIn - '0';
                    p + e.at(pChar - 1);
                    actionPoints--;
                }
            }
            catch(...) {
                std::cout << "Unknown Action!";
                Sleep(500);
            }

            enemyCount = 0;

            if (actionPoints == 0) {
                system("cls");
                uiLock = false;
                attack = false;

                for (Enemy a : e) {
                    if(a.getHealth() > 0) {
                        p - a;
                        std::cout << "\n";
                    }
                    else if (a.getHealth() <= 0) {
                        std::cout << a.name << " has died!\n";
                    }

                }
                actionPoints++;
            }


            system("cls");
        }
    exit_loop:
      system("cls");
    } while (playerIn != 'q' || pHealth <= 0 || e.empty());

    return;
}


// ------------------------------Player------------------------------- \\

Player::Player(){}

void Player::getPlayer() {
    std::cout << " " << this->name << "   " << "\n ---------------- \n ";
    std::cout << " " << this->health << "   |   " << this->damage << " \n\n";
}

int Player::getHealth() {
    return this->health;
}

Player::Player(std::string n, int h, int d) {
    this->name = n;
    this->damage = d;
    this->health = h;
}

void Player::operator+(Enemy& enemy) {
    Dice d;
    d.rollDice(20, 1);
    std::cout << "You rolled a ";
    Sleep(500);
    if (d.rolledVal[0] >= enemy.ac) {
        d.returnDice();
        std::cout << "! \nIt hit!";
        Sleep(750);
        enemy.takeDamage(damage);
    }
    else if (d.rolledVal[0] < enemy.ac) {
        d.returnDice();
        std::cout << "! \nIt missed!";
        Sleep(750);
    }
}

void Player::operator-(Enemy& enemy) {
    Dice d;
    d.rollDice(20, 1);
    std::cout << enemy.name << " rolled a ";
    Sleep(500);
    if (d.rolledVal[0] >= ac) {
        d.returnDice();
        std::cout << "! \nIt hit!";
        Sleep(750);
        takeDamage(enemy.damage);
    }
    else if (d.rolledVal[0] < ac) {
        d.returnDice();
        std::cout << "! \nIt missed!";
        Sleep(750);
    }
}