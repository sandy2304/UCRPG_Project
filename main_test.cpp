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
	Entity_Factory* Factory = new BCOE_Factory();
	Entity_Factory* Factory2 = new SM_Factory();
	Entity* player1 = Factory->createEntity("Dylan", 2,1);
	Entity* player2 = Factory2->createEntity("Angel", 2,2);
	Weapon* weapon = new BCOE_Weapon(1,1);
	player1->showStats();
	player1->weaponUpgrade();
	player1->showStats();
	//player1->showMPHP();
	//player2->showMPHP();
	//cout << weapon->getName() << ": " << weapon->getStat() <<  endl;
	//weapon->levelUp();
	//cout << weapon->getName() << ": " << weapon->getStat() << endl;
	
	player1->showMPHP();
	
	player1->printBackpack();
	
	player1->setHP_Potion(2,1);
  player1->printBackpack();
	
	player1->usePotion(1);
	player1->printBackpack();

return 0;
}
