#include "character/character.hpp"
#include <iostream>

using namespace std;

int main(){
   cout << "Hello World" << endl;
	   
   Entity player("Dylan", "BCOE", 2, 1);
   player.showStats();
   return 0;
}
