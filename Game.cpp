#include <iostream>
#include <string>
#include "Character_Factory/Character_Factory.hpp"

using namespace std;

int main() {
	int welcomeInput;
	string userName;
	int schoolInput;
	Entity_Factory* CharFactory = nullptr;
	Entity* player = nullptr;
	cout << "Welcome to UCRPG! Please select an option!" << endl;
	cout << "1 - Start game" << endl;
	cout << "2 - Quit game" << endl; 
	cin >> welcomeInput;

	while ((welcomeInput <= 0) || (welcomeInput >= 3)) {
		cout << "ERROR : INVALID INPUT! Please try again!";
		cin >> welcomeInput;
	}
	if (welcomeInput == 2) {
		return 1;
	}
	if (welcomeInput == 1) {
		cout << "Hello! What is your name? (10 characters max)" << endl;
		cin >> userName;
		cout << "Greetings " << userName << "! What school would you like to pursue?" << endl;
		cout << "1 - Marlan and Rosemary Bourns College of Engineering (BCOE)" << endl;
		cout << "2 - College of Humanities, Arts, and Social Sciences (CHASS)" << endl;
		cout << "3 - College of Natural and Agricultural Sciences (CNAS)" << endl;
		cout << "4 - Graduate School of Education (GSE)" << endl;
		cout << "5 - School of Business (SB)" << endl;
		cout << "6 - School of Medicine (SM)" << endl;
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
	return 0;
}
