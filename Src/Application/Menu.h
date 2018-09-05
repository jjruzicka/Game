#ifndef MENU_H
#define MENU_H
#include "Escenas.h"
#include "GUI.h"

#include "EstadosManager.h"
class Menu : public Escenas
{
public:
	Menu();
	virtual ~Menu();
	virtual bool run();
	void MenuToPlay();
	void MenuToExit();
	void initCamera();
private:
	GUI* gui;
	EstadosManager * estadosManager;
	Ogre::Light* light;

	bool exit;
	bool goJuego;
//variables vienen de escenas.h
};
#endif