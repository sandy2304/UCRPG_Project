#ifndef __SM_Weapon__
#define __SM_Weapon__

#include "weapon.hpp"

using namespace std;

class SM_Weapon: public Weapon{
	public:
		SM_Weapon():Weapon(){
			name = adj + " Syringe";
		}
		
		virtual void weaponDetails() const{
			cout << "Weapon Name: " << name << endl;
			cout << "With a Syringe, you heal as you attack, aka life steal." << endl;
		}
};

#endif
