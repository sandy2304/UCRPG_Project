#ifndef SAVE_HPP
#define SAVE_HPP

#include <iostream>
#include "../character/character.hpp"
#include <fstream>

using namespace std; 

void ResetGame(){
ofstream myfile ("gamedata.txt");
 if(myfile.is_open()){
   myfile << "Name\n";
   myfile << "\n";
   myfile << "School\n";
   myfile << "0\n";
   myfile << "GOLD\n";
   myfile << "0\n";
   myfile << "Level\n";
   myfile << "0\n";
   myfile << "HP_Potion\n";
   myfile << "0\n";
   myfile << "MP_Potion\n";
   myfile << "0\n";
   myfile << "Weapon\n";
   myfile << "1\n";
   myfile.close();
   }
else cout << "Unable to open file";
} 

void SaveGame(Entity* player){ 
 ofstream myfile ("gamedata.txt"); 
 if(myfile.is_open()){
   myfile << "Name\n";
   myfile << player->getName() << "\n";
   myfile << "School\n";
   myfile << player->getSchool() << "\n";
   myfile << "GOLD\n";
   myfile << player->getGold() << "\n";
   myfile << "Level\n";
   myfile << player->getLevel() << "\n";
   myfile << "HP_Potion\n";
   myfile << player->getHP_potion() << "\n";
   myfile << "MP_Potion\n";
   myfile << player->getMP_potion() << "\n";
   myfile << "Weapon\n";
   myfile << player->getWeapon()->getLevel() << "\n";
   myfile.close();
   }
else cout << "Unable to open file";  
   }

#endif
