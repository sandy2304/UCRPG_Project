#ifndef __SKILLB__
#define __SKILLB__

#include "../character/character.hpp"
#include <iostream>
using namespace std;

class Entity;
	
class Skill{
	protected:
		Entity* attacker = nullptr;
		Entity* reciever = nullptr;
	public:
		Skill(){}
		Skill(Entity* att, Entity* rec){
			attacker = att;
			reciever = rec;
		}
	
		~Skill(){}
			
		virtual void do_Skill() = 0;

		
};

#endif
