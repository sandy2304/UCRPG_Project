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

TEST(Weapons, randomWeapon_1){
	Weapon* weapon = new BCOE_Weapon(1);
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
		weapon = new BCOE_Weapon(1);
	}
	EXPECT_EQ(four, true);
} 

TEST(Weapons, randomWeapon_2){
	Weapon* weapon = new BCOE_Weapon(2);
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
		weapon = new BCOE_Weapon(2);
	}
	EXPECT_EQ(four, true);
} 

TEST(Weapons, randomWeapon_3){
	Weapon* weapon = new BCOE_Weapon(3);
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
		weapon = new BCOE_Weapon(3);
	}
	EXPECT_EQ(four, true);
} 

TEST(Weapons, randomWeapon_4){
	Weapon* weapon = new BCOE_Weapon(4);
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
		weapon = new BCOE_Weapon(4);
	}
	EXPECT_EQ(four, true);
} 

TEST(Weapons, randomWeapon_5){
	Weapon* weapon = new BCOE_Weapon(5);
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
		weapon = new BCOE_Weapon(5);
	}
	EXPECT_EQ(four, true);
} 

TEST(Weapons, randomWeapon_6){
	Weapon* weapon = new BCOE_Weapon(6);
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
		weapon = new BCOE_Weapon(6);
	}
	EXPECT_EQ(four, true);
} 

#endif
