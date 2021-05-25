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
			cout << atk->getName() << "healed <number> hp" << endl;	
		} 
};

#endif
