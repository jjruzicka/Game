#pragma once
#include "Escenas.h"
#include "EscenasManager.h"
class Menu : public Escenas
{
public:
	Menu(EscenasManager* scnM, Ogre::RenderWindow* mWindow, Ogre::SceneManager * scnMgrOgre, btDiscreteDynamicsWorld* bulletWorld);
	virtual ~Menu();
	virtual bool run();
	void MenuToPlay();
private:
	EscenasManager* scnM;
//variables vienen de escenas.h
};