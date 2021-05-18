#ifndef __SB_Weapon__
#define __SB_Weapon__

#include "weapon.hpp"

using namespace std;

class SB_Weapon: public Weapon{
	public:
		SB_Weapon(int num):Weapon(num){
			name = adj + " E-Wallet";
		}
		
		virtual void weaponDetails() const{
			cout << "Weapon Name: " << name << endl;
			cout << "With the E-Wallet, you have a chance of stealing Bear-Bucks with each attack." << endl;
		}
};

#endif
