#ifndef __CHASS_SKILL__
#define __CHASS_SKILL__

#include "Skill.hpp"
#include "../character/character.hpp"

using namespace std;

class Think: public Skill{
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
			atk->setMP(mpCost, 2);
		
			//Text Output
			cout << atk->getName() << " started to think......increasing their " << statName << " and healed thier HP" << endl;
		}		
		
		virtual bool manaCheck(Entity* atk){
			if((atk->getmaxMP() * .20) <= atk->getMP()){
				return true;
			}else{
				return false;
			}
		}
};

class Breakdance: public Skill{
	public: 
		Breakdance():Skill(){}
	
		virtual void do_Skill(Entity* atk, Entity* rec){
			//What is the skill going to do
			double damageDone = (atk->getATK() * (4)) - rec->getDEF();
			double defGain = (3 * atk->getLevel());
			rec->setHP(damageDone, 2);
			atk->setDEF(defGain,1);
		
			//MP COST
			double mpCost = 7 * atk->getLevel();
			atk->setMP(mpCost, 2);

			//Test Output
			cout << atk->getName() << " challenged " << rec->getName() << " to a breakdance battle and won, dealing " << damageDone 
				<< " damage and increased their defense by " << defGain << endl;
		}			
		
		virtual bool manaCheck(Entity* atk){
			if(7*atk->getLevel() <= atk->getMP()){
				return true;
			}else{
				return false;
			}	
		}
};

class Reverse_Psychology: public Skill{
	public:
		Reverse_Psychology():Skill(){}
		virtual void do_Skill(Entity* atk, Entity* rec){
			double damageDone = (rec->getATK() * (6.0)) - rec->getDEF();
			double attackGain = 5 * atk->getLevel();
			rec->setHP(damageDone, 2);

			double mpCost = 10 * atk->getLevel();
			atk->setMP(mpCost, 2);
			
			cout << atk->getName() << " used reverse psychology and " << rec->getName() << " did  " << damageDone << " to themselve " << endl;
		}
		
		virtual bool manaCheck(Entity* atk){
			if(10*atk->getLevel() <= atk->getMP()){
				return true;
			}else{
				return false;
			}
		}		
};
#endif 
