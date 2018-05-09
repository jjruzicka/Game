#pragma once
#include "Escenas.h"
class Juego : public Escenas
{
public:
	Juego(Ogre::RenderWindow* mWindow, Ogre::SceneManager * scnMgrOgre, btDiscreteDynamicsWorld* bulletWorld);
	virtual ~Juego();
	virtual bool run();
private:
	//variables vienen de escenas.h
};