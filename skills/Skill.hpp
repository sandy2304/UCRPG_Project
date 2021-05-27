#ifndef __SKILLB__
#define __SKILLB__

#include "../character/character.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Entity;
	
class Skill{
	public:
		Skill(){}
		virtual void do_Skill(Entity*, Entity*) = 0;
		virtual bool manaCheck(Entity*) = 0;
		
};

#endif
