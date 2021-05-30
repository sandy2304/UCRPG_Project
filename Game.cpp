#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include "Character_Factory/Character_Factory.hpp"
#include "save/save.hpp"
#include <string.h>
#include "skills/Skill.hpp"
#include "skills/BCOE_Skill.hpp"
#include "skills/CHASS_Skill.hpp"
#include "skills/CNAS_Skill.hpp"
#include "skills/GSE_Skill.hpp"
#include "skills/SB_Skill.hpp"
#include "skills/SM_Skill.hpp"

using namespace std;

void worldHubMenu(int&);
void school_Challenge(Entity*, Entity_Factory*);
void BCOE_Challenge(Entity*, Entity_Factory*);
void CHASS_Challenge(Entity*, Entity_Factory*);
void CNAS_Challenge(Entity*, Entity_Factory*);
void GSE_Challenge(Entity*, Entity_Factory*);
void SB_Challenge(Entity*, Entity_Factory*);
void SM_Challenge(Entity*, Entity_Factory*); 
void Battle(Entity*,Entity*, int, int);
void BattleMenu(Entity*,Entity*, int&,int&, int); 
int inputCheck(int,int);
void skillSet(Entity*, string);
void PrintEnemy(int);
void shop(Entity* );
bool buy(Entity* );
bool CheckPrice(int, Entity*);
void EnemySkill(Entity*,int);
void loadGame();
void playerWin(Entity*,int);
void factorySet(Entity_Factory*, int);


int main() {
	string line;
	ifstream myfile;
	int welcomeInput;
	string userName;
	int schoolInput;
	Entity_Factory* CharFactory = nullptr;
	Entity* player = nullptr;
	cout << "=========================================================================================" << endl;
	cout << "Welcome to UCRPG! Please select an option and press enter!" << endl;
	cout << "1 - Start game" << endl;
	cout << "2 - Load game" << endl;
	cout << "3 - Quit game" << endl; 
	cout << "=========================================================================================" << endl;
	cin >> welcomeInput;

	while ((welcomeInput <= 0) || (welcomeInput >= 4)) {
		cout << "ERROR : INVALID INPUT! Please try again!";
		cin >> welcomeInput;
	}

	if(welcomeInput == 1){
	myfile.open("gamedata.txt");
	if(myfile.peek() == std::ifstream::traits_type::eof()){
	ResetGame();
	}
	else{
	cout << "WARNING!! This would delete your current save!" << endl;
	cout << "Enter \"accept\" to comfirm. Enter anything else to cancel." << endl;
	string confirm;
	cin >> confirm;
	if(confirm == "accept"){
	cout << "Resetted the game" << endl;
	ResetGame();
	}
	else{
	return 0;
	}
	}
	}

	if(welcomeInput == 2){
	string line;
	string name;
	string school;
	int gold;
	int level;
	int HP_Potion;
	int MP_Potion;
	int weaponlevel;
	vector<string> Beatlist;
	myfile.open("gamedata.txt");
	if(myfile.peek() == std::ifstream::traits_type::eof()){
        ResetGame();
	}
	else{
	if(myfile.is_open()){
	while(getline(myfile,line)){
	if(line == "Name"){
	getline(myfile,line);
	if(line == "\n"){
	cout << "An error has occurred, please reset the game" << endl;
	return 0;
	}
	else{
	name = line;
	}
	}
	else if(line == "School"){
	getline(myfile,line);
	school = line;
	}
	else if(line == "GOLD"){
	getline(myfile,line);
	gold = stod(line);
	}
	else if(line == "Level"){
	getline(myfile,line);
	level = stod(line);
	}
	else if(line == "HP_Potion"){
	getline(myfile,line);
	HP_Potion = stod(line);
	}
	else if(line == "MP_Potion"){
	getline(myfile,line);
	MP_Potion = stod(line);
	}
	else if(line == "Weapon"){
	getline(myfile,line);
	weaponlevel = stod(line);
	}
	else if(line == "Schools_Beaten"){
	while(!myfile.eof()){
	getline(myfile,line);
	Beatlist.push_back(line);
	}
	}
	}
	}
	
	if(school == "BCOE"){
	CharFactory = new BCOE_Factory();
	player = CharFactory->createEntity(name,level,1);	
	}
	else if(school == "CHASS"){
	CharFactory = new CHASS_Factory();
        player = CharFactory->createEntity(name,level,1);
	}
	else if(school == "CNAS"){
	CharFactory = new CNAS_Factory();
        player = CharFactory->createEntity(name,level,1);
	}
	else if(school == "GSE"){
	CharFactory = new GSE_Factory();
        player = CharFactory->createEntity(name,level,1);
	}
	else if(school == "SB"){
	CharFactory = new SB_Factory();
        player = CharFactory->createEntity(name,level,1);
	}
	else if(school == "SM"){
	CharFactory = new SM_Factory();
        player = CharFactory->createEntity(name,level,1);
	}
	else{
	cout << "An error has occured : No school detected" << endl; 
	}
	for(int i = 0; i < Beatlist.size(); ++i){
	player->addSchoolsBeaten(Beatlist.at(i));
	}
	player->setGOLD(player->getGold(),2);
	player->setGOLD(gold,1);
	player->setHP_Potion(HP_Potion,1);
	player->setMP_Potion(MP_Potion,1);
	for(int i = 1; i < weaponlevel; ++i){
	player->weaponUpgrade();
	}
	}	
}

	if (welcomeInput == 3) {
		return 0;
	}
	else if(welcomeInput == 1) {
		cout << "=========================================================================================" << endl;
		cout << "Hello! What is your name? (10 characters max)" << endl;
		cout << "=========================================================================================" << endl;
		cin.ignore();
		getline(cin, userName);
		cout << "=========================================================================================" << endl;	
		cout << "Greetings " << userName << "! What school would you like to pursue?" << endl;
		cout << "1 - Marlan and Rosemary Bourns College of Engineering (BCOE)" << endl;
		cout << "2 - College of Humanities, Arts, and Social Sciences (CHASS)" << endl;
		cout << "3 - College of Natural and Agricultural Sciences (CNAS)" << endl;
		cout << "4 - Graduate School of Education (GSE)" << endl;
		cout << "5 - School of Business (SB)" << endl;
		cout << "6 - School of Medicine (SM)" << endl;
		cout << "=========================================================================================" << endl;
		schoolInput = inputCheck(1,6);
		//====================
		if(schoolInput == 1){
			CharFactory = new BCOE_Factory();
			player = CharFactory->createEntity(userName, 1, 1);
		}
		else if (schoolInput == 2) {
			CharFactory = new CHASS_Factory();
			player = CharFactory->createEntity(userName, 1, 1);
		}
		else if (schoolInput == 3) {
			CharFactory = new CNAS_Factory();
			player = CharFactory->createEntity(userName, 1, 1);
		}
		else if (schoolInput == 4) {
			CharFactory = new GSE_Factory();
			player = CharFactory->createEntity(userName, 1, 1);
		}
		else if (schoolInput == 5) {
			CharFactory = new SB_Factory();
			player = CharFactory->createEntity(userName, 1, 1);
		}
		else if (schoolInput == 6) {
			CharFactory = new SM_Factory();
			player = CharFactory->createEntity(userName, 1, 1);
		}
		SaveGame(player);	
	}
	
	//THIS IS WHERE THE GAME HAPPENS
	int userInput;
	while(true){
		worldHubMenu(userInput);
		if(userInput == 1){
			shop(player);
		}else if(userInput == 2){
			player->printBackpack();
		}else if(userInput == 3){
			player->showStats();
		}else if(userInput == 4){
			school_Challenge(player, CharFactory); 
		}else if(userInput == 5){
			cout << "Saving game!" << endl;
			SaveGame(player);
		}else if(userInput == 6){
			break;
		}
	}
	
	return 0;	
}
//******************************************************************************************************************************************************
//================================MENUS========================================
void worldHubMenu(int& input){
	bool cond = false;
	while(cond == false){
		cout << "======================================WORLDHUB-MENU======================================" << endl;
		cout << "Choose an action and press enter" << endl;
		cout << "1 - Go to Scotty's Convenience Store" << endl;
		cout << "2 - Access Inventory" << endl;
		cout << "3 - See Character Details" << endl;
		cout << "4 - Select a school to challenge" << endl;
		cout << "5 - Save Game" << endl;
		cout << "6 - Quit game" << endl;
		cout << "=========================================================================================" << endl;
		cin >> input;
		if((input <= 0) || (input >= 7)){
			cout << "Invalid Input! Choose again" << endl;
		}else{
			cond = true;
		}
			
	}
}

