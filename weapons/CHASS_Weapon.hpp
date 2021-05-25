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
			srand(time(NULL));
			int chance = rand() % 3 + 1;
			if(chance < 3){
				int chance2 = rand() & 3 + 1;
				int chance3 = rand() & 2 + 1;
				string stat, what;
				if(chance2 == 1){
					atk->setDEF(5*statBoost, chance3);
					stat = "DEF";
				}else if(chance == 2){
					atk->setATK(5*statBoost, chance3);
					stat = "ATK";
				}else{	
					atk->setINT(5*statBoost, chance3);	
					stat = "INT";
				}

				if(chance3 == 1){
					what = " added ";
				}else{
					what = " subtracted ";
				}
				
			cout << atk->getName() << " re-wrote thier " << stat  << " and " << what << 5*statBoost << endl;
			}
		}
};

#endif
