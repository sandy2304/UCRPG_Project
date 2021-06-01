#ifndef __SKILLS_TEST__
#define __SKILLS_TEST__

#include "gtest/gtest.h"
#include <iostream>
#include "../Character_Factory/Character_Factory.hpp"
#include "BCOE_Skill.hpp"
#include "CHASS_Skill.hpp"
#include "CNAS_Skill.hpp"
#include "GSE_Skill.hpp"
#include "SB_Skill.hpp"
#include "SM_Skill.hpp"
#include "Skill.hpp"

TEST(BCOE_Skills,Debug_do_Skill){
	Entity* player1 = new BCOE_Entity("Dylan",1,1);
	Entity* player2 = new BCOE_Entity("Bob",1,1);
	Skill* skill = new Debug();
	bool  check1 = false;
	double num;
	
	player1->setHP(20,2);
	num = player1->getHP();
	skill->do_Skill(player1, player2);
	if(player1->getHP() > num){
		check1 = true;
	}
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check1 , true);
}

TEST(BCOE_Skills,Debug_manaCheck){
	Entity* player1 = new BCOE_Entity("Dylan",1,1);
	Entity* player2 = new BCOE_Entity("Bob",1,1);
	Skill* skill = new Debug();
	bool  check;
	
	player1->setMP(19,2);
	check = skill->manaCheck(player1);
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check , false);
}

TEST(CNAS_Skills,Chemical_Spash){
	Entity* player1 = new CNAS_Entity("Dylan",1,1);
        Entity* player2 = new CNAS_Entity("Bob",1,1);
        Skill* skill = new Chemical_Splash();
        double num;

	skill->do_Skill(player1,player2);
	num = player2->getHP();

	/*should be 15 * 2 - 25 = 5 damage = 95 HP
	*/
        delete player1;
        delete player2;
        delete skill;
        EXPECT_EQ(num , 95);

}

TEST(CNAS_Skills,Explosion1){
        Entity* player1 = new CNAS_Entity("Dylan",1,1);
        Entity* player2 = new CNAS_Entity("Bob",1,1);
        Skill* skill = new Explosion();
        double num;

        skill->do_Skill(player1,player2);
        num = player2->getHP();

        /*should be 15 * 6 - 25 = 65 damage = 35 HP
        */
                delete player1;
                        delete player2;
                                delete skill;
                                        EXPECT_EQ(num , 35);
        
                                        }
TEST(CNAS_Skills,Explosion2){
        Entity* player1 = new CNAS_Entity("Dylan",1,1);
        Entity* player2 = new CNAS_Entity("Bob",1,1);
        Skill* skill = new Explosion();
        double num;

        skill->do_Skill(player1,player2);
        num = player1->getHP();

        /*should be 15 * 6 - 25 = 65 damage * .2 = 13 self = 100 - 13 = 87
 *         */
                delete player1;
                        delete player2;
                                delete skill;
                                        EXPECT_EQ(num , 87);

                                        }
TEST(CNAS_Skills,Gravity){
        Entity* player1 = new CNAS_Entity("Dylan",1,1);
        Entity* player2 = new CNAS_Entity("Bob",1,1);
        Skill* skill = new Gravity();
        double num;

        skill->do_Skill(player1,player2);
        num = player2->getHP();

        /*should be 15 * 7  - 25 = 80 damage = 20 HP
 *         */
        delete player1;
        delete player2;
        delete skill;
        EXPECT_EQ(num , 20);

}

TEST(GSE_Skills,Ruler){
        Entity* player1 = new GSE_Entity("Dylan",1,1);
        Entity* player2 = new GSE_Entity("Bob",1,1);
        Skill* skill = new Ruler();
        double num;

        skill->do_Skill(player1,player2);
        num = player2->getHP();

        /*should be 15 * 3  - 25 = 20 damage = 80 HP
 *  *         */
        delete player1;
        delete player2;
        delete skill;
        EXPECT_EQ(num , 80);

}

TEST(GSE_Skills,Pop_quiz){
        Entity* player1 = new GSE_Entity("Dylan",1,1);
        Entity* player2 = new GSE_Entity("Bob",1,1);
        Skill* skill = new Pop_Quiz();
        double num;

        skill->do_Skill(player1,player2);
        num = player2->getHP();

        /*should be 15 * 3  - 25 = 65 damage = 35 HP
 *  *  *         */
        delete player1;
        delete player2;
        delete skill;
        EXPECT_EQ(num , 35);

}

TEST(GSE_Skills,F_Hammer){
        Entity* player1 = new GSE_Entity("Dylan",1,1);
        Entity* player2 = new GSE_Entity("Bob",1,1);
        Skill* skill = new F_Hammer();
        double num;

        skill->do_Skill(player1,player2);
        num = player2->getHP();

        /*should be 15 * 10  - 25 = 125 damage = 0 HP
 *  *  *  *         */
        delete player1;
        delete player2;
        delete skill;
        EXPECT_EQ(num , 0);

}

TEST(GSE_Skills,F_Hammer2){
        Entity* player1 = new GSE_Entity("Dylan",1,1);
        Entity* player2 = new GSE_Entity("Bob",6,1);
        Skill* skill = new F_Hammer();
        double num;

	player2->setHP(300,2);
        skill->do_Skill(player1,player2);
        num = player2->getHP();

        /*should be 15 * 10  - 25 = 125 damage = 0 HP
 *  *  *  *  *         */
        delete player1;
        delete player2;
        delete skill;
        EXPECT_EQ(num , 0);

}




#endif
