#include "EscenasManager.h"


using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
EscenasManager::EscenasManager()
{
	juegoB = false;
	menuB = true;
	

	if (menuB){
		states.push_back(new Menu(esc));
		
	}
	else if (juegoB){
		states.push_back(new Juego(esc));
		
	}
}

void EscenasManager::MenuToGame(){
	menuB = false;
	juegoB = true;
	delete states[0];
	states.push_back(new Juego(esc));
	
}
void EscenasManager::GameToMenu(){
	menuB = true;
	juegoB = false;
	delete states[0];
	states.push_back(new Menu(esc));
	
}

EscenasManager::~EscenasManager()
{
	delete states[0];

}

