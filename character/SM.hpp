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
			maxATK = ATK;
			maxDEF = DEF;
			maxINT = INT;

		}

		virtual void LevelUp(){
			if(Level != 6){
				maxHP = HP = 110 * (Level + 1);
				maxATK = ATK = 15 * (Level + 1);
				maxDEF = DEF = 15 * (Level + 1);
				maxINT = INT = 10 * (Level + 1);
				maxMP = MP = 20 * (Level + 1);
				Level = Level + 1;
			}else{
				cout << "Character has reached max level of 6" << endl;
			}	
		}


};

#endif 