//=======================================BATTLE STUFF=======================================
void school_Challenge(Entity* player,Entity_Factory* factory){
	int userInput;
	cout << "WORLD Level " <<  player->getLevel() << " " << endl;	
	cout << "Choose a school to fight: " << endl;
	cout << "(1) - Challenge Marlan and Rosemary Bourns College of Engineering(BCOE)";
	if(player->checkifBeaten("BCOE")){
		cout << " X ";
	}
	cout << endl;
	cout << "(2) - Challenge College of Humanities, Arts, and Social Sciences(CHASS)";
  	if(player->checkifBeaten("CHASS")){
        	cout << " X ";
        }
        cout << endl;

	cout << "(3) - Challenge College of Natuiral and Agricultural Sciences(CNAS)";
  	if(player->checkifBeaten("CNAS")){
        	cout << " X ";
        }
        cout << endl;

	cout << "(4) - Challenge Graduate School of Education(GSE)";
  	if(player->checkifBeaten("GSE")){
        	cout << " X ";
        }
        cout << endl;

	cout << "(5) - Challenge School of Business(SB)";
  	if(player->checkifBeaten("SB")){
        	cout << " X ";
        }
        cout << endl;

	cout << "(6) - Challenge School of Medicine(SM)";
  	if(player->checkifBeaten("SM")){
        	cout << " X ";
        }
        cout << endl;
	cout << "Enter 7 to go back to World Hub";
        cout << endl;

	userInput = inputCheck(1,7);
	if(userInput == 1){
		factorySet(factory,1);
		BCOE_Challenge(player, factory);		
	}else if(userInput == 2){
		factorySet(factory,2);
		CHASS_Challenge(player, factory);
	}else if(userInput == 3){
		factorySet(factory,3);
		CNAS_Challenge(player, factory);
	}else if(userInput == 4){
		factorySet(factory,4);
		GSE_Challenge(player, factory);
	}else if(userInput == 5){
		factorySet(factory,5);
		SB_Challenge(player,factory);
	}else if(userInput == 6){
		factorySet(factory,6);
		SM_Challenge(player,factory);
	}			
}

void BCOE_Challenge(Entity* player, Entity_Factory* Factory){
     cout << "Welcome to the BCOE Challenge!" << endl;
     cin.ignore();  
     cin.get();
     cout << "First Opponent: The Debugger" << endl; 
     Entity* opponent = Factory->createEntity("the debugger",player->getLevel(),1);
     Battle(player,opponent,2, 1);
     if(player->getHP() == 0){
	delete opponent;
	player->reset();
	return;	
     }
     playerWin(player, 100);
     cout << "Second Opponent: The Sabotager" << endl;
     delete opponent;
     opponent = Factory->createEntity("The Sabotager",player->getLevel(),1);
     Battle(player, opponent,3, 2);
     if(player->getHP() == 0){
	delete opponent;
	player->reset();
	return;	
     }
     playerWin(player,150);
     cout << "Final Boss: Electro" << endl;
     delete opponent;
     opponent = Factory->createEntity("Electro", player->getLevel(),2);
     Battle(player, opponent,4,3);
     if(player->getHP() == 0){
   	delete opponent;
	player->reset();
	return;
     }
     playerWin(player, 500);
     cout << "You've beaten Marlan and Rosemary Bourns College of Engineering!" << endl;
     cin.ignore(); 
     cin.get();
    
     //LEVEL UP
     if(player->checkifBeaten("BCOE") == false){
     	cout << "Leveled up!" << endl;
     	player->LevelUp();
     	player->addSchoolsBeaten("BCOE");
     }
     SaveGame(player);
}	

void CHASS_Challenge(Entity* player, Entity_Factory* Factory){
     cout << "Welcome to the CHASS  Challenge!" << endl;
     cin.ignore();  
     cin.get();
     cout << "First Opponent: The Thinker" << endl; 
     Entity* opponent = Factory->createEntity("Thinker",player->getLevel(),1);
     Battle(player,opponent,2, 5);
     if(player->getHP() == 0){
	delete opponent;
	player->reset();
	return;	
     }
     playerWin(player, 100);
     cout << "Second Opponent: The Breakdancer" << endl;
     delete opponent;
     opponent = Factory->createEntity("Breakdancer",player->getLevel(),1);
     Battle(player, opponent,3, 5);
     if(player->getHP() == 0){
	delete opponent;
	player->reset();
	return;	
     }
     playerWin(player,150);
     cout << "Final Boss: Big Brain Boy" << endl;
     delete opponent;
     opponent = Factory->createEntity("Big Brain Boy", player->getLevel(),2);
     Battle(player, opponent,4,5);
     if(player->getHP() == 0){
   	delete opponent;
	player->reset();
	return;
     }
     playerWin(player, 500);
     cout << "You've beaten the College of Humanities, Arts, and Social Sciences!" << endl;
     cin.ignore(); 
     cin.get();
    
     //LEVEL UP
     if(player->checkifBeaten("CHASS") == false){
     	cout << "Leveled up!" << endl;
     	player->LevelUp();
     	player->addSchoolsBeaten("CHASS");
     }
     SaveGame(player);
}

