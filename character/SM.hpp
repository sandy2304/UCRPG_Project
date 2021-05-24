#ifndef __SM__
#define __SM__

#include "character.hpp"

class SM_Entity : public Entity{
	public:
		SM_Entity(string name, int lvl, int type):Entity(name, "SM", lvl, type){
			if(type == 1){
				HP = 110 * lvl;
				ATK = 15 * lvl;
				DEF = 15 * lvl;
				INT = 10 * lvl;
				MP = 20 * lvl;
				Gold = 100 * lvl;
			}
			else{
				HP = 110 * (lvl + .5);
				ATK = 15 * (lvl + .5);
				DEF = 15 * (lvl + .5);
				INT = 10 * (lvl + .5);
				MP = 20 * (lvl + .5);
				Gold = 100 * lvl;
	
			}
			maxHP = HP;
			maxMP = MP;
		}

		virtual void attack(Entity* enemy) const{
			cout << Name << " gave " << enemy->getName() << " the Johnson and Johsnson vaccine " <<  endl;
		}

};

#endif 
