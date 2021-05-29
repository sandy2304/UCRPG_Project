#ifndef __SM_Weapon__
#define __SM_Weapon__

#include "weapon.hpp"

using namespace std;

class SM_Weapon: public Weapon{
	public:
		SM_Weapon(int num, int mod):Weapon(num, mod){
			name = "Syringe";
		}
		
		virtual void weaponDetails() {
			cout << "Weapon Name: " << this->getName() << endl;
			cout << "With a Syringe, you heal as you attack, aka life steal." << endl;
		}
		
		virtual void weaponPassive(Entity* atk, Entity* rec){
			double hpGain = 3 * statBoost;
			atk->setHP(hpGain,1);
			if(atk->getHP() == atk->getmaxHP()){
				cout << atk->getName() << " replenished thier hp using their " << this->getName()  << endl;	
			}else{
				cout << atk->getName() << " replenished their hp by " << hpGain << " using their " << this->getName() << endl;
			}
		} 
};

#endif
