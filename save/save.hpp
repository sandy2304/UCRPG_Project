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
   myfile << "HP\n";
   myfile << "0\n";
   myfile << "ATK\n";
   myfile << "0\n";
   myfile << "DEF\n";
   myfile << "0\n";
   myfile << "INT\n";
   myfile << "0\n";
   myfile << "MP\n";
   myfile << "0\n";
   myfile << "LEVEL\n";
   myfile << "0\n";
   myfile << "GOLD\n";
   myfile << "0\n";
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
   myfile << "HP\n";
   myfile << player->getHP() << "\n";
   myfile << "ATK\n";
   myfile << player->getATK() << "\n";
   myfile << "DEF\n";
   myfile << player->getDEF() << "\n";
   myfile << "INT\n";
   myfile << player->getINT() << "\n";
   myfile << "MP\n";
   myfile << player->getMP() << "\n";
   myfile << "LEVEL\n";
   myfile << player->getLevel() << "\n";
   myfile << "GOLD\n";
   myfile << player->getGold() << "\n";
   myfile.close();
   }
else cout << "Unable to open file";  
   }

#endif
