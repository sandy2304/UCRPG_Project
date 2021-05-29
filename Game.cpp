#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "Character_Factory/Character_Factory.hpp"
#include "skills/Skill.hpp"
#include "skills/BCOE_Skill.hpp"
#include "skills/CHASS_Skill.hpp"
#include "skills/CNAS_Skill.hpp"
#include "skills/GSE_Skill.hpp"
#include "skills/SB_Skill.hpp"
#include "skills/SM_Skill.hpp"


using namespace std;

void worldHubMenu(int&);
void school_Challenge(Entity*);
void BCOE_Challenge(Entity*);
void CHASS_Challenge(Entity*);
void CNAS_Challenge(Entity*);
void GSE_Challenge(Entity*);
void SB_Challenge(Entity*);
void SM_Challenge(Entity*); 
void Battle(Entity*,Entity*);
int BattleMenu(Entity*); 
int inputCheck(int,int);
void skillSet(Entity*, string);
void printEnemy(int);
void shop(Entity* );
bool buy(Entity* );
bool CheckPrice(int, Entity*);


int main() {
	cout << inputCheck(1,3) << endl;
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
	if (welcomeInput == 3) {
		return 0;
	}
	//IMPLEMENT THIS
	else if( welcomeInput == 2){
		return 0;
	}
	else if(welcomeInput == 1) {
		cout << "=========================================================================================" << endl;
		cout << "Hello! What is your name? (10 characters max)" << endl;
		cout << "=========================================================================================" << endl;
		cin >> userName;
		cout << "=========================================================================================" << endl;	
		cout << "Greetings " << userName << "! What school would you like to pursue?" << endl;
		cout << "1 - Marlan and Rosemary Bourns College of Engineering (BCOE)" << endl;
		cout << "2 - College of Humanities, Arts, and Social Sciences (CHASS)" << endl;
		cout << "3 - College of Natural and Agricultural Sciences (CNAS)" << endl;
		cout << "4 - Graduate School of Education (GSE)" << endl;
		cout << "5 - School of Business (SB)" << endl;
		cout << "6 - School of Medicine (SM)" << endl;
		cout << "=========================================================================================" << endl;
		cin >> schoolInput;
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
			school_Challenge(player); 
		}else if(userInput == 5){
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
		cout << "5 - Quit game" << endl;
		cout << "=========================================================================================" << endl;
		cin >> input;
		if((input <= 0) || (input >= 6)){
			cout << "Invalid Input! Choose again" << endl;
		}else{
			cond = true;
		}
			
	}
}

//=======================================BATTLE STUFF=======================================
void school_Challenge(Entity* player){
	cout << "Level " <<  player->getLevel() << " " << endl;	
	if(player->getLevel() == 1){
		BCOE_Challenge(player);
	} 			
}

void BCOE_Challenge(Entity* player){
     cout << "Welcome to the BCOE Challenge!" << endl;
     cin.ignore();  
     cin.get();
     cout << "First Opponent: The Debugger" << endl; 
     Entity_Factory* Factory = new BCOE_Factory();
     Entity* debugger = Factory->createEntity("the debugger",player->getLevel(),2);
     cin.ignore();
     cin.get();
     Battle(player,debugger);
}	

void Battle(Entity* player, Entity* enemy){
  int userInput;
  while(player->getHP() < 0 || enemy->getHP() < 0){
	userInput = inputCheck(1,3);
  	if(player->getINT() > enemy->getINT()){
  		
  	}
  	else{	

  	} 
  }
}

int BattleMenu(Entity* player,int& option,int& potion){
	int choice;
	int choice2; 
	int choice3;
	bool skillCheck = false, main = false; 
	cin >> choice;
	while(1){
       		player->showMPHP();
       		cout << "         (1)Fight         (2)Items        " << endl;
       		cout << "==========================================" << endl;
		choice = inputCheck(1,2);
		if(choice == 1){
			player->printSkill();
			cout << "Enter 5 to go back" << endl;
			choice2 = inputCheck(1,5);
			if(choice2 < 5){
				skillSet(player, player->pickSkill(choice2));
				skillCheck = player->checkManaCost();
				if(skillCheck == true){
					break;
				}
			}
		}else if(choice == 2){
			player->printBackpack();
			cout << "     (1)HP Potion         (2)MP Potion    " << endl;
			cout << "==========================================" << endl;
			cout << "Enter 3 to go back" << endl;
			choice3 = inputCheck(1,3);
			if(choice < 4){
				potion = choice3;
				break; 
			}
		}	      
	}
}

//=============================OTHER===================================
int inputCheck(int rangeA, int rangeB){
	int num;
	cin >> num;
	while(!((num >= rangeA) && (num <= rangeB))){
		cout << "Please enter a number from " << rangeA << " to " << rangeB << endl;
		cin >> num;	
	}
	return num;
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
	}else if(skillName == "F_Hammer"){
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
	}
	
	else{
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
cout << "1. 1 Healing Potion - 50 BBs" << endl;
cout << "2. 1 Mana Potion    - 50 BBs" << endl;
cout << "3. Upgrade Weapon   - " << (player->getWeapon()->getLevel()+1)*100 << " BBs" << endl;
cout << endl;
cout << "4. Quit" << endl;

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
