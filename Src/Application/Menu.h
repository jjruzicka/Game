#pragma once
#include "Escenas.h"
#include "EscenasManager.h"
#include "GUI.h"
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
	GUI* gui;
//variables vienen de escenas.h
};