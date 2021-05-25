#ifndef __GSE__
#define __GSE__

#include "character.hpp"

class GSE_Entity : public Entity{
	public:
		GSE_Entity(string name, int lvl, int type):Entity(name, "GSE", lvl, type){
			if(type == 1){
				HP = 100 * lvl;
				ATK = 15 * lvl;
				DEF = 15 * lvl;
				INT = 20 * lvl;
				MP = 20 * lvl;
				Gold = 125 * lvl;
			}
			else{
				HP = 100 * (lvl + .5);
				ATK = 15 * (lvl + .5);
				DEF = 15 * (lvl + .5);
				INT = 20 * (lvl + .5);
				MP = 20 * (lvl + .5);
				Gold = 125 * lvl;
	
			}
			maxHP = HP;
			maxMP = MP;
		}

};

#endif 
