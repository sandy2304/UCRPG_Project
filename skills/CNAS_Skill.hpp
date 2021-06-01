#ifndef __CNAS_SKILLS__
#define __CNAS_SKILLS_

#include "Skill.hpp"

using namespace std; 

class Chemical_Splash: public Skill{
	public:
		Chemical_Splash():Skill(){}
	
		virtual void do_Skill(Entity* atk, Entity* rec){
			double damageDone = (atk->getATK() * 2) - rec->getDEF();
			double mpLoss = (2.0 * atk->getLevel());
			rec->setHP(damageDone,2);
			atk->setMP(mpLoss,2);

		cout << atk->getName() << " used Chemcial Splash and dealt " << damageDone << " damage!" << endl; 	 
		}

virtual bool manaCheck(Entity* atk){
	if((2.0 * atk->getLevel()) <= atk->getMP()){
		return true;
	}
	else{	
	return false;	
	}
}
		
};

class Explosion : public Skill{
	public:
		Explosion():Skill(){}

	virtual void do_Skill(Entity* atk, Entity* rec){
	double damageDone = (atk->getATK() * 6) - rec->getDEF();
	double selfDamage = damageDone * .2;
	double mpLoss = (4 * atk->getLevel());
	
	rec->setHP(damageDone,2);
	atk->setHP(selfDamage,2);
	atk->setMP(mpLoss,2); 

	cout << atk->getName() << " used Explosion! It dealt " << damageDone << " damage! " << atk->getName() << " inflicted " << selfDamage << " to themselves!" << endl;
	
}
virtual bool manaCheck(Entity* atk){
	if((4 * atk->getLevel()) <= atk->getMP()){
	return true;
	}
	else{
	return false; 
	}
}		
};

class Gravity : public Skill{
        public:
                Gravity():Skill(){}

        virtual void do_Skill(Entity* atk, Entity* rec){
        double damageDone = (atk->getATK() * 7) - rec->getDEF();
        double mpLoss = (10 * atk->getLevel());

        rec->setHP(damageDone,2);
        atk->setMP(mpLoss,2);
	rec->setINT(5 * atk->getLevel(),2);

	cout << atk->getName() << " used Gravity to slam " << rec->getName() << " to the ground! It dealt " << damageDone << " damage!" << endl;
	cout << rec->getName() << "'s INT fell!" << endl;
}
virtual bool manaCheck(Entity* atk){
        if((10 * atk->getLevel()) <= atk->getMP()){
        return true;
        }
        else{
        return false;
        }
}
};


#endif 
