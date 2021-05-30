#ifndef __SB_SKILLS__
#define __SB_SKILLS__

#include "Skill.hpp"

using namespace std;

class Briefcase : public Skill {
public:
	Briefcase() :Skill() {}

	virtual void do_Skill(Entity* atk, Entity* rec) {
		//What is the skill going to do
		double damageDone = ((atk->getATK() * 2 * (atk->getGold() * 0.01)) - (rec->getDEF()));
		double mpLoss = (atk->getLevel() * 5);
	
		rec->setHP(damageDone, 2);
		atk->setMP(mpLoss, 2);

			//Output to console the who and what, when the skill happened
		cout << atk->getName() << " smacked " << rec->getName() << " with a Briefcase, dealing " << damageDone << " damage!" << endl;
	}
	
	virtual bool manaCheck(Entity* atk) {
		if (atk->getMP() >= (atk->getLevel() * 5)) {
			return true;
		}
		else {																											return false;
		}
	}
};

class Robinhood : public Skill {
public:
	Robinhood() :Skill() {}

	virtual void do_Skill(Entity* atk, Entity* rec) {
		//What is the skill going to do
		double goldGained = (atk->getLevel() * 75);
		double HPgained = (rec->getmaxHP() * 0.5);
		double mpLoss = (atk->getmaxMP() * 0.5);
		
		atk->setGOLD(goldGained, 1);
		atk->setHP(HPgained, 1);

		//Set amount of mp lost
		atk->setMP(mpLoss, 2);
		
		//Output to connsole the whos and what
		cout << atk->getName() << " made a " << goldGained << " profit from Robinhood, while also adding " << HPgained << " health!" << endl;
	}
	
	virtual bool manaCheck(Entity* atk) {
		if ((atk->getmaxMP() * 0.5) <= (atk->getMP())) {
			return true;
		}
		else {
			return false;
		}
	}
};

class StockMarketCrash : public Skill {
public: 
	StockMarketCrash() :Skill() {}
		
	virtual void do_Skill(Entity* atk, Entity* rec) {
		//What is the skill going to do
		srand(time(NULL) + rand());
		double randNum = (rand() % 9) + 4;
		double damageDone = (atk->getATK() * 3 * randNum) - (rec->getDEF());
		double intGained = 4 * rec->getLevel();
		double mpLoss = (atk->getLevel() * 6);
		
		rec->setHP(damageDone, 2);
		rec->setINT(intGained, 1);
		atk->setMP(mpLoss, 2);
		
		//Output to connsole the whos and what
		cout << atk->getName() << " shorted the stock market, dealing " << damageDone << " damage to " << rec->getName() << ". This market crashed increased " << rec->getName()
			<< "'s intelligence by " << intGained << "." << endl;																			}
		
	virtual bool manaCheck(Entity* atk) {
		if ((atk->getLevel() * 6) <= atk->getMP()) {
			return true;
		}
		else {
			return false;
		}
	}
};

#endif
