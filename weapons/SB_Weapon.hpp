#ifndef __SB_Weapon__
#define __SB_Weapon__

#include "weapon.hpp"

using namespace std;

class SB_Weapon: public Weapon{
	public:
		SB_Weapon(int num, int mod):Weapon(num, mod){
			name = "E-Wallet";
		}
		
		virtual void weaponDetails() {
			cout << "Weapon Name: " << this->getName() << endl;
			cout << "With the E-Wallet, you deal an extra amount of damage that scales with the amount of Bear-Bucks that you have" << endl;
		}
		
		virtual void weaponPassive(Entity* atk, Entity* rec){
			double dmg = atk->getGold() * .005 * statBoost;
			rec->setHP(dmg,2);
			cout << atk->getName() << " did " << dmg << " extra damage using his " << this->getName() << endl;
		}
};

#endif
