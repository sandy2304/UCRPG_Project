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
		
	public:
		~Weapon(){};
		Weapon(int lvl){
			vector<string> adjectives = {"Dog-water", "Trash", "Broke","99-Cent Store","Mc-Donalds", 
						    "Walmart", "Office Depot", "Rich", "The Dean's"};
			
			srand(time(NULL) + rand());
			int num;
			if(lvl <= 2){
				num = (rand() % 3);
			}else if((lvl >= 3) && (lvl <= 4)){
			  	num = (rand() % 3) + 3;
			}else if((lvl >= 5) && (lvl <= 6)){
				num = (rand() % 3) + 6;
			}
			adj = adjectives.at(num);
			num = num + 1;
			statBoost = 1.5 * num;
			name = adj + " Monkey Brain";
		}
		
		string getName(){return name;}
		int getStat(){return statBoost;}
 
		virtual void weaponDetails()const = 0;
		virtual void weaponPassive(Entity* atk, Entity* def) = 0;
		//virtual void upgradeWeapon(){} = 0;
};

#endif
