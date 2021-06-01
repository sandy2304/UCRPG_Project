#ifndef __ENTITY_TESTS__
#define __ENTITY_TESTS__

#include "gtest/gtest.h"
#include "../Character_Factory/Character_Factory.hpp"
#include "../skills/Skill.hpp"
#include "../skills/BCOE_Skill.hpp"
#include "../skills/CHASS_Skill.hpp"
#include "../skills/CNAS_Skill.hpp"
#include "../skills/GSE_Skill.hpp"
#include "../skills/SB_Skill.hpp"
#include "../skills/SM_Skill.hpp"


TEST(Entity_Tests_Beaten, SchoolsBeatenTrue){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	bool check;

	player->addSchoolsBeaten("BCOE");
	player->addSchoolsBeaten("CHASS");
	check = player->checkifBeaten("CHASS");

	delete player;	
	EXPECT_EQ(check, true);
}

TEST(Entity_Tests_Beaten, SchoolsBeatenFalse){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	bool check;

	player->addSchoolsBeaten("BCOE");
	player->addSchoolsBeaten("CHASS");
	check = player->checkifBeaten("CNAS");
	
	delete player;	
	EXPECT_EQ(check, false);
}

TEST(Entity_Tests_reset, checkReset){
	Entity* player = new BCOE_Entity("Dylan", 1, 1);
	bool check = false;

	player->setHP(10,2);		
	player->setMP(10,2);
	player->setATK(10,2);
	player->setDEF(10,2);
	player->setINT(10,2);
	player->reset();

	if((player->getHP() == player->getmaxHP()) &&
	   (player->getMP() == player->getmaxMP()) &&
           (player->getATK() == player->getmaxATK()) &&
   	   (player->getDEF() == player->getmaxDEF()) &&
	   (player->getINT() == player->getmaxINT())){

		check = true;
	}
		
	delete player;	
	EXPECT_EQ(check, true);
}

TEST(Entity_Tests_Sets, setHP2){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	bool check;
	
	player->setHP(20,2);
	
	EXPECT_DOUBLE_EQ(player->getHP(), 60.0);
	delete player;
}

TEST(Entity_Tests_Sets, setHP1){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	bool check;
	int temp;
	
 
	player->setHP(20,2);
	temp = player->getHP();
	player->setHP(20,1);
	if(player->getHP() == player->getmaxHP()){
		check = true;
	}	

	delete player;
	EXPECT_EQ(check, true);
}

TEST(Entity_Tests_Sets, overHeal){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setHP(20,1);
	
	EXPECT_DOUBLE_EQ(player->getHP(), player->getmaxHP());
	delete player;
}

TEST(Entity_Tests_Sets, setMP1){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	bool check;
	int temp;
	
 
	player->setHP(20,2);
	temp = player->getHP();
	player->setHP(20,1);
	if(player->getHP() == player->getmaxHP()){
		check = true;
	}	

	delete player;
	EXPECT_EQ(check, true);
}

TEST(Entity_Tests_Sets, setMP2){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setMP(10,2);
	
	EXPECT_LT(player->getMP(), player->getmaxMP());
	delete player;
}

TEST(Entity_Tests_Sets, overMP){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setHP(20,1);
	
	EXPECT_DOUBLE_EQ(player->getHP(), player->getmaxHP());
	delete player;
}

TEST(Entity_Tests_Sets, setATK1){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setATK(20,1);	
	
	EXPECT_GT(player->getATK(), player->getmaxATK() );
	delete player;
}

TEST(Entity_Tests_Sets, setATK2){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setATK(10,2);
	
	EXPECT_LT(player->getATK(), player->getmaxATK());
	delete player;
}

TEST(Entity_Tests_Sets, setATKboundary){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setATK(500,2);
	
	EXPECT_EQ(player->getATK(), 10);
	delete player;
}

TEST(Entity_Tests_Sets, setDEF1){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setDEF(20,1);	

	EXPECT_GT(player->getDEF(), player->getmaxDEF() );
	delete player;
}

TEST(Entity_Tests_Sets, setDEF2){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setDEF(10,2);
	
	EXPECT_LT(player->getDEF(), player->getmaxDEF());
	delete player;
}

TEST(Entity_Tests_Sets, setDEFboundary){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setDEF(500,2);
	
	EXPECT_EQ(player->getDEF(), 10);
	delete player;
}

TEST(Entity_Tests_Sets, setINT1){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setINT(20,1);	
	
	EXPECT_GT(player->getINT(), player->getmaxINT() );
	delete player;
}

TEST(Entity_Tests_Sets, setINT2){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setINT(10,2);
	
	EXPECT_LT(player->getINT(), player->getmaxINT());
	delete player;
}

TEST(Entity_Tests_Sets, setINTboundary){
	Entity* player  = new BCOE_Entity("Dylan" ,1 ,1);
	
	player->setINT(500,2);
	
	EXPECT_EQ(player->getINT(), 10);
	delete player;
}

TEST(Entity_Tests_LevelUp, levelUPlevel){
	Entity* player = new BCOE_Entity("Dylan",1,1);

	player->LevelUp();

	EXPECT_EQ(player->getLevel(), 2);
	delete player;
}

TEST(Entity_Tests_LevelUp, levelUPHP){
	Entity* player = new BCOE_Entity("Dylan",1,1);

	player->LevelUp();
	
	EXPECT_EQ(player->getmaxHP(), 160);
	delete player;
}

TEST(Entity_Tests_LevelUp, levelUPMP){
	Entity* player = new BCOE_Entity("Dylan",1,1);

	player->LevelUp();
	
	EXPECT_EQ(player->getmaxMP(), 40);
	delete player;
}

TEST(Entity_Tests_LevelUp, levelUPATK){
	Entity* player = new BCOE_Entity("Dylan",1,1);

	player->LevelUp();
	
	EXPECT_EQ(player->getmaxATK(), 50);
	delete player;
}

TEST(Entity_Tests_LevelUp, levelUPDEF){
	Entity* player = new BCOE_Entity("Dylan",1,1);

	player->LevelUp();
	
	EXPECT_EQ(player->getmaxDEF(), 60);
	delete player;
}

TEST(Entity_Tests_LevelUp, levelUPINT){
	Entity* player = new BCOE_Entity("Dylan",1,1);

	player->LevelUp();
	
	EXPECT_EQ(player->getmaxINT(), 50);
	delete player;
}

TEST(Entity_Tests_attack, normalAttack){
	Entity* player1 = new BCOE_Entity("Dylan",1,1);
	Entity* player2 = new BCOE_Entity("John",1,1);
	
	player1->attack(player2);
	
	EXPECT_LT(player2->getHP(),player2->getmaxHP());
	delete player1;
	delete player2;
}

TEST(Entity_Tests_Potion, HPPotion){
	Entity* player = new BCOE_Entity("Dylan",1,1);
	bool use;

	player->setHP_Potion(1,1);
	player->setHP(20,2);
	use = player->usePotion(1);
	

	EXPECT_EQ(player->getmaxHP(), player->getHP());
	delete player;
}

TEST(Entity_Tests_Potion, MPPotion){
	Entity* player = new BCOE_Entity("Dylan",1,1);
	bool use;

	player->setMP_Potion(1,1);
	player->setMP(10,2);
	use = player->usePotion(2);
	
	EXPECT_EQ(player->getmaxMP(), player->getMP());
	delete player;
}

#endif
