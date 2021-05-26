#ifndef __CHASS_Weapon__
#define __CHASS_Weapon__

#include "weapon.hpp"

using namespace std;

class CHASS_Weapon: public Weapon{
	public:
		CHASS_Weapon(int num):Weapon(num){
			name = adj + " Pen";
		}
		
		virtual void weaponDetails() const{
			cout << "Weapon Name: " << name << endl;
			cout << "With a Pen, you have a chance to rewrite your stats to be better or worse." << endl;
		}
		
		virtual void weaponPassive(Entity* atk, Entity* def){
			srand(time(NULL) + rand());
			int chance = rand() % 3 + 1;
			if(chance < 3){
				cout << "statBoost: " << statBoost << endl;
				int chance2 = rand() % 3 + 1;
				int chance3 = rand() % 100 + 1;
				int chance4;
				double statChange = 1.5 * statBoost;
				string stat, what;
				if(chance3 > 40.0){
					chance4 = 1;	
				}else{
					chance4 = 2;
				}
				if(chance2 == 1){
					atk->setDEF(statChange, chance4);
					stat = "DEF";
				}else if(chance2 == 2){
					atk->setATK(statChange, chance4);
					stat = "ATK";
				}else{	
					atk->setINT(statChange, chance4);	
					stat = "INT";
				}

				if(chance4 == 1){
					what = " added ";
				}else{
					what = " subtracted ";
				}
				
			cout << atk->getName() << " re-wrote thier " << stat  << " using ther " << name << " and" << what << statChange << endl;
			}
		}
};

#endif
