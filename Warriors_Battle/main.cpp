#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <time.h>

using namespace std;

class Warrior{
protected:
    int attack_max;
    int block_max;

public:
    string name;
    int health;

    Warrior(string name, int health, int attack_max, int block_max){
        this -> name = name;
        this -> health = health;
        this -> attack_max = attack_max;
        this -> block_max = block_max;

    }

    int Attack(){
        return rand() % this -> attack_max;
    }

    int Block(){
        return rand() % this -> block_max;
    }
};

class Battle{
public:
    static void StartFight(Warrior& warrior1, Warrior& warrior2){
        while(true){
            if(Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0){
                cout << "Game Over\n";
                break;
            }
            if(Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0){
                cout << "Game Over\n";
                break;
            }
        }
    }

    static string GetAttackResult(Warrior& warriorA, Warrior& warriorB){

        int warriorA_attack = warriorA.Attack();
        int warriorB_block = warriorB.Block();
        int damage_to_WarriorB = ceil(warriorA_attack - warriorB_block);


        damage_to_WarriorB= (damage_to_WarriorB<= 0) ? 0 : damage_to_WarriorB;
        warriorB.health = warriorB.health - damage_to_WarriorB;

        printf("%s attacks %s and deals %d damage\n", warriorA.name.c_str(), warriorB.name.c_str(), damage_to_WarriorB);

        printf("%s is down to %d health\n\n", warriorB.name.c_str(), warriorB.health);


        if(warriorB.health <= 0){
            printf("%s has Died and %s WINS!\n", warriorB.name.c_str(), warriorA.name.c_str());
            return "Game Over";
        } else {
            return "Fight Again";
        }
    }
};

int main() {
    srand(time(NULL));
    printf("\n");

               //Name, Health, Attack, Block
    Warrior A("Warrior1", 50, 20, 15);
    Warrior B("Warrior2", 65, 20, 10);

    Battle::StartFight(A, B);

    return 0;
}