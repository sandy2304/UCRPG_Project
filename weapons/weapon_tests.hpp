#ifndef __WEAPON_TESTS__
#define __WEAPON_TESTS__

#include "gtest/gtest.h"
#include "weapon.hpp"
#include "BCOE_Weapon.hpp"
#include "CHASS_Weapon.hpp"
#include "CNAS_Weapon.hpp"
#include "GSE_Weapon.hpp"
#include "SB_Weapon.hpp"
#include "SM_Weapon.hpp"
#include "../Character_Factory/Character_Factory.hpp"

TEST(Weapons, randomWeapon_1){
	Weapon* weapon = new BCOE_Weapon(1,1);
	string name = "";
	bool one = false, two = false, three = false, four = false;
	for(int i = 0; i < 20; ++i){
		if(weapon->getName() == "Dog-water Laptop"){
			one = true;
		}
		if(weapon->getName() == "Broke Laptop"){
			two = true;
		}
		if(weapon->getName() == "Trash Laptop"){
			three = true;
		}
		if(one == true && two == true && three == true){
			four = true;
			delete weapon;
			break;
		}
		delete weapon;
		weapon = new BCOE_Weapon(1,1);
	}
	EXPECT_EQ(four, true);
} 

TEST(Weapons, randomWeapon_2){
	Weapon* weapon = new BCOE_Weapon(2,1);
	string name = "";
	bool one = false, two = false, three = false, four = false;
	for(int i = 0; i < 20; ++i){
		if(weapon->getName() == "Dog-water Laptop"){
			one = true;
		}
		if(weapon->getName() == "Broke Laptop"){
			two = true;
		}
		if(weapon->getName() == "Trash Laptop"){
			three = true;
		}
		if(one == true && two == true && three == true){
			four = true;		
			delete weapon;
			break;	
		}
		delete weapon;
		weapon = new BCOE_Weapon(2,1);
	}
	EXPECT_EQ(four, true);
} 

TEST(Weapons, randomWeapon_3){
	Weapon* weapon = new BCOE_Weapon(3,1);
	string name = "";
	bool one = false, two = false, three = false, four = false;
	for(int i = 0; i < 20; ++i){
		if(weapon->getName() == "99-Cent Store Laptop"){
			one = true;
		}
		if(weapon->getName() == "Mc-Donalds Laptop"){
			two = true;
		}
		if(weapon->getName() == "Walmart Laptop"){
			three = true;
		}
		if(one == true && two == true && three == true){
			four = true;
			delete weapon;
			break;
		}
		delete weapon;
		weapon = new BCOE_Weapon(3,1);
	}
	EXPECT_EQ(four, true);
} 

TEST(Weapons, randomWeapon_4){
	Weapon* weapon = new BCOE_Weapon(4,1);
	string name = "";
	bool one = false, two = false, three = false, four = false;
	for(int i = 0; i < 20; ++i){
		if(weapon->getName() == "99-Cent Store Laptop"){
			one = true;
		}
		if(weapon->getName() == "Mc-Donalds Laptop"){
			two = true;
		}
		if(weapon->getName() == "Walmart Laptop"){
			three = true;
		}
		if(one == true && two == true && three == true){
			four = true;
			delete weapon;
			break;
		}
		delete weapon;
		weapon = new BCOE_Weapon(4,1);
	}
	EXPECT_EQ(four, true);
} 

TEST(Weapons, randomWeapon_5){
	Weapon* weapon = new BCOE_Weapon(5,1);
	string name = "";
	bool one = false, two = false, three = false, four = false;
	for(int i = 0; i < 20; ++i){
		if(weapon->getName() == "Office Depot Laptop"){
			one = true;
		}
		if(weapon->getName() == "Rich Laptop"){
			two = true;
		}
		if(weapon->getName() == "The Dean's Laptop"){
			three = true;
		}
		if(one == true && two == true && three == true){
			four = true;
			delete weapon;
			break;
		}
		delete weapon;
		weapon = new BCOE_Weapon(5,1);
	}
	EXPECT_EQ(four, true);
} 

TEST(Weapons, randomWeapon_6){
	Weapon* weapon = new BCOE_Weapon(6,1);
	string name = "";
	bool one = false, two = false, three = false, four = false;
	for(int i = 0; i < 20; ++i){
		if(weapon->getName() == "Office Depot Laptop"){
			one = true;
		}
		if(weapon->getName() == "Rich Laptop"){
			two = true;
		}
		if(weapon->getName() == "The Dean's Laptop"){
			three = true;
		}
		if(one == true && two == true && three == true){
			four = true;
			delete weapon;
			break;
		}
		delete weapon;
		weapon = new BCOE_Weapon(6,1);
	}
	EXPECT_EQ(four, true);
} 

