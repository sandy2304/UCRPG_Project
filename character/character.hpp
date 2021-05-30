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
	double maxHP = 0.0, maxMP = 0.0, maxATK = 0.0, maxDEF = 0.0, maxINT = 0.0;
	int Level = 0, Gold = 0;
	Weapon* weapon = nullptr;
	Skill* skill = nullptr;
	vector<string> skillList;
	int HP_potion = 0;
	int MP_potion = 0; 
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
	double getmaxHP(){return maxHP;}
	double getmaxMP(){return maxMP;}
	double getmaxATK(){return maxATK;}
	double getmaxDEF(){return maxDEF;}
	double getmaxINT(){return maxINT;} 
	double getHP(){return HP;}
	double getATK(){return ATK;}
	double getDEF(){return DEF;}
	double getINT(){return INT;}
	double getMP(){return MP;}
	int getHP_Potion(){return HP_potion;}
	int getMP_Potion(){return MP_potion;}
	int getLevel(){return Level;}
	int getGold(){return Gold;}
	//SETTERS
	//    *The mode is for aadding(1) to stats or subtracting(mode >1) to stats
	void reset(){
		HP = maxHP;
		MP = maxMP;
		ATK = maxATK;
		DEF = maxDEF;
		INT = maxINT;	
	}
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
	
	void weaponUpgrade(){
		weapon->levelUp();	
	}
	//------------------------------------
	//SKILL FUNCTIONS--------------------
	bool checkManaCost(){
		if(skill == nullptr){
			return true;
		}else if(skill->manaCheck(this) == true){
			return true;
		}else{
			return false;	
		}	
	}
	void setSkill(Skill* newSkill){
		delete skill;
		skill = newSkill; 
	}
	
	void setSkillNull(){
		delete skill;
		skill = nullptr;
	}
	Skill* getSkill(){return skill;}

	void  printSkill(){
		cout << "==========================================" << endl;
		cout << "(1)Normal Attack" << endl;
		cout << "(2)" << skillList.at(0) << endl;
		cout << "(3)" << skillList.at(1) << endl;
		cout << "(4)" << skillList.at(2) << endl;
		cout << "==========================================" << endl;
	}
	
	string pickSkill(int input){
		if(input >= 1 && input <=4){
			if(input == 1){
				return "Normal";
			}else if(input == 2){
				return skillList.at(0);
			}else if(input == 3){
				return skillList.at(1);
			}else if(input == 4){
				return skillList.at(2);	
			}else{
				cout << "Sumthin went wrong" << endl;
			}
		}	
	}

	//-----------------------------------
	//OTHER FUNCTIONS
	virtual void LevelUp() = 0;
	void showStats(){
		cout << "===================================CHARACTER-DETAILS=====================================" << endl;
		cout << "Name  : " << Name << endl << "Level : " << Level << endl << 
		"School: " << School << endl << "HP : " << HP 
		<< endl << "MP : " << MP << endl << "ATK: " << ATK << endl 
		<<  "DEF: " << DEF << 
		endl << "INT: " << INT << endl << "Bear Bucks: " << Gold << endl;
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
			this->setMP(.05 * this->getINT(),1);
			weapon->weaponPassive(this, enemy);
			
		}else{
			skill->do_Skill(this, enemy);
			this->setMP(.05 * this->getINT(),1);
			weapon->weaponPassive(this, enemy);
		}
		cout << "----------------------------------------" << endl << endl;
	}
	void printBackpack(){
		cout << "----------------Backpack------------------" << endl;
		for(int i = 0; i < HP_potion; ++i){
			cout << "HP Potion" << endl; 
		}
		for(int i = 0; i < MP_potion; ++i){
			cout << "MP Potion" << endl;
		}
		cout << "------------------------------------------" << endl;
	}

	bool usePotion(int potion){
		if(potion == 1){
	 		if(HP_potion > 0){ 
				setHP_Potion(1,2);
				setHP(100,1);
				cout << "Used HP Potion and Gained 100 HP!" << endl;
				return true;
			} 
		}
		else if(potion == 2){
			if(MP_potion > 0){
				setMP_Potion(1,2);
				setMP(20,1);
				cout << "Used MP potion and gained 20 MP!" << endl;
				return true;
			}
		}
		return false;
		
	}

 void setHP_Potion(int number, int mode){
                if(mode == 1){
                        HP_potion  =  HP_potion + number;
                }else{
                        HP_potion = HP_potion - number;
                }
        }

 void setMP_Potion(int number, int mode){
                if(mode == 1){
                        MP_potion  =  MP_potion + number;
                }else{
                        MP_potion = MP_potion - number;
                }
        }

	
};

#endif //Entity
