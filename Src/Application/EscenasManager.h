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
	void MenuToCredits();
	void CreditsToMenu();
private:


	bool juegoB;//la B es de bool
	bool menuB;//la B es de bool
	bool creditsB;
	Escenas* juego;
	Escenas* menu;
	Escenas* credits;
};