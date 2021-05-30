#ifndef __SM_SKILLS__
#define __SM_SKILLS__

#include "Skill.hpp"

using namespace std;

class MedKit : public Skill {
public:
	MedKit() :Skill() {}

	virtual void do_Skill(Entity* atk, Entity* rec) {
		//What is the skill going to do
		double hpGain = atk->getmaxHP() - atk->getHP();
		double mpLoss = (atk->getmaxMP() * .50);
		
		atk->setHP(hpGain, 1);
		atk->setMP(mpLoss, 2);
		
		//Output to console the who and what, when the skill happened
		cout << atk->getName() << " used MedKit!" << atk->getName() << " gained " << hpGain << " HP!" << endl;
	}
	
	virtual bool manaCheck(Entity* atk) {
		if (atk->getMP() >= (atk->getmaxMP() * .50)) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Syringe : public Skill { 
public:
	Syringe() :Skill() {}
		
	virtual void do_Skill(Entity* atk, Entity* rec) {
		//What is the skill going to do
		double damageDone = (atk->getATK() * 4) - (rec->getDEF());
		double attackLoss = (rec->getATK() * 0.2);
		double defenseLost = (rec->getDEF() * 0.2);
		double mpLoss = (atk->getLevel() * 6);
		
		rec->setHP(damageDone, 2);
		rec->setATK(attackLoss, 2);
		rec->setDEF(defenseLost, 2);
		
		//Set amount of mp lost
		atk->setMP(mpLoss, 2);
		
		//Output to connsole the whos and what
		cout << atk->getName() << " attacked with a syringe! It dealt " << damageDone << " damage, lowered attack by " << attackLoss << " and lowered defense by " << defenseLost
			<< ", weakening the enemy!" << endl;
	}
	
	virtual bool manaCheck(Entity* atk) {
		if ((atk->getLevel() * 6) <= (atk->getMP())) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Incision : public Skill {
public:
	Incision() :Skill() {}
	
	virtual void do_Skill(Entity* atk, Entity* rec) {
		//What is the skill going to do
		double damageDone = (atk->getATK() * 2 * (atk->getmaxHP() * .02)) - (rec->getDEF());
		double mpLoss(atk->getLevel() * 5);

		rec->setHP(damageDone, 2);

		//Set amount of mp lost
		atk->setMP(mpLoss, 2);
		//Output to connsole the whos and what
		cout << atk->getName() << " used Incision! It left a huge mark on the enemy, causing " << damageDone << " damage!" << endl;
	}
		
	virtual bool manaCheck(Entity* atk) {
		if ((atk->getLevel() * 5) <= atk->getMP()) {
			return true;
		}
		else {
			return false;
		}
	}
};

#endif
