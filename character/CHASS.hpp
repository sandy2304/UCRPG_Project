#ifndef __CHASS__
#define __CHASS__

#include "character.hpp"

class CHASS_Entity : public Entity{
	public:
		CHASS_Entity(string name, int lvl, int type):Entity(name, "CHASS", lvl, type){
			if(type == 1){
				HP = 110 * lvl;
				ATK = 15 * lvl;
				DEF = 10 * lvl;
				INT = 15 * lvl;
				MP = 20 * lvl;
				Gold = 100 * lvl;
			}
			else{
				HP = 100 * (lvl + .5);
				ATK = 15 * (lvl + .5);
				DEF = 10 * (lvl + .5);
				INT = 15 * (lvl + .5);
				MP = 20 * (lvl + .5);
				Gold = 100 * lvl;
	
			}
		}

		virtual void attack(Entity* enemy) const{
			enemy->getDamage(ATK);
			cout << Name << " argued and won against  " << enemy->getName() << endl;
		}

};

#endif 
