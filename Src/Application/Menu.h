#ifndef MENU_H
#define MENU_H
#include "Escenas.h"
#include "EscenasManager.h"
#include "GUI.h"
class Menu : public Escenas
{
public:
	Menu();
	virtual ~Menu();
	virtual bool run();
	void MenuToPlay();
	void MenuToExit();
	bool exit;
private:
	GUI* gui;

//variables vienen de escenas.h
};
#endif