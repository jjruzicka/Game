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
	bool exit;
private:
	EscenasManager* scnM;
//variables vienen de escenas.h
};