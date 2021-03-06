#ifndef __BCOE__
#define __BCOE__

#include "character.hpp"

class BCOE_Entity : public Entity{
	public:
		BCOE_Entity(string name, int lvl, int type):Entity(name, "BCOE", lvl, type){
			if(type == 1){
				HP = 80 * lvl ;
				ATK = 25 * lvl;
				DEF = 30 * lvl;
				INT = 25 * lvl;
				MP = 20 * lvl;
				Gold = 100 * lvl;
			}
			else{
				HP = 80 * (lvl + .5);
				ATK = 25 * (lvl + .5);
				DEF = 20 * (lvl + .5);
				INT = 25 * (lvl + .5);
				MP = 20 * (lvl + .5);
				Gold = 100 * lvl;
	
			}
			skillList = {"Debug", "Sabotage", "Faulty_Circuit"};
			maxHP = HP;
			maxMP = MP;
			maxATK = ATK;
			maxDEF = DEF;
			maxINT = INT;
		}
		
		virtual void LevelUp(){
			if(Level != 6){
				maxHP = HP = 80 * (Level + 1);
				maxMP = MP = 20 * (Level + 1);
				maxATK = ATK = 25 * (Level + 1);
				maxDEF = DEF = 30 * (Level + 1);
				maxINT = INT = 25 * (Level + 1);
				Level++;
			}
			else{
				cout << "Level Up" << endl;
			}
		}
		

};

#endif 
