#include "character/character.hpp"
#include "character/BCOE.hpp"
#include "character/CHASS.hpp"
#include "character/CNAS.hpp"
#include "character/GSE.hpp"
#include "character/SB.hpp"
#include "character/SM.hpp"

#include <iostream>

using namespace std;

int main(){
	Entity* player1 = new BCOE_Entity("Dylan", 3,1);
   	Entity* player2 = new CHASS_Entity("David", 3,2);
	Entity* player3 = new CNAS_Entity("Deez", 3,1);
	Entity* player4 = new GSE_Entity("Bruh",2, 2);
	Entity* player5 = new SB_Entity("Sheesh",7,2);
	Entity* player6 = new SM_Entity("pp", 8, 1);
	
	player1->showStats();
  	player2->showStats();
	player3->showStats();
	player4->showStats();
	player5->showStats();
	player6->showStats();

	return 0;
}
