#ifndef __CHARACTER_FACTORY_TESTS__
#define __CHARACTER_FACTORY_TESTS__

#include "gtest/gtest.h"
#include "Character_Factory.hpp"


TEST(CharacterFactory, BCOEcheck){
	Entity_Factory* Factory = new BCOE_Factory();
	Entity* player = Factory->createEntity("Dylan", 1, 1);
	bool check = false;

	if(player != nullptr){
		check = true;	
	}
	
	delete Factory;
	delete player;
	EXPECT_EQ(check, true);
}

TEST(CharacterFactory, CHASScheck){
	Entity_Factory* Factory = new CHASS_Factory();
	Entity* player = Factory->createEntity("Dylan", 1, 1);
	bool check = false;

	if(player != nullptr){
		check = true;	
	}
	
	delete Factory;
	delete player;
	EXPECT_EQ(check, true);
}

TEST(CharacterFactory, CNAScheck){
	Entity_Factory* Factory = new CNAS_Factory();
	Entity* player = Factory->createEntity("Dylan", 1, 1);
	bool check = false;

	if(player != nullptr){
		check = true;	
	}
	
	delete Factory;
	delete player;
	EXPECT_EQ(check, true);
}

TEST(CharacterFactory, GSEcheck){
	Entity_Factory* Factory = new GSE_Factory();
	Entity* player = Factory->createEntity("Dylan", 1, 1);
	bool check = false;

	if(player != nullptr){
		check = true;	
	}
	
	delete Factory;
	delete player;
	EXPECT_EQ(check, true);
}

TEST(CharacterFactory, SBcheck){
	Entity_Factory* Factory = new SB_Factory();
	Entity* player = Factory->createEntity("Dylan", 1, 1);
	bool check = false;

	if(player != nullptr){
		check = true;	
	}
	
	delete Factory;
	delete player;
	EXPECT_EQ(check, true);
}

TEST(CharacterFactory, SMcheck){
	Entity_Factory* Factory = new SM_Factory();
	Entity* player = Factory->createEntity("Dylan", 1, 1);
	bool check = false;

	if(player != nullptr){
		check = true;	
	}
	
	delete Factory;
	delete player;
	EXPECT_EQ(check, true);
}

#endif
