#ifndef __GSE_SKILLS__
#define __GSE_SKILLS_

#include "Skill.hpp"
#include <vector>

using namespace std;

class Ruler: public Skill{
        public:
                Ruler():Skill(){}

                virtual void do_Skill(Entity* atk, Entity* rec){ 
                        double damageDone = (atk->getATK() * 3) - rec->getDEF();
                        double mpLoss = (2.0 * atk->getLevel());
                        rec->setHP(damageDone,2);
                        atk->setMP(mpLoss,2);

                cout << atk->getName() << " smacked " << rec->getName() << " with a ruler!" << endl;
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

class Pop_Quiz : public Skill{
        public:
                Pop_Quiz():Skill(){}

                virtual void do_Skill(Entity* atk, Entity* rec){
                        double damageDone = (atk->getATK() * 6) - rec->getDEF();
                        double mpLoss = (5.0 * atk->getLevel());
                        rec->setHP(damageDone,2);
                        atk->setMP(mpLoss,2);

                cout << atk->getName() << " popped " << rec->getName() << " with a quiz! Dealing " << damageDone << " damage!" <<  endl;
                }

virtual bool manaCheck(Entity* atk){
        if((5.0 * atk->getLevel()) <= atk->getMP()){
                return true;
        }
        else{
        return false;
        }
}

};

class F_Hammer : public Skill{
        public:
                F_Hammer():Skill(){}

                virtual void do_Skill(Entity* atk, Entity* rec){
                        double damageDone = (atk->getATK() * 10) - rec->getDEF();
                        double mpLoss = (15 * atk->getLevel());
			if( rec->getHP() <= .5 * rec->getmaxHP()){
                        rec->setHP(rec->getHP(),2);
			cout << atk->getName() << " failed " << rec->getName() << "! " << rec->getName() << " passed away." << endl; 
			}
			else{
			rec->setHP(damageDone, 2);
			cout << atk->getName() << " dropped the F hammer and dealt " << damageDone << " damage!" << endl;
			}
                        atk->setMP(mpLoss,2);

                }

virtual bool manaCheck(Entity* atk){
        if((15 * atk->getLevel()) <= atk->getMP()){
                return true;
        }
        else{
        return false;
        }
}

};


//Pop quiz;
//F_Stamp

#endif
