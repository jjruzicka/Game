#pragma once

#include <iostream>
//#include <stack>
//#include "Escenas.h"
#include "Estados.h"
#include <vector>
#include "Menu.h"
#include "Juego.h"


class EscenasManager
{
	friend class Escenas;
public:
	EscenasManager();
	
	

	~EscenasManager();
	bool run();
	void MenuToGame();
	void GameToMenu();
	std::vector <Estados*> states;
private:
	
	Escenas* esc;
	bool juegoB;//la B es de bool
	bool menuB;//la B es de bool
	
};