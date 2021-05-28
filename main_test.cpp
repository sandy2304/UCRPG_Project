#include "character/character.hpp"
#include "character/BCOE.hpp"
#include "character/CHASS.hpp"
#include "character/CNAS.hpp"
#include "character/GSE.hpp"
#include "character/SB.hpp"
#include "character/SM.hpp"
#include "weapons/weapon.hpp"
#include "save/save.hpp"
#include "weapons/BCOE_Weapon.hpp"
#include "weapons/CHASS_Weapon.hpp"
#include "weapons/CNAS_Weapon.hpp"
#include "weapons/GSE_Weapon.hpp"
#include "weapons/SB_Weapon.hpp"
#include "weapons/SM_Weapon.hpp"
#include "Character_Factory/Character_Factory.hpp"
#include "skills/Skill.hpp"
#include "skills/BCOE_Skill.hpp"
#include "skills/CHASS_Skill.hpp"
#include "skills/CNAS_Skill.hpp"
#include "skills/GSE_Skill.hpp"
#include <iostream>

using namespace std;

int main(){
	ResetGame();	
	//Entity* player1 = new BCOE_Entity("Dylan", 3,1);
   	//Entity* player2 = new CHASS_Entity("David", 3,2);
	//Entity* player3 = new CNAS_Entity("Deez", 3,1);
	//Entity* player4 = new GSE_Entity("Bruh",2, 2);
	//Entity* player5 = new SB_Entity("Sheesh",7,2);
	//Entity* player6 = new SM_Entity("pp", 8, 1);
	//Weapon* weapon = new BCOE_Weapon(1);
	//weapon->weaponDetails();
	Skill* skill  = new F_Hammer();
	Entity_Factory* Factory = new GSE_Factory();
	Entity_Factory* Factory2 = new SM_Factory();
	Entity* player1 = Factory->createEntity("Dylan", 2,1);
	Entity* player2 = Factory2->createEntity("Angel", 2,2);
	player1->showMPHP();
	player2->showMPHP();
	player1->attack(player2);
	player2->attack(player1);

	player1->showStats();
	player2->showStats();
	
	player1->attack(player2);


	player2->showMPHP();
	player1->setSkill(skill);
	player1->attack(player2);
	player1->showMPHP();
	player2->showMPHP();	

	player2->showStats();
	
	player1->showMPHP();
	//player1->showStats();
  	//player2->showStats();
	//player3->showStats();
	//player4->showStats();
	//player5->showStats();
	//player6->showStats(); 


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

	return 0;
}
