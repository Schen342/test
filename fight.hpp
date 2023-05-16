#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>
#include <set>
#include "player.hpp"

int fight(){
    int tdef = def;
    int o1;
    do{
        std::cout << "What would you like to do? \n" "1) Attack\n" "2) Run\n" "Selection: ";
        std::cin >> o1;
        if(o1 == 1){
        std::cout << "You attack!\n";
        int atkroll = rand() % 20+1;
        if(atkroll >= mdef){
                mhp = mhp - atk;
                std::cout << "You dealt " << mhp-atk << " damage!\n";
                if(matk >= def){
                    std::cout << "The monster attacks!";
                    hp = hp - (matk - def);
                    std::cout << "The monster dealt " << (matk - def) << " damage";
                    if(hp == 0){
                    std::cout << "You have died";
                    }
                }
                if(mhp == 0){
                    std::cout << "Done";
                    inv + drop;
                    std::cout << "The monster has dropped " + drop;
                }
            }else{
                std::cout << "You Missed!";
                if(matk >= def){
                    std::cout << "The monster attacks!";
                    hp = hp - (matk - def);
                    std::cout << "The monster dealt " << (matk - def) << " damage";
                    if(hp == 0){
                    std::cout << "You have died";
                    }
                }
            }
        }
    }while(mhp != 0 || hp != 0);
} 