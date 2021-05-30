#ifndef __SM__
#define __SM__

#include "character.hpp"

class SM_Entity : public Entity{
	public:
		SM_Entity(string name, int lvl, int type):Entity(name, "SM", lvl, type){
			if(type == 1){
				HP = 110 * lvl;
				ATK = 15 * lvl;
				DEF = 25 * lvl;
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
			skillList = {"Medkit","Syringe","Incision"};

		}
		
		virtual void LevelUp(){
			
			if(this->getLevel() != 6){
				this->manualSetHP(110 * (this->getLevel() + 1));
				this->manualSetATK(15 * (this->getLevel() + 1));
				this->manualSetDEF(15 * (this->getLevel() + 1));
				this->manualSetINT(10 * (this->getLevel() + 1));
				this->manualSetMP(20 * (this->getLevel() + 1));
				this->manualSetLevel(this->getLevel() + 1);			
			}else{
				cout << "Character has reached max level of 6" << endl;
			}
				
		}
		


};

#endif 
