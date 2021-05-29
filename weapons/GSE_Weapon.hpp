#ifndef __GSE_Weapon__
#define __GSE_Weapon__

#include "weapon.hpp"

using namespace std;

class GSE_Weapon: public Weapon{
	public:
		GSE_Weapon(int num, int mod):Weapon(num, mod){
			name = "Clipboard";
		}
		
		virtual void weaponDetails() {
			cout << "Weapon Name: " << this->getName() << endl;
			cout << "With a Clipboard, you can replenish all of your mp and gain defense" << endl;
		}
		
		virtual void weaponPassive(Entity* atk, Entity* rec){
			srand(time(NULL) + rand());
			int chance = (rand() % 100) + 1;
			if(chance < 11){
				double defUP = (5 * statBoost);
				atk->setMP(atk->getMP(),2);
				atk->setMP(atk->getmaxMP(),1);
				atk->setDEF(statBoost,1);
				cout << atk->getName() << " replenished all of their mp and increased their defense by " << defUP << " using their "
					<< this->getName() << endl;
			}
		}

};

#endif
