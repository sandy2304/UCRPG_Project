#ifndef __ENTITY__
#define __ENTITY__

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "../weapons/weapon.hpp"
#include "../skills/Skill.hpp"

using namespace std;

class Entity{
    protected:
	string Name = "", School = "";
	double HP = 0.0, ATK = 0.0, DEF = 0.0, INT = 0.0, MP = 0.0;
	double maxHP = 0.0, maxMP = 0.0;
	int Level = 0, Gold = 0;
	Weapon* charWeapon = nullptr;
	Skill* skill = nullptr;
	vector<string> skillList;
    public:
	Entity(string name, string school, int lvl, int type){
		Name = name;
		School = school;
		Level = lvl;
	}
	virtual ~Entity(){};	
	
	//GETTERS
 	string getName(){return Name;}
	string getSchool(){return School;}
	double getHP(){return HP;}
	double getmaxHP(){return maxHP;}
	double getmaxMP(){return maxMP;}
	double getATK(){return ATK;}
	double getDEF(){return DEF;}
	double getINT(){return INT;}
	double getMP(){return MP;}
	int getLevel(){return Level;}
	int getGold(){return Gold;}
	//SETTERS
	//    *The mode is for aadding(1) to stats or subtracting(mode >1) to stats
	void setHP(double hp, int mode){
		if(mode == 1){
			HP = HP + hp;
			if(HP >= maxHP){
				HP = maxHP;
			}
		}else{
			HP = HP  - hp;
			if(HP <= 0.0){
				HP = 0.0;
			}
		}
	}
	void setMP(double mp, int mode){
		if(mode == 1){
			MP = MP + mp;
			if(MP >= maxMP){
				mp = maxMP;
			}
		}else{
			MP = MP - mp;
			if(MP <= 0.0){
				MP = 0.0;
			}
		}
	}
	void setATK(double atk, int mode){
		if(mode == 1){
			ATK = ATK + atk;
		}else{
			double tempATK = ATK - atk;
			if(!(tempATK <= 50)){
				ATK = ATK - atk;
			}
		}
	}
	void setDEF(double def, int mode){
		if(mode == 1){
			DEF = DEF + def;
		}else{
			double tempDEF = DEF - def;
			if(!(tempDEF <= 50)){
				DEF = DEF - def;
			}
		}
	}
	void setINT(double inte, int mode){
		if(mode == 1){
			INT = INT + inte;
		}else{
			double tempINT = INT - inte;
			if(!(tempINT <= 50)){
				INT = INT - inte;
			}
		}		
	}
	void setGOLD(double gold, int mode){
		if(mode == 1){
			Gold =  Gold + gold;
		}else{
			double tempGOLD = Gold - gold;
			if(!(tempGOLD <= 50)){
				Gold = Gold - gold;
			}
		}	
	}
	//WEAPON FUNCTIONS--------------------
	void setWeapon(Weapon* wpn){
		delete charWeapon;
		charWeapon = wpn;
	}
	Weapon* getWeapon(){return charWeapon;}
	//------------------------------------
	//SKILL FUNCTIONS--------------------
	void setSkill(Skill* newSkill){
		delete skill;
		skill = newSkill; 
	}
	Skill* getSkill(){return skill;}
	//-----------------------------------
	//OTHER FUNCTIONS
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
	void showMPHP(){
		int hp = round((HP/maxHP) * 10 * 2);
		int mp = round((MP/maxMP) * 10 * 2);
		int counter;
		
		for(int i = 0; i < 2; i++){
			if(i == 0){
				cout << "HP: ||";
				counter = hp;
			}else{
				cout << "MP: ||";
				counter = mp;
			}
			for(int j = 0; j < counter; j++){
				cout << "O";
			}
			for(int k = 0; k < (20 - counter);k++){
				cout << "-";
			}
			cout << "||" << endl;		
		}	
	}
	virtual void attack(Entity* enemy) const = 0;
};

#endif //Entity
