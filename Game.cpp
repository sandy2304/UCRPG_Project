#include <iostream>
#include <string>
#include <stdio.h>
#include "Character_Factory/Character_Factory.hpp"

using namespace std;

void worldHubMenu(int&);

int main() {
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
			cout << "Implement Store" << endl;
		}else if(userInput == 2){
			cout << "Implement Access Inventory" << endl;
		}else if(userInput == 3){
			player->showStats();
		}else if(userInput == 4){
			cout << "Implement Select School to Challenge" << endl;
		}else if(userInput == 5){
			break;
		}
	}
	
	return 0;	
}

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

