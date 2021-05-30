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
			skillList = {"Ruler","Pop_Quiz","F-Hammer"};
			maxHP = HP;
			maxMP = MP;
			maxATK = ATK;
			maxDEF = DEF;
			maxINT = INT;

		}
		
		virtual void LevelUp(){
			if(Level != 6){
				maxHP = HP = 100 * (Level + 1);
				maxATK = ATK = 15 * (Level + 1);
				maxDEF = DEF = 15 * (Level + 1);
				maxINT = INT = 20 * (Level + 1);
				maxMP = MP = 20 * (Level + 1);
				Level = Level + 1;
			}else{
				cout << "Character has reached max level of 6" << endl;
			}	
		}

};

#endif 
