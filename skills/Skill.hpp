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
	protected:
		Entity* atk = nullptr;
		Entity* rec = nullptr;
	public:
		Skill(Entity* att, Entity* recv){
			atk = att;
			rec = recv;
		}
	
		~Skill(){}
			
		virtual void do_Skill() = 0;

		
};

#endif
