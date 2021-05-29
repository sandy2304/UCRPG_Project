#ifndef __CNAS__
#define __CNAS__

#include "character.hpp"

class CNAS_Entity : public Entity{
	public:
		CNAS_Entity(string name, int lvl, int type):Entity(name, "CNAS", lvl, type){
			if(type == 1){
				HP = 100 * lvl;
				ATK = 15 * lvl;
				DEF = 25 * lvl;
				INT = 10 * lvl;
				MP = 20 * lvl;
				Gold = 100 * lvl;
			}
			else{
				HP = 100 * (lvl + .5);
				ATK = 15 * (lvl + .5);
				DEF = 25 * (lvl + .5);
				INT = 10 * (lvl + .5);
				MP = 20 * lvl;
				Gold = 100 * lvl;
	
			}
			skillList = {"Chemical_Splash","Explosion","Gravity"};
			maxHP = HP;
			maxMP = MP;
			maxATK = ATK;
			maxDEF = DEF;
			maxINT = INT;

		}


};

#endif 
