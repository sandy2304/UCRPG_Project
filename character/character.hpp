#ifndef __Entity__
#define __Entity__

#include <iostream>
#include <string>
#include <vector>
#include "../weapons/weapon.hpp"

using namespace std;

class Entity{
    protected:
	string Name = "", School = "";
	double HP = 0.0, ATK = 0.0, DEF = 0.0, INT = 0.0, MP = 0.0;
	int Level = 0, Gold = 0;
	Weapon* charWeapon = nullptr;
    public:
	Entity(string name, string school, int lvl, int type){
		Name = name;
		School = school;
		Level = lvl;
	}
	virtual ~Entity(){};	

 	string getName(){return Name;}
	string getSchool(){return School;}
	double getHP(){return HP;}
	double getATK(){return ATK;}
	double getDEF(){return DEF;}
	double getINT(){return INT;}
	double getMP(){return MP;}
	int getLevel(){return Level;}
	int getGold(){return Gold;}
	
	void setWeapon(Weapon* wpn){charWeapon = wpn;}
	void getDamage(double damage){
		HP = HP  - damage;
		if(HP <= 0.0){
			HP = 0.0;
		}
	}
	void showStats(){
		cout << "===================================CHARACTER-DETAILS=====================================" << endl;
		cout << "Name  : " << Name << endl << "Level : " << Level << endl << 
		"School: " << School << endl << "HP : " << HP 
		<< endl << "MP : " << MP << endl << "ATK: " << ATK << endl 
		<<  "DEF: " << DEF << 
		endl << "INT: " << INT << endl;
		cout << "----------------------------------------WEAPON-------------------------------------------" << endl;
		charWeapon->weaponDetails();
		cout << "=========================================================================================" << endl;
	}

	virtual void attack(Entity*) const = 0;
};

#endif //Entity
