#ifndef __CHASS_SKILL__
#define __CHASS_SKILL__

#include "Skill.hpp"
#include "../character/character.hpp"

using namespace std;

class Think: Skill{
	public:
		Think():Skill(){}
		virtual void do_Skill(Entity* atk, Entity* rec){
			//WHat is the skill going to do
			srand(time(NULL) + rand());
			int stat = (rand() % 3) + 1;
			string statName;
			if(stat == 1){
				atk->setATK(5 * atk->getLevel(), 1);	
				statName = "attack";
			}else if(stat == 2){
				atk->setDEF(5 * atk->getLevel(), 1);
				statName = "defense";
			}else{
				atk->setINT(2 * atk->getLevel(), 1);
				statName = "intelligence";
			}
			
			atk->setHP(10 * atk->getLevel(),1);
			
			//MP COST
			double mpCost = atk->getmaxMP() * .20;
		
			//Text Output
			cout << atk->getName() << " started to think......increasing their " << statName << " and healed thier HP" << endl;
		}		
		
		virtual bool manaCheck(Entity* atk){
			if((atk->getmaxMP() * .20) <= atk->getmaxMP()){
				return true;
			}else{
				return false;
			}
		}
};


#endif 
