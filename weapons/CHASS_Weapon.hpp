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
			cout << atk->getName() << "re-wrote thier <stat> from to <newStat>" << endl;
		}
};

#endif
