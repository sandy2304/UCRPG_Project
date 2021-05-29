#ifndef __CNAS_Weapon__
#define __CNAS_Weapon__

#include "weapon.hpp"

using namespace std;

class CNAS_Weapon: public Weapon{
	public:
		CNAS_Weapon(int num, int mod):Weapon(num, mod){
			name = "Radioactive Pencil";
		}
		
		virtual void weaponDetails() {
			cout << "Weapon Name: " << this->getName() << endl;
			cout << "With the Radioactive Pencil, your enemy takes extra damage each time you attack or use an ability" <<  endl;
		}
		
		virtual void weaponPassive(Entity* atk, Entity* rec){
			double damageDone = statBoost * 1.1;
			rec->setHP(damageDone, 2);
			cout << atk->getName() << "'s " << this->getName() << " did " << damageDone <<  " to " << rec->getName() << endl;	
		}
};

#endif