void CNAS_Challenge(Entity* player, Entity_Factory* Factory){
     cout << "Welcome to the CNAS Challenge!" << endl;
     cin.ignore();
     cin.get();
     cout << "First Opponent: Poison Skull" << endl;
     Entity* lightbulb = Factory->createEntity("Posion Skull",player->getLevel(),1);
     Battle(player,lightbulb,2, 6);
     if(player->getHP() == 0){
     player->reset();
     return;
     }
     cout << "Earned 100 Bear-Bucks!" << endl;
     cin.ignore();
     cin.get();
     player->setGOLD(100,1);
     player->reset();
     cin.ignore(); 
     cin.get();
     cout << "Second Opponent: Bombie" << endl;
     Entity* bomb = Factory->createEntity("Bombie",player->getLevel(),1);
     Battle(player,bomb,2,8);
      if(player->getHP() == 0){
     player->reset();
     return;
     }
     cout << "Earned 150 Bear-Bucks!" << endl;
     player->setGOLD(150,1);
     cin.ignore();
     cin.get();
     player->reset();
     cin.ignore();
     cin.get();
     cout << "Final Boss: Newton's Apple" << endl;
     Entity* apple = Factory->createEntity("Newton's Apple",player->getLevel(),2);
     Battle(player,apple,2,7);
	 if(player->getHP() == 0){ 
     player->reset();
     return;
     }
     player->reset();
     cout << "You beat the CNAS Challenge!" << endl;
     cin.ignore();
     cin.get();
     cout << "You earend 500 BB's!" << endl;
     player->setGOLD(500,1);
     if(player->checkifBeaten("CHAS") == false){
     	cout << "Leveled up!" << endl;
     	player->LevelUp();
     	player->addSchoolsBeaten("CNAS");
     }
     SaveGame(player);
}


void GSE_Challenge(Entity* player, Entity_Factory* Factory){
     cout << "Welcome to the GSE Challenge!" << endl;
     cin.ignore();
     cin.get();
     cout << "First Opponent: Ruler" << endl;
     Entity* ruler = Factory->createEntity("Ruler",player->getLevel(),1);
     Battle(player,ruler,2, 9);
      if(player->getHP() == 0){
     player->reset();
     return;
     }
     cout << "Won 120 BBs!" << endl;
          cin.ignore();
	  cin.get();
     player->setGOLD(120,1);
     player->reset();
     cout << "Second Opponent: Evil Toaster" << endl;
     Entity* pop = Factory->createEntity("Evil Toaster",player->getLevel(),1);
     Battle(player,pop,2,10);
     if(player->getHP() == 0){
     player->reset();
     return;
     }
     cout << "Won 300 BBs!" << endl;
     cin.ignore();
     cin.get();
     player->setGOLD(300,1);
     player->reset();
     cout << "Final Boss: Crocker" << endl;
     Entity* crocker = Factory->createEntity("Denzel Crocker",player->getLevel(),2);
     Battle(player,crocker,2,11);
      if(player->getHP() == 0){
     player->reset();
     return;
     }
     cout << "Congratulations you beat the GSE Challenge!" << endl;
     cin.ignore();
     cin.get();
     cout << "You earned 700 BB's!" << endl;
     player->setGOLD(700,1);
     player->reset();
     if(player->checkifBeaten("GSE") == false){
     	cout << "Leveled up!" << endl;
	player->LevelUp();
	player->addSchoolsBeaten("GSE");
     }
     SaveGame(player);
}

void SB_Challenge(Entity* player, Entity_Factory* Factory){
     cout << "Welcome to the SB Challenge!" << endl;
     cin.ignore();  
     cin.get();
     cout << "First Opponent: Brick-Case" << endl; 
     Entity* opponent = Factory->createEntity("Brick-Case",player->getLevel(),1);
     Battle(player,opponent,2, 1);
     if(player->getHP() == 0){
	delete opponent;
	player->reset();
	return;	
     }
     playerWin(player, 100);
     cout << "Second Opponent: Vlad Jr" << endl;
     delete opponent;
     opponent = Factory->createEntity("Vlad Jr",player->getLevel(),1);
     Battle(player, opponent,3, 2);
     if(player->getHP() == 0){
	delete opponent;
	player->reset();
	return;	
     }
     playerWin(player,150);
     cout << "Final Boss: Dylan's Doge" << endl;
     delete opponent;
     opponent = Factory->createEntity("Dylan's Doge", player->getLevel(),2);
     Battle(player, opponent,4,3);
     if(player->getHP() == 0){
   	delete opponent;
	player->reset();
	return;
     }
     playerWin(player, 500);
     cout << "You've beaten the School of Business!" << endl;
     cin.ignore(); 
     cin.get();
    
     //LEVEL UP
     if(player->checkifBeaten("SB") == false){
     	cout << "Leveled up!" << endl;
     	player->LevelUp();
     	player->addSchoolsBeaten("SB");
     }
     SaveGame(player);
}

void SM_Challenge(Entity* player, Entity_Factory* Factory){
     cout << "Welcome to the SM Challenge!" << endl;
     cin.ignore();  
     cin.get();
     cout << "First Opponent: ChugJug" << endl; 
     Entity* opponent = Factory->createEntity("ChugJug",player->getLevel(),1);
     Battle(player,opponent,2, 1);
     if(player->getHP() == 0){
	delete opponent;
	player->reset();
	return;	
     }
     playerWin(player, 100);
     cout << "Second Opponent: Nurse Joy" << endl;
     delete opponent;
     opponent = Factory->createEntity("Nurse Joy",player->getLevel(),1);
     Battle(player, opponent,3, 2);
     if(player->getHP() == 0){
	delete opponent;
	player->reset();
	return;	
     }
     playerWin(player,150);
     cout << "Final Boss: Doctor Cringe" << endl;
     delete opponent;
     opponent = Factory->createEntity("Doctor Cringe", player->getLevel(),2);
     Battle(player, opponent,4,3);
     if(player->getHP() == 0){
   	delete opponent;
	player->reset();
	return;
     }
     playerWin(player, 500);
     cout << "You've beaten the School of Medicine!" << endl;
     cin.ignore(); 
     cin.get();
    
     //LEVEL UP
     if(player->checkifBeaten("SM") == false){
     	cout << "Leveled up!" << endl;
     	player->LevelUp();
     	player->addSchoolsBeaten("SM");
     }
     SaveGame(player);
}

void playerWin(Entity* player, int gold){
	cout << "Won " << gold  <<  " Bear-Bucks!" << endl;
	cin.ignore();
	cin.get();
	player->setGOLD(gold, 1);
	player->reset();
	cin.ignore();
	cin.get();
}