TEST(Weapons, BCOE_Weapon){
	Entity* player1 = new BCOE_Entity("Dylan",1,1);
	Entity* player2 = new CHASS_Entity("Alex",1,2);
	Weapon* weapon = new BCOE_Weapon(1,1);
	bool check1 = false, check2 = false, check3 = false;
	

	for(int i = 0;i < 10;i++){
		weapon->weaponPassive(player1,player2);
	}
	if(player2->getmaxHP() == player2->getHP()){
		check1 = true;
	}
	player1->setHP(20,2);
	for(int i = 0;i < 10;i++){
		weapon->weaponPassive(player1,player2); 	
	}
	if(player1->getHP() < player1->getmaxHP()){
		check2 = true;	
	}

	if((check1 == true) && (check2 == true)){
		check3 = true;
	} 
	
	delete player1;
	delete player2;
	delete weapon;
	EXPECT_EQ(check3, true);		
}

TEST(Weapons, CHASS_Weapon){
	Entity* player1 = new CHASS_Entity("Dylan",4,1);
	Entity* player2 = new BCOE_Entity("Alex",1,2);
	Weapon* weapon = new CHASS_Weapon(1,2);
	bool check1 = false, check2 = false, check3 = false, check4 = false;
	double hp;
	
	for(int i = 0; i < 10; i++){
		weapon->weaponPassive(player1, player2);
	}
	
	if(player1->getATK() != player1->getmaxATK()){
		check1 = true;
	}
	if(player1->getDEF() != player1->getmaxDEF()){
		check2 = true;
	}
	if(player1->getDEF() != player1->getmaxDEF()){
		check3 = true;
	}
		
	if(check1 == true || check2 == true || check3 == true){
		check4 = true;
	}
	
	delete player1;
	delete player2;
	delete weapon;
	EXPECT_EQ(check4, true);
}

TEST(Weapons, CNAS_Weapon){
	Entity* player1 = new CNAS_Entity("Dylan",4,1);
	Entity* player2 = new BCOE_Entity("Alex",1,2);
	Weapon* weapon = new CNAS_Weapon(1,2);
	bool check = false;
	
	weapon->weaponPassive(player1, player2);
		
	if(player2->getHP() < player2->getmaxHP()){
		check = true;
	}
	
	delete player1;
	delete player2;
	delete weapon;
	EXPECT_EQ(check, true);
}

TEST(Weapons, GSE_Weapon){
	Entity* player1 = new CNAS_Entity("Dylan",4,1);
	Entity* player2 = new BCOE_Entity("Alex",1,2);
	Weapon* weapon = new GSE_Weapon(1,2);
	bool check1 = false, check2 = false, check3 = false;
		
	player1->setMP(100,2);
	
	for(int i = 0; i < 50; i++){
		weapon->weaponPassive(player1, player2);
	}

	if(player1->getMP() == player1->getmaxMP()){
		check1 = true;
	}
	if(player1->getmaxDEF() < player1->getDEF()){
		check2 = true;
	}
	
	if((check1 == true) && (check2 == true)){
		check3 = true;
	}
	delete player1;
	delete player2;
	delete weapon;
	EXPECT_EQ(check3, true);
}

TEST(Weapons, SB_Weapon){
	Entity* player1 = new CNAS_Entity("Dylan",4,1);
	Entity* player2 = new BCOE_Entity("Alex",5,2);
	Weapon* weapon = new SB_Weapon(1,2);
	bool check1 = false, check2 = false, check3 = false;
		
	player1->setGOLD(3000,2);
	
	weapon->weaponPassive(player1,player2);

	if(player2->getHP() == player2->getmaxHP()){
		check1 = true;
	}
	
	player1->setGOLD(500,1);
	weapon->weaponPassive(player1,player2);
	if(player2->getmaxHP() > player2->getHP()){
		check2 = true;
	}
	
	if((check1 == true) && (check2 == true)){
		check3 = true;
	}
	delete player1;
	delete player2;
	delete weapon;
	EXPECT_EQ(check3, true);
}

TEST(Weapons, SM_Weapon){
	Entity* player1 = new CNAS_Entity("Dylan",4,1);
	Entity* player2 = new BCOE_Entity("Alex",5,2);
	Weapon* weapon = new SM_Weapon(1,2);
	bool check = true;
		
	player1->setHP(50,2);
	int num = player1->getHP();
	weapon->weaponPassive(player1, player2);
	if(num < player1->getHP()){
		check = true;
	}
	

	delete player1;
	delete player2;
	delete weapon;
	EXPECT_EQ(check, true);
}

#endif
