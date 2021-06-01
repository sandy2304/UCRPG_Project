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

TEST(BCOE_Skills,Sabotage_do_Skill){
	Entity* player1 = new BCOE_Entity("Dylan",1,1);
	Entity* player2 = new BCOE_Entity("Bob",1,1);
	Skill* skill = new Sabotage();
	bool  check1 = false;
	double num;
	
	skill->do_Skill(player1, player2);
	if((player2->getmaxHP() > player2->getHP()) && (player2->getDEF() < player2->getmaxDEF())){
		check1 = true;
	}
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check1 , true);
}

TEST(BCOE_Skills,Sabotage_manaCheck){
	Entity* player1 = new BCOE_Entity("Dylan",1,1);
	Entity* player2 = new BCOE_Entity("Bob",1,1);
	Skill* skill = new Sabotage();
	bool  check;
	
	player1->setMP(19,2);
	check = skill->manaCheck(player1);
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check , false);
}

TEST(BCOE_Skills,Faulty_Circuit_do_Skill){
	Entity* player1 = new BCOE_Entity("Dylan",1,1);
	Entity* player2 = new BCOE_Entity("Bob",1,1);
	Skill* skill = new Faulty_Circuit();
	bool  check1 = false;

	skill->do_Skill(player1, player2);
	if(player2->getmaxHP() > player2->getHP()){
		check1 = true;
	}
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check1 , true);
}

TEST(BCOE_Skills,Faulty_Circuit_manaCheck){
	Entity* player1 = new BCOE_Entity("Dylan",1,1);
	Entity* player2 = new BCOE_Entity("Bob",1,1);
	Skill* skill = new Faulty_Circuit();
	bool  check;
	
	player1->setMP(19,2);
	check = skill->manaCheck(player1);
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check , false);
}

TEST(CHASS_Skills,Think_do_Skill){
	Entity* player1 = new CHASS_Entity("Dylan",1,1);
	Entity* player2 = new CHASS_Entity("Bob",1,1);
	Skill* skill = new Think();
	bool  check1 = false;

	player1->setHP(5,2);
	skill->do_Skill(player1, player2);
	if(((player1->getATK() > player1->getmaxATK()) || (player1->getDEF() > player1->getmaxDEF()) ||  (player1->getINT() > player1->getmaxINT())) 
		 && (player1->getHP() ==  player1->getmaxHP())){
		check1 = true;
	}
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check1 , true);
}

TEST(CHASS_Skills,Think_manaCheck){
	Entity* player1 = new CHASS_Entity("Dylan",1,1);
	Entity* player2 = new CHASS_Entity("Bob",1,1);
	Skill* skill = new Faulty_Circuit();
	bool  check;
	
	player1->setMP(19,2);
	check = skill->manaCheck(player1);
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check , false);
}

TEST(CHASS_Skills,Breakdance_do_Skill){
	Entity* player1 = new CHASS_Entity("Dylan",1,1);
	Entity* player2 = new CHASS_Entity("Bob",1,1);
	Skill* skill = new Breakdance();
	bool  check1 = false;

	skill->do_Skill(player1, player2);
	if(player2->getHP() < player2->getmaxHP()){
		check1 = true;
	}
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check1 , true);
}

TEST(CHASS_Skills,Breakdance_manaCheck){
	Entity* player1 = new CHASS_Entity("Dylan",1,1);
	Entity* player2 = new CHASS_Entity("Bob",1,1);
	Skill* skill = new Breakdance();
	bool  check;
	
	player1->setMP(19,2);
	check = skill->manaCheck(player1);
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check , false);
}

TEST(CHASS_Skills,Reverse_Psychology_do_Skill){
	Entity* player1 = new CHASS_Entity("Dylan",1,1);
	Entity* player2 = new CHASS_Entity("Bob",1,1);
	Skill* skill = new Reverse_Psychology();
	bool  check1 = false;

	skill->do_Skill(player1, player2);
	if(player2->getHP() < player2->getmaxHP()){
		check1 = true;
	}
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check1 , true);
}

TEST(CHASS_Skills,Reverse_Psychology_manaCheck){
	Entity* player1 = new CHASS_Entity("Dylan",1,1);
	Entity* player2 = new CHASS_Entity("Bob",1,1);
	Skill* skill = new Reverse_Psychology();
	bool  check;
	
	player1->setMP(19,2);
	check = skill->manaCheck(player1);
	
	delete player1;
	delete player2;
	delete skill;
	EXPECT_EQ(check , false);
}

#endif