void Battle(Entity* player, Entity* enemy, int skillRange, int pic){
  int userInput;
  int Potion;
  bool use_potion = false;
  while(player->getHP() > 0 && enemy->getHP() > 0){
	BattleMenu(player, enemy, userInput, Potion, pic);
       	EnemySkill(enemy, skillRange);	
  	if(player->getINT() > enemy->getINT()){
  		if(userInput == 1){
			player->attack(enemy);
			if(enemy->getHP() <= 0){
				cout << "You beat " << enemy->getName() <<  endl;
				break;
			}
			enemy->attack(player);
			if(player->getHP() <= 0){
				cout << "You lost to " << enemy->getName() << endl;
				break;
			}
		}else{
			use_potion = player->usePotion(Potion);
			enemy->attack(player);
			if(player->getHP() <= 0){
				cout << "You lost to " << enemy->getName() << endl;
                        	break;
			}
  		}
	}	
  	else{	
		enemy->attack(player);
		if(player->getHP() <= 0){
			cout << "You lost to " << enemy->getName() << endl;
			break;
		}
		if(userInput == 1){
			player->attack(enemy);
			if(enemy->getHP() <= 0){
				cout << "You beat the " << enemy->getName() << endl;
				break;
			}
		}else{
			use_potion = player->usePotion(Potion);
		}
		
  	} 
  	
  }
}

void EnemySkill(Entity* enemy, int range){
	bool skillCheck = false;
	int random;
	srand(time(NULL)+rand());
	while(skillCheck == false){
		random = (rand() % range) + 1;
		skillSet(enemy,enemy->pickSkill(random));
		skillCheck = enemy->checkManaCost();
	}		
}

void BattleMenu(Entity* player,Entity* enemy ,int& option,int& potion, int picture){
	int choice;
	int choice2; 
	int choice3;
	bool skillCheck = false, loop1 = false, loop2 = false; 
	while(loop1 == false){
		PrintEnemy(picture);
		enemy->showMPHP();
       		player->showMPHP();
       		cout << "         (1)Fight         (2)Items        " << endl;
       		cout << "==========================================" << endl;
		choice = inputCheck(1,2);
		option = choice;
		if(choice == 1){
			player->printSkill();
			cout << "Enter 5 to go back" << endl;
			loop2 = false;
			while(loop2 == false){
				choice2 = inputCheck(1,5);
				if(choice2 < 5){
					skillSet(player, player->pickSkill(choice2));
					skillCheck = player->checkManaCost();
					if(skillCheck == true){
						loop1 = true;
						loop2 = true;
					}else{
						cout << "Not enough mana! " << endl;
					}
				}else{
					loop2 = true;
				}
			}
		}else if(choice == 2){
			player->printBackpack();
			cout << "     (1)HP Potion         (2)MP Potion    " << endl;
			cout << "==========================================" << endl;
			cout << "Enter 3 to go back" << endl;
			loop2 = false;
			while(loop2 == false){
				choice3 = inputCheck(1,3);
				if(choice3 < 3){
					potion = choice3;
					if(choice3 == 1){
						if(player->getHP_Potion() != 0){
							loop1 = true;
							loop2 = true;
						}else{
							cout << "You have no HP potions!" << endl;
						}
					}else if(choice3 == 2){
						if(player->getMP_Potion()!= 0){
							loop1 = true;
							loop2 = true;
						}else{
							cout << "You have no MP potions!" << endl;
						}	
					}
				}else{
					loop2 = true;
				}
			}
		}	      
	}
}

//=============================OTHER===================================
int inputCheck(int rangeA, int rangeB){
	int num;
	cout << "Enter a number between " << rangeA << " and " << rangeB << endl;
	cin >> num;
	while(!((num >= rangeA) && (num <= rangeB))){
		cout << "Please enter a number from " << rangeA << " to " << rangeB << endl;
		cin >> num;	
	}
	return num;
}
void factorySet(Entity_Factory* fac, int num){
	delete fac;
	if(num == 1){
		fac = new BCOE_Factory();	
	}else if(num == 2){
		fac = new CHASS_Factory();	
	}else if(num == 3){
		fac = new CNAS_Factory();	
	}else if(num == 4){
		fac = new GSE_Factory();
	}else if(num == 5){
		fac = new SB_Factory();
	}else if(num == 6){
		fac = new SM_Factory();
	}		
}

