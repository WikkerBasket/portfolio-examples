#include <string>
#include <vector>

struct Dice {
    void rollDice(int d, int q);
    void returnDice();
    std::vector<int> rolledVal;
};


class Enemy {
public:
    Enemy();
    ~Enemy();
    Enemy(std::string n, std::string t, int h, int d);
    void rollEnemy();
    void getEnemy();
    void takeDamage(int d) { health -= d; }
    int getHealth();
    std::string getType();
    std::string name = "";
    int ac = 0;
    int damage = 0;
private:
    Dice dice;
    int health = 0;
    std::string type = "";
};

class Player {
public:
    Player();
    Player(std::string n, int h, int d);
    void takeDamage(int d) { health -= d; }
    void getPlayer();
    int getHealth();
    void operator+(Enemy& enemy);
    void operator-(Enemy& enemy);
    int ac = 12;
private:
    std::string name = "";
    int health = 0;
    int damage = 0;
};

class Combat {
public:
    Combat();
    void runCombat(Player p, std::vector<Enemy> e);
private:
    int turnNum = 0;
    std::vector<Enemy> enemies;
    Player player;
};

