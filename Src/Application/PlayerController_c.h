#pragma once
#include "Component.h"
#include "Entidad.h"
#include <OgreRenderWindow.h>
#include <OgreFrameListener.h>
#include "OIS.h"

class PlayerController_c : public Component, public Ogre::FrameListener
	
{
public:
	PlayerController_c(Entidad* ent);
	void Update();
	bool frameStarted(/*const Ogre::FrameEvent& evt*/);
	Ogre::RenderWindow* win;
	~PlayerController_c();
private:
	OIS::InputManager* _inputManager;
	OIS::Keyboard* _keyboard;
	OIS::Mouse* _mouse;
	Entidad* entidad;
	Ogre::RenderWindow *renderWindow;


};

