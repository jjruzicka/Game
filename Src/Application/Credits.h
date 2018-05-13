#pragma once
#include "Escenas.h"
#include "EscenasManager.h"
#include "InputComponent.h"
#include "Gui3D.h"
#include "Gui3DPanel.h"
#include "Gui3DScreenPanel.h"
#include "MyPurplePanelColors.h"
#include "MyEnvironmentDemoPanelColors.h"
#include <iostream>
#include "Estados.h"
#include "Menu.h"
class Credits :
	public Menu, OIS::MouseListener
{
public:
	Credits(Escenas* scn);
	
	virtual ~Credits();
protected:
	bool creditsToMenu(Gui3D::PanelElement* e);
	Gui3D::ScreenPanel* mPanel;
	virtual void update(){};
	virtual void render();
	void createPanel();

	virtual bool mouseMoved(const OIS::MouseEvent &arg);
	virtual bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);

	virtual bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	Ogre::Vector3 cameraDirection;
	
	Escenas* scnM;

};