void skillSet(Entity* ent, string skillName){
	if(skillName == "Normal"){
		ent->setSkillNull();
	}else if(skillName == "Debug"){
		Skill* newSkill = new Debug();
		ent->setSkill(newSkill);
	}else if(skillName == "Sabotage"){
		Skill* newSkill = new Sabotage();
		ent->setSkill(newSkill);
	}else if(skillName == "Faulty_Circuit"){
		Skill* newSkill = new Faulty_Circuit();
		ent->setSkill(newSkill);
	}else if(skillName == "Think"){
		Skill* newSkill = new Think();
		ent->setSkill(newSkill);
	}else if(skillName == "Breakdance"){
		Skill* newSkill = new Breakdance();
		ent->setSkill(newSkill);	
	}else if(skillName == "Reverse_Psychology"){
		Skill* newSkill = new Reverse_Psychology();
		ent->setSkill(newSkill);
	}else if(skillName == "Ruler"){
		Skill* newSkill = new Ruler();
		ent->setSkill(newSkill);
	}else if(skillName == "Pop_Quiz"){
		Skill* newSkill = new Pop_Quiz();
		ent->setSkill(newSkill);
	}else if(skillName == "F-Hammer"){
		Skill* newSkill = new F_Hammer();
		ent->setSkill(newSkill);
	}else if(skillName == "Chemical_Splash"){
		Skill* newSkill = new Chemical_Splash();
		ent->setSkill(newSkill);
	}else if(skillName == "Explosion"){
		Skill* newSkill = new Explosion();
		ent->setSkill(newSkill);
	}else if(skillName == "Gravity"){
		Skill* newSkill = new Gravity();
		ent->setSkill(newSkill);
	}else if(skillName == "Briefcase"){
		Skill* newSkill = new Briefcase();
		ent->setSkill(newSkill);
	}else if(skillName == "Robinhood"){
		Skill* newSkill = new Robinhood();
		ent->setSkill(newSkill);
	}else if(skillName == "Stock-Market-Crash"){
		Skill* newSkill = new Robinhood();
		ent->setSkill(newSkill);
	}else if(skillName == "Medkit"){
		Skill* newSkill = new MedKit();
		ent->setSkill(newSkill);
	}else if(skillName == "Syringe"){
		Skill* newSkill = new Syringe();
		ent->setSkill(newSkill);	
	}else if(skillName == "Incision"){
		Skill* newSkill = new Incision();
		ent->setSkill(newSkill);
	}
	
	else{
		ent->setSkillNull();	
		cout << skillName << " does not exist" << endl;
	}
}
//==============================IMAGES=============================
void PrintEnemy(int i){
 if(i == 1){
cout << "MMMMMMMMMMMMMMWXNMMMMMMMMNXWMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMWk,,xXWWWWXx,,kWMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMXc  .,,,,. .cXMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMXd.          .dXMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMXc              cXMMMMMMMMMMMM" << endl;
cout << "MMMKddKWMMMMO'..............'OMMMMWKddKMMM" << endl;
cout << "MMM0:..lO000kdoddddk00kddooodk000Ol..:KMMM" << endl;
cout << "MMMMNk:''..       .lKKl.       .''':kNMMMM" << endl;
cout << "MMMMMMWXk,         :KK:         c0NWMMMMMM" << endl;
cout << "MMMMMMMK;          :KK:          lNMMMMMMM" << endl;
cout << "MMMMMMNc           :KK:          .oWMMMMMM" << endl;
cout << "MKdlll:.           :KK:           .:llldKM" << endl;
cout << "M0c,,,.            :KK:            .,,,c0M" << endl;
cout << "MMWWWWx.           :KK:           .kWWWWMM" << endl;
cout << "MMMMMMX;           :KK:           :XMMMMMM" << endl;
cout << "MMMMMW0:           :00:          .c0WMMMMM" << endl;
cout << "MMMW0c....         :KK:         ....c0WMMM" << endl;
cout << "MMNd..:kK0d'       :0K:      .;xKKk:..dWMM" << endl;
cout << "MMW0xOWMMMMXkc'.   :0K:   .;o0NMMMMWOd0WMM" << endl;
cout << "MMMMMMMMMMMMMMNKkdoONNOoxOXWMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
 }
else if (i == 2){
cout << "WWWWWWWWWK0XWWWWWWWWWWWWWWWWWWX0KWWWWWWWWW" << endl;
cout << "WWWWWWWWd:::OWWWWWWWWWWWWWWWWO:::xWWWWWWWW" << endl;
cout << "WWWWWWWWk:,c0WWWWX0OOOO0XWWWW0c,:kWWWWWWWW" << endl;
cout << "WWWWWWWWWd'oOOOxc'......,cxOOOo'dWWWWWWWWW" << endl;
cout << "WWWWWWWWW0ooo;.            .;oooKWWWWWWWWW" << endl;
cout << "WWWWWWN0k0NMK; 'c,.    .;c. ;KMN0k0NWWWWWW" << endl;
cout << "WWWWWWk,;,:o;. 'O0dc;;cdKx. .;o:,;,kWWWWWW" << endl;
cout << "WWWWWWKdlox0o. .lkk0KK0kk:. .o0xoloKWWWWWW" << endl;
cout << "WWWWWWWWWNK0O:. ..;,'',;.. .:O0KNWWWWWWWWW" << endl;
cout << "WWWWWWWWWk;coo;..:;.co,;c..;ooc;kWWWWWWWWW" << endl;
cout << "WWWWWWWWXc.dNWO'.xd;kKldk.'OWNd.cXWWWWWWWW" << endl;
cout << "WWWWWWWWo',,kWN0kXKOXN0KXO0NWk','oWWWWWWWW" << endl;
cout << "WWWWWWWWKdoxXWWWWWWWWWWWWWWWWXxod0WWWWWWWW" << endl;
cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
}
else if (i == 3){
cout << "l;:cccccccccccccccccccccccccccccccccccc:;l" << endl;
cout << ".oXXXXXXXXXXXXXXXX0xddx0XXXXXXXXXXXXXXXKo." << endl;
cout << ".kXXXXXXXXXXXXXX0o;:cc:;o0XXXXXXXXXXXXXXx." << endl;
cout << ".kXXXXXXXXXXXXXOc,oKXXKo,:OXXXXXXXXXXXXXx." << endl;
cout << ".xXXXXXXXXXXXXO:,xKXXXXKx,:OXXXXXXXXXXXXx." << endl;
cout << ".xXXXXXXXXXXXk;;kXXXXXXXXk;;kXXXXXXXXXXXx." << endl;
cout << ".xXXXXXXXXXKx,:OXKxccclkXXO:,xKXXXXXXXXXx." << endl;
cout << ".xXXXXXXXXKo,cOXXO,   .xXXX0c,oKXXXXXXXXk." << endl;
cout << ".xXXXXXXX0l'l0XXKl   .cKXKXX0l'l0XXXXXXXx." << endl;
cout << ".xXXXXXX0c'oKXXXx.  ..;c:o0XXKo'c0XXXXXXx." << endl;
cout << ".kXXXXXO:,dKXXX0:       'xXXXXKd,:OXXXXXx." << endl;
cout << ".kXXXXk;,xKXXXXOc;:.   'xXXXXXXKx,;kXXXXx." << endl;
cout << ".xXXKx,;kXXXXXXXXXO,  'kXXXXXXXXXk;,xKXXk." << endl;
cout << ".xXKd,:OXXXXXXXX0x:.'cxKXXXXXXXXXXO:,dKXx." << endl;
cout << ".xKo'c0XXXXXXXXX0;  ,okKXXXXXXXXXXX0c'oKx." << endl;
cout << ".xd'c0XXXXXXXXXXKc.:kKKXXXXXXXXXXXXXKc'xx." << endl;
cout << ".xk,;dkkkkkkkkkkkolxkkkkkkkkkkkkkkkkd;,kx." << endl;
cout << ".xXOoccccccccccccccccccccccccccccccccoOXx." << endl;
cout << ".xXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx." << endl;
cout << ".;llllllllllllllllllllllllllllllllllllll;." << endl;
}
else if (i == 4){
cout << "MMMMMMMMMMMMWWWNNNNXK00OkkxddolcxNMMMMMMMM" << endl;
cout << "MMMMMMMMN0kxddolloOkc::;;;;;;;;;dNMMMMMMMM" << endl;
cout << "MMMMMMMMXo;;;;;;;ckx:;;;;;;;;;;;dNMMMMMMMM" << endl;
cout << "MMMMMMMMXo;;;;;;;ckx:;;;;;;;;;;;dNMMMMMMMM" << endl;
cout << "MMMMMMMMXo;;;;;;;ckx:;;;;;;;;;;;dNMMMMMMMM" << endl;
cout << "MMMMMMMMNkdddddddxK0xxxxxxxxxxxx0WMMMMMMMM" << endl;
cout << "MMMMMMMMXdccccllloOOllllllllllllkNMMMMMMMM" << endl;
cout << "MMMMMMMMXo;;;;;;;ckx:;;;;;;;;;;;dNMMMMMMMM" << endl;
cout << "MMMMMMMMXo;;;;;;;ckx:;;;;;;;;;;;dNMMMMMMMM" << endl;
cout << "MMMMMMMMXxcc:::;;ckx:;;;;;;;;;;;dNMMMMMMMM" << endl;
cout << "MMMMMMMMWNXXK00OOOK0ddoollc::::;dNMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMMWWWWNXK0OkxdokNMMMMMMMM" << endl;
}
else if (i == 5){
cout << "MMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMWWMMMMMMMMM" << endl;
cout << "MMMMMMMMMKodXMMWXOxdddddk0XWMW0ldNMMMMMMMM" << endl;
cout << "MMMMMMMMMWOoxOdlllodxxxdolllxOddKMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMKl:o0NMMMMMMMMWXkc:dNMMMMMMMMMM" << endl;
cout << "MMMMMMMMMWO;c00d0WMMMMMMMMMMWk;lXMMMMMMMMM" << endl;
cout << "MMMMMMMMMK:cXO;lKMMMMMMMMMMMMMO,oWMMMMMMMM" << endl;
cout << "MMMN0OOKWd,kX::XMMMMMMMMMMMMMMNc;KMXO0NMMM" << endl;
cout << "MMMXxooONd,OK;cNMMMMMMMMMMMMMMNc;KMKdxXMMM" << endl;
cout << "MMMMMMMMMO,oNd,xWMMMMMMMMMMMMM0;lNMMMMMMMM" << endl;
cout << "MMMMMMMMMNo,xXdcOWMMMMMMMMMMW0::KMMMMMMMMM" << endl;
cout << "MMMMMMMMMMNx;l0XNMMMMMMMMMWKd;lKMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMNOdlccxNMMMMMMNxlclxkKWMMMMMMMMM" << endl;
cout << "MMMMMMMMMKl:OWXc'kNNNNNNk'cXWNd:dNMMMMMMMM" << endl;
cout << "MMMMMMMMMX0NMMWo.,,',;:l:.oWMMWXKNMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMWo.lxoc::c;.oWMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMWo.;lldxxxc.oWMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMWo.:c,...',.oWMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMx.,oxxddo,.xWMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMNx:coddol:dNMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMXOxxxxOXWMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
}
else if(i == 6){
cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMMWWWWWMMMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMWXkoc;;,,;:cokXWMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMWKl.            .lKMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMM0,                ,0MMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMNl                  lWMMMMMMMMMM" << endl;
cout << "MMMMWXOOKWNc                  cNWKOOXWMMMM" << endl;
cout << "MMMMO,  .dNl  ,ll:.    .:ll,  lNd.  ,OMMMM" << endl;
cout << "MMMNo.   ;0x.;KMMWk.  .kWMMK;.x0;   .oNMMM" << endl;
cout << "MM0:.    .od.:KXX0c',,'c0XNK:.do.    .:0MM" << endl;
cout << "MWx.   ..;x:  .....xXXx.....  :x;..   .xWM" << endl;
cout << "MMNkllxXNKXk;.    .',,'.    .;kXKNXxllkNMM" << endl;
cout << "MMMMMMMMMMMMXko'          'okXWMMMMMMMMMMM" << endl;
cout << "MMNkolxXN0xc,.:d:,,'''',,:d:.,cx0NXxloONMM" << endl;
cout << "MWx.   .'.    .c0NWNNWWWN0c.    .'.   .xWM" << endl;
cout << "MM0:.     .,lx0NMMMMMMMMMWN0xl,.     .:0MM" << endl;
cout << "MMMNo.   ,0WMMMMMMMMMMMMMMMMMMW0,   .oNMMM" << endl;
cout << "MMMMO,  .dWMMMMMMMMMMMMMMMMMMMMWd.  ,OMMMM" << endl;
cout << "MMMMWXOkKWMMMMMMMMMMMMMMMMMMMMMMWKkOXWMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
}
else if (i == 7){
cout << "MMMMMMMMMMMMMWOclONMNKklxXMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMk. .oXo..'xNMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMWOc;ok' 'OWWWWMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMW0o:,,,:,. ':;,,:o0WMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMXo.                .lXMMMMMMMMMM" << endl;
cout << "MMMMMMMMMWd.  .:'             .oWMMMMMMMMM" << endl;
cout << "MMMMMMMMMX:   oK;              ;XMMMMMMMMM" << endl;
cout << "MMMMMMMMMX;  .d0,              ;XMMMMMMMMM" << endl;
cout << "MMMMMMMMMWl   :Kl              lNMMMMMMMMM" << endl;
cout << "MMMMMMMMMM0'  .d0;            'OMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMWx.  .:,           .dWMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMNx.              .dNMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMWKdlcccoddolccldKWMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMWKkOKMMMMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMNc..lWMMMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMN:  cNMMMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMN:  cNMMMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMWOxk;  :kx0WMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMWx'.   ..'kWMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMWKo.  'oXWMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMW0xx0WMMMMMMMMMMMMMMMMMM" << endl;
}
else if (i == 8){
cout << "                       .     .    " << endl;
cout << "                 . ,%.   %%    %% " << endl;      
cout << "                  .,   ......    ," << endl;       
cout << "                 . ,%/*..@@..**%% " << endl;       
cout << "                       @@....     " << endl;       
cout << "                 .   &@  **  **   " << endl;       
cout << "            .     @@@,            " << endl;       
cout << "              @@@@&&&&&&&         " << endl;       
cout << "            @@@@@@@@&&&&&&&       " << endl;       
cout << "          @@@@@@@@@@@&&&&&&&&     " << endl;       
cout << "          @@@@@@  @@@  @@&&&&     " << endl;       
cout << "          @@@@@@  @@@  @@@@&&     " << endl;       
cout << "          @@@@@@@@@@@@@@@@@@@     " << endl;       
cout << "          @@@@@@@@@@@@@@@@@@@     " << endl;       
cout << "              @@@@@@@@@@@    .    " << endl;   
}
else if (i == 9){
cout << "    ..(                                " << endl;
cout << " ,,,,...(#                             " << endl;
cout << ",/,,,,,**..#                           " << endl;
cout << "  .,.#,,,,...(#                        " << endl;
cout << "     ,(,,,,,,...%                      " << endl;
cout << "       *,.#,,,....#/                   " << endl;
cout << "         ,%,,,,,....%                  " << endl;
cout << "            (,,#,/,....%,              " << endl;
cout << "               ,%,.,(,....#            " << endl;
cout << "                 (,,/&,,*...%.         " << endl;
cout << "                   ,(,*,,,...,#        " << endl;
cout << "                      (.,*,,,(...#     " << endl;
cout << "                         ,*,,,,,...,(  " << endl;
cout << "                           /.,,,,,#...(" << endl;
cout << "                              ,,,,,,,% " << endl;
cout << "                               ,.,     " << endl;
}
else if (i == 10){                                         
cout << "            .                   .     " << endl;    
cout << "          .                           " << endl;    
cout << "                ,  ,   ,             ." << endl;    
cout << "     .                                " << endl;    
cout << "  .           @///////////@           " << endl;    
cout << "              @,,,,,*,,,,,@           " << endl;    
cout << "              @/,,,*,,,,,/            " << endl;    
cout << "          %%%%%%%%%%%%%#((((((%       " << endl;    
cout << "         %%%%%%%%%%%%%%%%%%%%#(@%%%   " << endl;    
cout << ".        %%%%%%%%%%%%%%%%%%%%%(@      " << endl;    
cout << "        %@%%/%%%%%%%%%%%%%%%%(@       " << endl;   
cout << "         %%%%%%%%%%%%%%%%%%%%%%@      " << endl;    
cout << "           @@@             @@@        " << endl;  
}
else if (i == 11){
cout << "                   @@@@@@@@@         " << endl;     
cout << "          @#@@@.....@@@....@@.&@@@@@@" << endl;     
cout << "         @........@@@@@@###@@@@@@@@  " << endl;     
cout << "         .........@@.....@@.@@.....@ " << endl;     
cout << "    @@@@@@@@@@@@@@@..###...@@.###...@" << endl;     
cout << "        @...(.,...@.......@.@*.....@@" << endl;     
cout << "        @........@...,@&.......@@.   " << endl;     
cout << "         ,........@.............     " << endl;     
cout << "          @    ......@......@        " << endl;     
cout << "           .../........@             " << endl;     
cout << "           @...@.....@               " << endl;     
cout << "               @....@                " << endl;     
cout << "                ...@                 " << endl;     
cout << "            @  @  @                  " << endl;     
cout << "          ,   * @                    " << endl;     
cout << "           @  # @@                   " << endl;     
cout << "        @  @   @@                    " << endl;     
cout << "        @    @ @                     " << endl;     
cout << "              @@@                    " << endl;     
cout << "         @@   @ @                    " << endl;     
cout << " @..@     @ @%%%%@                   " << endl;     
cout << " /..#....   @%%%@%%%                 " << endl;     
cout << "   ........@  &%%@ @%%               " << endl;     
cout << "      @@@*      %%%   %%             " << endl;     
cout << "                  %%@  @%%&          " << endl;     
cout << "                    %%@ @%@          " << endl;     
cout << "                  %%@ @%%            " << endl;     
cout << "                %%@  %%@             " << endl;     
cout << "              %%@  @%@               " << endl;     
cout << "            %%@  @%%%%%%%%%%%%@      " << endl;     
cout << "         @%%@@@@@@@@   (@@@@@%%%%@   " << endl;     
cout << "       @%%%%@@%%%%%%%%%%%@           " << endl;     
cout << "                       (@@@/         " << endl;     
}
else if(i==12){
cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl; 
cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@@*(((((((/*@@@@@@@*@@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@*((%%%%%%%%@@@@@*@#*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@//#&&&&&&&&*@@@@@%#*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@###&&&&&&&&*@@@@@%@*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@@((%%%%%%%*@@@@@@*@*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@@@&**///&@@@@@@@/&&*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@*(%%%//%%%%(####*@%*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@*#%*&%%%%%/@@@@@@*@%*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@*#*(%%%%%%/@@@@@@*@%*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@/%@/%%%%%%/@@@@@@*@%*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@@*(%%&&&&(@@@@@@*@%*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@@*(%#@*(%/@@@@@@*@%*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@@*(%#@*(%/@@@@@@*@%*@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@@(%#%(/%%&/@@@@@(&@(@@@@@@@@@@" << endl;
cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}
else if(i == 13){
cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMK;.cXMMMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMNk,.,xNMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMMMWWWMMMMMMMXl. ,xNMMMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMWk:,cOWMMMWKo;co,.,xNMMM" << endl;
cout << "MMMMMMMMMMMMMMMMMMMKc,..:ONKo;l0WMNd. ,xXM" << endl;
cout << "MMMMMMMMMMMMMMMMMMMMWN0; .',c0WMMWOc;c,.,x" << endl;
cout << "MMMMMMMMMMMMMMMMMMMWKko;::. ;ONWOc:dXWNk;," << endl;
cout << "MMMMMMMMMMMMMMMMMWKl;;,;xX0c..;;;dXMMMMMWN" << endl;
cout << "MMMMMMMMMMMMMMMWKo;';lxkxKMW0c. ,kNMMMMMMM" << endl;
cout << "MMMMMMMMMMMMMW0l;':kxoxXMMMW0c,,..;kNMMMMM" << endl;
cout << "MMMMMMMMMMMW0l,'ckxxXMMMMW0l;oKW0c..xWMMMM" << endl;
cout << "MMMMMMMMMW0l,.ckdxNMMMMWOl;oKWMMMWKOXMMMMM" << endl;
cout << "MMMMMMMW0l'.lkokNWMMWNOc;oKWMMMMMMMMMMMMMM" << endl;
cout << "MMMMMW0l;oOkoONWMMWOc;;oKWMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMk,cKWMMWWMMWOc;dOKMMMMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMk'oWMMMMMWOc;dXMMMMMMMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMMK;;0NWWNOc:dXMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
cout << "MMMMNx;;llllc:dXWMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
cout << "MMNkloONWNXKKNMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
cout << "Nklo0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
cout << "o:xNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
} 
else if(i == 13){
cout<< "                 %########&               " << endl;
cout<< "                %          @              " << endl;
cout<< "     (%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    " << endl;
cout<< "     &%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#   " << endl;
cout<< "     &%%%%%%%%%%%%%%####%%%%%%%%%%%%%%#   " << endl;
cout<< "     &%%%%%%%%%%%%%%    %%%%%%%%%%%%%%#   " << endl;
cout<< "     &%%%%%%%%%%           /%%%%%%%%%%#   " << endl;
cout<< "     &%%%%%%%%%%,,,,    ,,,(%%%%%%%%%%#   " << endl;
cout<< "     &%%%%%%%%%%%%%%    %%%%%%%%%%%%%%#   " << endl;
cout<< "     &%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#   " << endl;
cout<< "     &%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#   " << endl;
cout<< "      .&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&     " << endl;
}
else if(i == 14){
cout << " @@@                                     " << endl; 
cout << "    @@@                                  " << endl; 
cout << "      @@@                                " << endl; 
cout << "         @@&          @@@@               " << endl; 
cout << "           @@@     @@@   .@@*            " << endl; 
cout << "             .@@*@@@        @@@          " << endl; 
cout << "                @             (@@        " << endl; 
cout << "                                 @@@  @@@" << endl; 
cout << "                                   @@@@@@" << endl; 
cout << "                                 @@@@@@@@" << endl; 
}
else if(i == 15){
cout<< "                          /@&                  " << endl;
cout<< "                      #@@@@@@@@                " << endl;
cout<< "                       ,@  @@@@                " << endl;
cout<< "                  @@@@@ @@ @@                  " << endl;
cout<< "                @@@@@ @@@@                     " << endl;
cout<< "                @@@@ @@@@%                     " << endl;
cout<< "                @@ @@@@@                       " << endl;
cout<< "               (@ @.                           " << endl;
cout<< "               @ @                             " << endl;
cout<< "              (                                " << endl;
}
else if( i == 16){
cout << "     .                             .      " << endl;      
cout << "   .                                      " << endl;
cout << "                 @@@@@@@&@                " << endl;
cout << "                 @@     @@                " << endl;
cout << "     .       @@@@@@@@@@@#@@@@@            " << endl;
cout << "           @@                 @@          " << endl;
cout << "           @@  @@         @@  @@          " << endl;
cout << "           @@  @@         @@  @@          " << endl;
cout << "           @@  #@         @@  @@          " << endl;
cout << "             @@@@@@@@@@@@@@@@@            " << endl;
cout << "                                          " << endl;
cout << "                                          " << endl;
cout << "      .                  .                " << endl;
cout << "                                          " << endl;
cout << "                                          " << endl;
cout << " **                         ,             " << endl;
}
else if( i == 17){
cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMWWMMMM" << endl;
cout << "MMWXkdddddddddoodddddddddddddddddddddkXWMM" << endl;
cout << "MMKl'''..;lo:''''''''''''.........''.'cKMM" << endl;
cout << "MWO;.'''cOXXd'''''''''''';clodddol:,'';OMM" << endl;
cout << "MMO;''.c0Kd;,''''''',:ldxxxdollloxkkd;;OMM" << endl;
cout << "MWO;.,;o0Xd,.'''',ldxkxl;,'.''.''',lOOdOMM" << endl;
cout << "WWO;.:KW0c'.''';dkkl,''''''''''''''',kXNWM" << endl;
cout << "MMO;.'::;'''':dOx:''''''''''''''''''':OWMM" << endl;
cout << "MMO;.'''''',oOx:''''''''''''''''''''''dWMM" << endl;
cout << "MMO;.'''''ckOc,'''''''''''''''''''''''oNMM" << endl;
cout << "MMO;.''.;d0d,''''''.',,;;;;;,..'''''''oNMM" << endl;
cout << "MMO;''':kOl'.'''''. .;dKXXXXo..'''''.'xWMM" << endl;
cout << "WMO;''cOO:.'''''''..:oOWWWWNl.'''.''.;OMMM" << endl;
cout << "MMO;'c0O;''''''..,o0WWWMXOK0;.'''''.'oXWMM" << endl;
cout << "WWO;:OO;''''''...kWWWNKx,.';'''''''.:O0KMM" << endl;
cout << "MMkcOO:'''''''. .ONOxxxOo....'''''',xOlOMM" << endl;
cout << "WW0OKl''''''..'. ,dkKWWMO;.''''''''o0c;OMM" << endl;
cout << "MWNNx,'''''..'kxlkNWWWNO:.''''''''oOl';OMM" << endl;
cout << "MMWKc''''''. :NMMWWXxoc'.''''''',oOl'';OMM" << endl;
cout << "MMWk,.'''''..dWWWWNx'..'''''''',dkc''';OMM" << endl;
cout << "MMWd''''.''..,c:ccc:'..'''''.':xx;.''.;OMM" << endl;
cout << "MMNo.''''''...........'''''',lko,''''.;OMM" << endl;
cout << "MMNo'''''''''.'''''''''''''cxd;''''.'';OMM" << endl;
cout << "MMWk,.'''.'''''''.''''''':dxc''''''''.;OMM" << endl;
cout << "WMWXl''''''''''''''''',cddc'''''.;odc';OMM" << endl;
cout << "MMK00l,''''''''''',:oddo:'''''',cOK0o';OMM" << endl;
cout << "WWOcoOko:,''',;cloooc:,''''.''.:0Ko,'';OMM" << endl;
cout << "MWO;';ldxdooooool:''''''''''.,:o0Kd,'';OMM" << endl;
cout << "MWO;''''''''''''''''''''''''.;0NOc'''';OMM" << endl;
cout << "WMNxc,,,,,,,,,,,,,,,,,,,,,,,',:c:,,,,:xXMM" << endl;
cout << "WWMWNK00000000KK000000000000KKKKKK0KKXWWMM" << endl;
cout << "WMMWWMMMMMMMMMMMMMMMMMMMMMMMMMWMWMWWMMWWMM" << endl;
}
else if( i == 18){
cout << "                  *(...(..,(              " << endl;
cout << "                ........*...,%            " << endl;
cout << "                 &..####....#             " << endl;
cout << "                 &./.,,,#..*,&            " << endl;
cout << "     /(*#**,.***.(./*,/*(/.(,***..**(*(#  " << endl;
cout << "                    (.(            ....   " << endl;
cout << "                    %((@                  " << endl;
cout << "               ,,,,,%#(((,,,,,,,,         " << endl;
cout << "             #*.%            ,./ & &      " << endl;
cout << "           &/*(#..../     ....##**#*.     " << endl;
}
}

void shop(Entity* player){
int input;
cout << "Welcome to Scotty's!" << endl; 
cout << "1. Buy" << endl;
cout << "2. Quit" << endl; 
cin.ignore();
cin >> input;
while (input != 1 && input != 2){
cout << "Invalid input!" << endl;
cin >> input; 
}


if (input == 1){
bool cont = true;
while (cont == true){
cont = buy(player);
}
}
else if(input == 2){
return;
}
}

bool buy(Entity* player){
int select;
cout <<"==========================================" << endl;
cout <<"            Bear-Bucks: " << player->getGold() << endl;
cout <<"------------------------------------------" << endl;
cout << "1. 1 Healing Potion - 50 BBs" << endl;
cout << "2. 1 Mana Potion    - 50 BBs" << endl;
cout << "3. Upgrade Weapon   - " << (player->getWeapon()->getLevel()+1)*100 << " BBs" << endl;
cout << endl;
cout << "4. Quit" << endl;
cout <<"==========================================" << endl;

cin >> select;
while (select != 1 && select != 2 && select != 3 && select != 4){
cout << "Invalid input!" << endl;
cin >> select;
}

if(select == 1){
if(CheckPrice(50,player) == true){
cout << "Thank you for your purchase!" << endl;
player->setGOLD(50,2);
player->setHP_Potion(1,1);
return true;
}
else{
cout << "Not enough funds!" << endl;
return true; 
}
}
else if (select == 2){
if(CheckPrice(50,player) == true){
cout << "Thank you for your purchase!" << endl;
player->setGOLD(50,2);
player->setMP_Potion(1,1);
return true;
}
else{
cout << "Not enough funds!" << endl;
return true;
}
}
else if (select == 3) {
if(CheckPrice((player->getWeapon()->getLevel()+1)*100,player) == true){
cout << "Thank you for your purchase!" << endl;
player->setGOLD((player->getWeapon()->getLevel()+1)*100,2);
player->getWeapon()->levelUp();
return true;
}
else{
cout << "Not enough funds!" << endl;
return true;
}
}
else{
return false;
}
}

bool CheckPrice(int price, Entity* player){
if(price <= player->getGold()){
return true;
}
else{
return false;
}
}
