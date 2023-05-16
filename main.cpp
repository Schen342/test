#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>
#include "player.hpp"
#include "fight.hpp"
#include <set>

int hp;
int mhp;
int matk;
int mdef;
int atk;
int def;
int name;
const char* inv[6];
long long drop;

void slime(int lvl){
    // This sets up a basic monster
    mhp = 10*lvl;
    matk = 1*lvl;
    mdef = 2*lvl;
    drop = 'SlimeCore';
}

void encounter0(int num){
    int t = 1;
    //This is a random number generatior that adds in a chance for 
    int random = rand() % 10+1;
    if (random <= 9){
        std::cout << "You have an encountered " << num << " Slime\n";
        //This adds a slime object for the number set
        for(int i = 0; i < num; i++){
            slime(1);
        }
        fight();
    }else{
            std::cout << "You have noticed a monster but it didn't seem to notice you, the rest of the night was uneventful.";
    }
}

int option(){
    int o0;
    std::cout << "What would you like to do?\n" << "1) Sleep\n" << "2) Explore\n" << "3) Give Up . . .\n" << "Selection: "; 
    std::cin >> o0;
    int random = rand() % 10+1;
    if(o0 == 1){
        std::cout << "You decided to sleep for the night. \n";
        if(random < 10 && random >= 5){
            system("clear");
            std::cout << "Nothing Happened";
        }else if(random < 5){
            encounter0(1);
        }else if(random >= 10){
            encounter0(2);
        }
    }else if(o0 == 2){
            std::cout << "You look around the place and found nothing";
            return 0;
    }else if(o0 == 3){
        std::cout << "You have chosen to give up. . .";
        exit(0);
    }

    return 0;
}

int main(){
    int start;
    int alt_start;
    
    srand (time(NULL));
    int seed = rand() % 999+1;
    //this is a random number generator I made for a previous version of the project and decided to keep it
    //I wanted to do a story for this project but I had writers block. . .
    if(seed == 666){
        std::cout << "Welcome to The True Fallen Empire" << std::endl;
    }else {
        std::cout << "Welcome to The Fallen Empire" << std::endl;
        std::cout << "Would you like to start a New Game?" << std::endl << "Select\n" << "1) New Game\n" << "2) End Game\n" << "Selection: ";
        std::cin >> start;
        if(start == 1){
            system("clear");
            //The above clears the terminal to make it cleaner
            playerc(10, 10, 10);
            std::cout << "Welcome to the Fallen Empire, you are an adventure who has been excommunicated by the King to the forbidden land of the Fallen Empire.\n";
            option();
            std::cout << "This was just a test for a primitive combat and encounter situation.";
        }else{
            std::cout << "That was not an option";
            return(0);
        }
    }
    return 0;
}