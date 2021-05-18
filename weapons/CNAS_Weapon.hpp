#ifndef __CNAS_Weapon__
#define __CNAS_Weapon__

#include "weapon.hpp"

using namespace std;

class CNAS_Weapon: public Weapon{
	public:
		CNAS_Weapon(int num):Weapon(num){
			name = adj + " Radioactive Pencil";
		}
		
		virtual void weaponDetails() const{
			cout << "Weapon Name: " << name << endl;
			cout << "With the Radioactive Pencil, your enemy takes extra damage each time you attack or use an ability" <<  endl;
		}
};

#endif
