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
			double hpGain = (atk->getmaxHP() - (atk->getHP() * .25));
			double mpLoss = (atk->getmaxMP() * .50);
			atk->setHP(hpGain,1);
			
			//Set amount of mp lost
			atk->setMP(mpLoss,2);

			//Output to console the who and what, when the skill happened
			cout << atk->getName() << " used debug and healed " << hpGain << endl;
		}

};

//This skill deals a flat amount of damage based on the character's level
class Sabotage: public Skill{
	public:
		Sabotage():Skill(){}
		
		virtual void do_Skill(Entity* atk, Entity* rec){
			//What is the skill going to do
			double damageDone = (atk->getLevel() * 20.0);
			double mpLoss= (8.0 * atk->getLevel()) - rec->getDEF() * .25;
			rec->setHP(damageDone, 2);
		
			//Set amount of mp lost
			atk->setMP(mpLoss,2);
			//Output to connsole the whos and what
			cout << atk->getName() << " used Sabotage, deleting their hmoework file, and dealing " << damageDone << " damage" << endl;
		}	
};

class Faulty_Circuit: public Skill{
	public:
		Faulty_Circuit():Skill(){}
		
		virtual void do_Skill(Entity* atk, Entity* rec){
			//What is the skill going to do
			double mpLoss= (6.0 * atk->getLevel());
			srand(time(NULL));
			double sparks = rand()%8 + 1;
			double damageDone = ((sparks * 4) * atk->getLevel()) - (rec->getDEF() * .25);			

			rec->setHP(damageDone, 2);
		
			//Set amount of mp lost
			atk->setMP(mpLoss,2);
			//Output to connsole the whos and what
			cout << atk->getName() << " threw a faulty circuit, sparking " << sparks 
				<< " times, dealing " << damageDone << " damage" << endl;
		}	

};
//Ground Zero
#endif
