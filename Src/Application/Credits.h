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
class Credits :
	public Escenas, public InputComponent
{
public:
	Credits(EscenasManager* scnM);
	void createPanel();
	virtual bool run();
	bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
		
	bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
		
	Ogre::Vector2 getScreenCenterMouseDistance();
    bool mouseMoved(const OIS::MouseEvent &arg);
	virtual ~Credits();
protected:
	bool creditsToMenu(Gui3D::PanelElement* e);
	
	Ogre::Vector3 cameraDirection;
	// Gui3D main object
	Gui3D::Gui3D* mGui3D;

	// The main panel (display in 3D)
	Gui3D::Panel* mPanel;

	// The screen Panel (display in 2D)
	Gui3D::ScreenPanel* mSPanel;
	Gui3D::ScreenPanel* mSPanel2;
	EscenasManager* scnM;

	// Keep track of some captions to modify their contents on callbacks
	Gui3D::Caption* captionButton;

	//MyEnvironmentDemoPanelColors mMyEnvironmentDemoPanelColors;

	// As Gui3D doesn't fully abstract Gorilla, you still have to deal with it. 

	Gorilla::Layer* mMousePointerLayer;
	Gorilla::Rectangle* mMousePointer;
	Ogre::Vector2 mNormalizedMousePosition;

	int mClicksOnButton;

	MyPurplePanelColors mMyPurplePanelColors;

};

