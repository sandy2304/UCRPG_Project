#ifndef __CHARACTER_FACTORY__
#define __CHARACTER_FACTORY__

#include "../character/BCOE.hpp"
#include "../character/BCOE.hpp"
#include "../character/CHASS.hpp"
#include "../character/CNAS.hpp"
#include "../character/GSE.hpp"
#include "../character/SB.hpp"
#include "../character/SM.hpp"
#include "../weapons/weapon.hpp"
#include "../weapons/BCOE_Weapon.hpp"
#include "../weapons/CHASS_Weapon.hpp"
#include "../weapons/CNAS_Weapon.hpp"
#include "../weapons/GSE_Weapon.hpp"
#include "../weapons/SB_Weapon.hpp"
#include "../weapons/SM_Weapon.hpp"
#include <iostream>
#include <string>

using namespace std;

class Entity_Factory{
        public:
                virtual Entity* createEntity(string, int, int) = 0;
};
// n = name, l = level, t = type
class BCOE_Factory: public Entity_Factory{
	public:
		virtual Entity* createEntity(string n, int l, int t){
			Entity* player = new BCOE_Entity(n,l,t);
			Weapon* weapon = new BCOE_Weapon(l);
			
			player->setWeapon(weapon);
			return player; 
		}
};

class CHASS_Factory: public Entity_Factory{
	public:
		virtual Entity* createEntity(string n, int l, int t){
			Entity* player = new CHASS_Entity(n,l,t);
			Weapon* weapon = new CHASS_Weapon(l);
			
			player->setWeapon(weapon);
			return player; 
		}
};

class CNAS_Factory: public Entity_Factory{
	public:
		virtual Entity* createEntity(string n, int l, int t){
			Entity* player = new CNAS_Entity(n,l,t);
			Weapon* weapon = new CNAS_Weapon(l);
			
			player->setWeapon(weapon);
			return player; 
		}
};

class GSE_Factory: public Entity_Factory{
	public:
		virtual Entity* createEntity(string n, int l, int t){
			Entity* player = new GSE_Entity(n,l,t);
			Weapon* weapon = new GSE_Weapon(l);
			
			player->setWeapon(weapon);
			return player; 
		}
};

class SB_Factory: public Entity_Factory{
	public:
		virtual Entity* createEntity(string n, int l, int t){
			Entity* player = new SB_Entity(n,l,t);
			Weapon* weapon = new SB_Weapon(l);
			
			player->setWeapon(weapon);
			return player; 
		}
};

class SM_Factory: public Entity_Factory{
	public:
		virtual Entity* createEntity(string n, int l, int t){
			Entity* player = new SM_Entity(n,l,t);
			Weapon* weapon = new SM_Weapon(l);
			
			player->setWeapon(weapon);
			return player; 
		}
};
#endif
