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
	Weapon* weapon = nullptr;
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
				MP = maxMP;
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
			if(!(tempATK <= 10)){
				ATK = ATK - atk;
			}
		}
	}
	void setDEF(double def, int mode){
		if(mode == 1){
			DEF = DEF + def;
		}else{
			double tempDEF = DEF - def;
			if(!(tempDEF <= 10)){
				DEF = DEF - def;
			}
		}
	}
	void setINT(double inte, int mode){
		if(mode == 1){
			INT = INT + inte;
		}else{
			double tempINT = INT - inte;
			if(!(tempINT <= 10)){
				INT = INT - inte;
			}
		}		
	}
	void setGOLD(double gold, int mode){
		if(mode == 1){
			Gold =  Gold + gold;
		}else{
			double tempGOLD = Gold - gold;
			if(!(tempGOLD <= 10)){
				Gold = Gold - gold;
			}
		}	
	}
	//WEAPON FUNCTIONS--------------------
	void setWeapon(Weapon* wpn){
		delete weapon;
		weapon = wpn;
	}
	Weapon* getWeapon(){return weapon;}
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
		weapon->weaponDetails();
		cout << "=========================================================================================" << endl;
	}
	void showMPHP(){
		int hp = round((HP/maxHP) * 10 * 2);
		int mp = round((MP/maxMP) * 10 * 2);
		int counter;
		cout << "===================" << Name << "==================" << endl;	
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
			if(i == 0){
				cout << "|| " << round(HP) << "/" << maxHP  << endl;
			}else{
				cout << "|| " << round(MP) << "/" << maxMP  << endl;
			}		
		}
		cout << "==========================================" << endl;
	}
	void attack(Entity* enemy){
		cout << "----------------------------------------" << endl;
		if(skill == nullptr){
			enemy->setHP((ATK * .75)-(enemy->getDEF() * .25) , 2);
			cout << Name << " attacked and dealt " << (ATK * .75) << " damage" << endl;
			this->setMP(.25 * this->getINT(),1);
			weapon->weaponPassive(this, enemy);
			
		}else{
			skill->do_Skill(this, enemy);
			this->setMP(.25 * this->getINT(),1);
			weapon->weaponPassive(this, enemy);
		}
		cout << "----------------------------------------" << endl << endl;
	}
};

#endif //Entity
