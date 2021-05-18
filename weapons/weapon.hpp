#ifndef __WEAPON__
#define __WEAPON__

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Weapon{
	protected:
		string name = "";
		int statBoost = 0;
		vector<string> adjectives = {"Doo-doo", "Trash", "Broke","99-Cent Store", 
					     "Walmart", "Office Depot", "Rich", "The Dean's"};
		string adj;
		
	public:
		~Weapon(){};
		Weapon(int n){
			vector<string> adjectives = {"Doo-doo", "Trash", "Broke","99-Cent Store", 
						    "Walmart", "Office Depot", "Rich", "The Dean's"};
			
			srand(time(NULL));
			int num;
			if(n <= 3){
				num = rand() % 3;
			}else{
			  	num = n;
			}
			adj = adjectives.at(num);
			statBoost = 2 * num;
			name = adj + " Monkey Brain";
		}

		string getName(){return name;}
		int getStat(){return statBoost;}
 
		virtual void weaponDetails()const = 0;
		//virtual void uniquePassive(){} = 0;
		//virtual void upgradeWeapon(){} = 0;
};

#endif
