#pragma once
#include "Escenas.h"
#include "EscenasManager.h"
class Menu : public Escenas
{
public:
	Menu(EscenasManager* scnM);
	virtual ~Menu();
	virtual bool run();
	void MenuToPlay();
private:
	EscenasManager* scnM;
//variables vienen de escenas.h
};