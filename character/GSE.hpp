#ifndef __GSE__
#define __GSE__

#include "character.hpp"

class GSE_Entity : public Entity{
	public:
		GSE_Entity(string name, int lvl, int type):Entity(name, "GSE", lvl, type){
			if(type == 1){
				HP = 100 * lvl;
				ATK = 15 * lvl;
				DEF = 25 * lvl;
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
			if(this->getLevel() != 6){
				this->manualSetHP(100 * (this->getLevel() + 1));
				this->manualSetATK(15 * (this->getLevel() + 1));
				this->manualSetDEF(15 * (this->getLevel() + 1));
				this->manualSetINT(20 * (this->getLevel() + 1));
				this->manualSetMP(20 * (this->getLevel() + 1));
				this->manualSetLevel(this->getLevel() + 1);
			}else{
				cout << "Character has reached max level of 6" << endl;
			}
				
		}
		
};

#endif 
