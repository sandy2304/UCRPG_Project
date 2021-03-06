#ifndef __BCOE_SKILLS__
#define __BCOE_SKILLS__

#include "Skill.hpp"

using namespace std;

//This skill heals the character based on the amount of helath lost
class Debug: public Skill{
	public:
		Debug():Skill(){}
	
		virtual void do_Skill(Entity* atk, Entity* rec){
			//What is the skill going to do
			double hpGain = ((atk->getmaxHP() - atk->getHP()) * .75);
			double mpLoss = (atk->getmaxMP() * .50);
			atk->setHP(hpGain,1);
			
			//Set amount of mp lost
			atk->setMP(mpLoss,2);

			//Output to console the who and what, when the skill happened
			cout << atk->getName() << " used debug and healed " << hpGain << endl;
		}
		
		virtual bool manaCheck(Entity* atk){
			if(atk->getMP() > (atk->getmaxMP() / 2)){
				return true;
			}else{
				return false;
			}
		}

};

//This skill deals a flat amount of damage based on the character's level
class Sabotage: public Skill{
	public:
		Sabotage():Skill(){}
		
		virtual void do_Skill(Entity* atk, Entity* rec){
			//What is the skill going to do
			double damageDone = (atk->getATK() * 2) - (rec->getDEF());
			double mpLoss= (8.0 * atk->getLevel());
			rec->setHP(damageDone, 2);
			rec->setDEF(3 * atk->getLevel(), 2);
		
			//Set amount of mp lost
			atk->setMP(mpLoss,2);
			//Output to connsole the whos and what
			cout << atk->getName() << " used Sabotage, deleting their hmoework file, and dealing " << damageDone 
			<< " damage and lowered their defense" << endl;
		}	
		
		virtual bool manaCheck(Entity* atk){
			if((8.0 * atk->getLevel()) <= atk->getMP()){
				return true;
			}else{
				return false;
			}
		}
};

class Faulty_Circuit: public Skill{
	public:
		Faulty_Circuit():Skill(){}
		
		virtual void do_Skill(Entity* atk, Entity* rec){
			//What is the skill going to do
			double mpLoss= (6.0 * atk->getLevel());
			srand(time(NULL));
			double sparks = rand()% 5 + 3 ;
			double damageDone = ((sparks * .7) * atk->getATK()) - (rec->getDEF());			

			rec->setHP(damageDone, 2);
		
			//Set amount of mp lost
			atk->setMP(mpLoss,2);
			//Output to connsole the whos and what
			cout << atk->getName() << " threw a faulty circuit, sparking " << sparks 
				<< " times, dealing " << damageDone << " damage" << endl;
		}
		
		virtual bool manaCheck(Entity* atk){
			if((6.0*atk->getLevel() <= atk->getMP())){
				return true;
			}else{
				return false;
			}
		}	

};
//Ground Zero
#endif
