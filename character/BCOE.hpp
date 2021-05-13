#ifndef __BCOE__
#define __BCOE__

#include "character.hpp"

class BCOE_Entity : public Entity{
	public:
		BCOE_Entity(string name, int lvl, int type):Entity(name, "BCOE", lvl, type){
			if(type == 1){
				HP = 100 * lvl - .5;
				ATK = 20 * lvl - .5;
				DEF = 10 * lvl - .5;
				INT = 5 * lvl - .5;
				MP = 20 * lvl - .5;
				Gold = 100 * lvl;
			}
			else{
				HP = 100 * lvl;
				ATK = 20 * lvl;
				DEF = 10 * lvl;
				INT = 5 * lvl;
				MP = 20 * lvl;
				Gold = 100 * lvl;
	
			}
		}

		virtual void attack(Entity* enemy) const{
			enemy->getDamage(ATK);
			cout << Name << " hacked " << enemy->getName() << endl;
		}

};

#endif 
