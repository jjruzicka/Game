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
	menu = nullptr;
	juego = nullptr;
}

bool EscenasManager::run(){
	if (juegoB){
		juego = new Juego(this);
		juego->run();
	}
	else if (menuB){
		menu = new Menu(this);
		menu->run();
	}
	else
		exit(0);
}
void EscenasManager::Exit(){
	delete menu;
	menuB = false;
	this->run();
}

void EscenasManager::MenuToGame(){
	menuB = false;
	juegoB = true;
	delete menu;
	this->run();
}
void EscenasManager::GameToMenu(){
	menuB = true;
	juegoB = false;
	delete juego;
	this->run();
}
EscenasManager::~EscenasManager()
{
	if (menuB)
		delete menu;
	else if (juegoB)
		delete juego;
}

