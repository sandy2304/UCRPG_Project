#ifndef __BCOE_Weapon__
#define __BCOE_Weapon__

#include "weapon.hpp"

using namespace std;

class BCOE_Weapon: public Weapon{
	public:
		BCOE_Weapon():Weapon(){
			name = adj + " Clipboard";
		}
		
		virtual void weaponDetails() const{
			cout << "Weapon Name: " << name << endl;
			cout << "With a Clipboard, you attack twice dealing damage equivalent to half of your DEF." << endl;
		}
};

#endif
