#ifndef __BCOE_Weapon__
#define __BCOE_Weapon__

#include "weapon.hpp"

using namespace std;

class BCOE_Weapon: public Weapon{
	public:
		BCOE_Weapon(int num):Weapon(num){
			name = adj + " Laptop";
		}
		
		virtual void weaponDetails() const{
			cout << "Weapon Name: " << name << endl;
			cout << "With a Laptop, the lower your health is, the more damage you will do." << endl;
		}
		
		virtual void weaponPassive(Entity* atk, Entity* def){
			cout << atk->getName() << "'s " << name << " dealt extra damage to " << def->getName() << endl;
		}
};

#endif
