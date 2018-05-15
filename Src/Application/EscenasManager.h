#pragma once
#include "Escenas.h"


class EscenasManager
{
public:
	EscenasManager();
	~EscenasManager();
	bool run();
	void MenuToGame();
	void GameToMenu();
private:


	bool juegoB;//la B es de bool
	bool menuB;//la B es de bool
	Escenas* juego;
	Escenas* menu;
};