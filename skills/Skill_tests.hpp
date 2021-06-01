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

#endif
