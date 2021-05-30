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
			
			if(this->getLevel() != 6){
				this->manualSetHP(100 * (this->getLevel() + 1));
				this->manualSetATK(20 * (this->getLevel() + 1));
				this->manualSetDEF(15 * (this->getLevel() + 1));
				this->manualSetINT(15 * (this->getLevel() + 1));
				this->manualSetMP(20 * (this->getLevel() + 1));
				this->manualSetLevel(this->getLevel() + 1);
			}else{
				cout << "Character has reached max level of 6" << endl;
			}
			
		}
		

};

#endif 
