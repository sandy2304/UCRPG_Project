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
			
			if(this->getLevel() != 6){
				maxHP = HP = 170.0;
				this->manualSetATK(25 * (this->getLevel() + 1));
				this->manualSetDEF(20 * (this->getLevel() + 1));
				this->manualSetINT(25 * (this->getLevel() + 1));
				this->manualSetMP(20 * (this->getLevel() + 1));
				this->manualSetLevel(this->getLevel() + 1);
			}else{
				cout << "Character has reached max level of 6" << endl;
			}	
		}
		

};

#endif 
