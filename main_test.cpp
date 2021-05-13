#include "character/character.hpp"
#include "character/BCOE.hpp"
#include <iostream>

using namespace std;

int main(){
	Entity* player1 = new BCOE_Entity("Dylan", 3,1);
   	Entity* player2 = new BCOE_Entity("David", 3,2);
	
	player2->showStats();
 	player1->attack(player2);
	player2->showStats();
   return 0;
}
