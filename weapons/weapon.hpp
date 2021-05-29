#ifndef __WEAPON__
#define __WEAPON__

#include "../character/character.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

class Entity;
class Weapon{
	protected:
		string name = "";
		double statBoost = 0;
		string adj;
		double level;
		vector<string> adjectives = {"Dog-water ", "Trash ", "Broke ","99-Cent Store ","Mc-Donalds ", 
						    "Walmart ", "Office Depot ", "Rich ", "The Dean's "};

		
	public:
		~Weapon(){};
		Weapon(int lvl, int mode){
			//RANDOM WEAPON GENERATION BASED ON ENTITY LEVEL(1-6)
			if(mode == 1){
				srand(time(NULL) + rand());
				double num;
				if(lvl <= 2){
					num = (rand() % 3);
				}else if((lvl >= 3) && (lvl <= 4)){
			  		num = (rand() % 3) + 3;
				}else if((lvl >= 5) && (lvl <= 6)){
					num = (rand() % 3) + 6;
				}
				adj = adjectives.at(num);
				num = num + 1;
				level = num;
				statBoost = 1.5 * num;
				name = "Monkey Brain";
			}
			//Manual Weapon Constructor that takes in the index of the type of weapon wanted (0-8)
			else{	
				adj = adjectives.at(lvl);
				statBoost = 1.5 * (lvl + 1);
				level = static_cast<double>(lvl);
			}
		}
		
		string getAdj() {return adj;}
		string getName(){return adj + name;}
		double getStat(){return statBoost;}
		void levelUp(){
			if(this->getAdj() != "The Dean's"){
				adj = adjectives.at(level);
				level = level + 1;
				statBoost = 1.5 * (level);
			}else{
				cout << "Weapon has reached maximum level" << endl;
			}
		}
		
		virtual void weaponDetails() = 0;
		virtual void weaponPassive(Entity* atk, Entity* def) = 0;
		//virtual void upgradeWeapon(){} = 0;
};

#endif
