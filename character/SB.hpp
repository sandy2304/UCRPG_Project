#ifndef __SB__
#define __SB__

#include "character.hpp"

class SB_Entity : public Entity{
	public:
		SB_Entity(string name, int lvl, int type):Entity(name, "SB", lvl, type){
			if(type == 1){
				HP = 100 * lvl;
				ATK = 20 * lvl;
				DEF = 25 * lvl;
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
			maxHP = HP;
			maxMP = MP;
			maxATK = ATK;
			maxDEF = DEF;
			maxINT = INT;
			skillList = {"Briefcase","Robinhood","Stock-Market-Crash"};

		}
		
		virtual void LevelUp(){
			if(Level != 6){
				maxHP = HP = 100 * (Level + 1);
				maxMP = MP = 20 * (Level + 1);
				maxATK = ATK = 20 * (Level + 1);
				maxDEF = DEF = 25 * (Level + 1);
				maxINT = INT = 15 * (Level + 1);
				Level++;
			}
			else{
				cout << "Level Up" << endl;
			}
			
		}
		

};

#endif 
