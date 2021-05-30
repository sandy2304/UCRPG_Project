#ifndef __CHASS__
#define __CHASS__

#include "character.hpp"

class CHASS_Entity : public Entity{
	public:
		CHASS_Entity(string name, int lvl, int type):Entity(name, "CHASS", lvl, type){
			if(type == 1){
				HP = 110 * lvl;
				ATK = 15 * lvl;
				DEF = 20 * lvl;
				INT = 15 * lvl;
				MP = 20 * lvl;
				Gold = 100 * lvl;
			}
			else{
				HP = 100 * (lvl + .5);
				ATK = 15 * (lvl + .5);
				DEF = 10 * (lvl + .5);
				INT = 15 * (lvl + .5);
				MP = 20 * (lvl + .5);
				Gold = 100 * lvl;
	
			}
			skillList = {"Think", "Breakdance", "Reverse_Psychology"};
			maxHP = HP;
			maxMP = MP;
			maxATK = ATK;
			maxDEF = DEF;
			maxINT = INT;

		}
		
		
		virtual void LevelUp(){
			
			if(this->getLevel() != 6){
				this->manualSetHP(110 * (this->getLevel() + 1));
				this->manualSetATK(15 * (this->getLevel() + 1));
				this->manualSetDEF(10 * (this->getLevel() + 1));
				this->manualSetINT(15 * (this->getLevel() + 1));
				this->manualSetMP(20 * (this->getLevel() + 1));
				this->manualSetLevel(this->getLevel() + 1);
			}else{
				cout << "Character has reached max level of 6" << endl;
			}
				
		}
		

};

#endif 
