#ifndef __SB__
#define __SB__

#include "character.hpp"

class SB_Entity : public Entity{
	public:
		SB_Entity(string name, int lvl, int type):Entity(name, "SB", lvl, type){
			if(type == 1){
				HP = 100 * lvl;
				ATK = 20 * lvl;
				DEF = 15 * lvl;
				INT = 15 * lvl;
				MP = 20 * lvl;
				Gold = 150 * lvl;
			}
			else{
				HP = 100 * (lvl + .5);
				ATK = 20 * (lvl + .5);
				DEF = 15 * (lvl + .5);
				INT = 15 * (lvl + .5);
				MP = 20 * (lvl + .5);
				Gold = 150 * lvl;
	
			}
		}

		virtual void attack(Entity* enemy) const{
			enemy->getDamage(ATK);
			cout << Name << " lied and told " << enemy->getName() << " Shiba Coin was going to the moon " << endl;
		}

};

#endif 
