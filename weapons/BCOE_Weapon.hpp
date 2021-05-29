#ifndef __BCOE_Weapon__
#define __BCOE_Weapon__

#include "weapon.hpp"

using namespace std;

class BCOE_Weapon: public Weapon{
	public:
		BCOE_Weapon(int num, int mod):Weapon(num, mod){
			name = "Laptop";
		}
		
		virtual void weaponDetails() {
			cout << "Weapon Name: " << this->getName() << endl;
			cout << "With a Laptop, the lower your health is, the more damage you will do." << endl;
		}
		
		virtual void weaponPassive(Entity* atk, Entity* def){
			srand(time(NULL));
			int rad = rand() % 10 + 1;
			if(rad < 4){	
				double dmg = (atk->getmaxHP() - atk->getHP()) * .25 * statBoost;
				def->setHP(dmg, 2);
				cout << atk->getName() << "'s " << this->getName() << " dealt extra " << dmg  <<  " damage to " << def->getName() << endl;
			}
		}
};

#endif
