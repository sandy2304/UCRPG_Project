#ifndef __SM_Weapon__
#define __SM_Weapon__

#include "weapon.hpp"

using namespace std;

class SM_Weapon: public Weapon{
	public:
		SM_Weapon(int num):Weapon(num){
			name = adj + " Syringe";
		}
		
		virtual void weaponDetails() const{
			cout << "Weapon Name: " << name << endl;
			cout << "With a Syringe, you heal as you attack, aka life steal." << endl;
		}
		
		virtual void weaponPassive(Entity* atk, Entity* rec){
			double hpGain = 3 * statBoost;
			atk->setHP(hpGain,1);
			if(atk->getHP() == atk->getmaxHP()){
				cout << atk->getName() << " replenished thier hp using their " << name  << endl;	
			}else{
				cout << atk->getName() << " replenished their hp by " << hpGain << " using their " << name << endl;
			}
		} 
};

#endif
