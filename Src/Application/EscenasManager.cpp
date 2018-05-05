#include "EscenasManager.h"
#include "Menu.h"
#include "Juego.h"
using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
EscenasManager::EscenasManager()
{
	juegoB = false;
	menuB = true;

	if (menuB)
		menu = new Menu();
	else if (juegoB)
		juego = new Juego();
}

bool EscenasManager::run(){
	if (juegoB)
		juego->run();
	else if (menuB)
		menu->run();
	return true;
}

void EscenasManager::MenuToGame(){
	menuB = false;
	juegoB = true;
	delete menu;
	juego = new Juego();
	run();
}
void EscenasManager::GameToMenu(){
	menuB = true;
	juegoB = false;
	menu = new Menu();
	delete juego;
	run();
}
EscenasManager::~EscenasManager()
{
	if (menuB)
		delete menu;
	else if (juegoB)
		delete juego;
}

