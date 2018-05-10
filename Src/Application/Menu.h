#pragma once
#include "Escenas.h"
#include "InputComponent.h"
#include "EscenasManager.h"
#include "Gui3D.h"
#include "Gui3DPanel.h"
#include "Gui3DScreenPanel.h"
#include "MyPurplePanelColors.h"
#include "MyEnvironmentDemoPanelColors.h"
class Menu : public Escenas, public InputComponent
{
public:
	Menu(EscenasManager* scnM);
	virtual ~Menu();
	virtual bool run();
	
	
protected:
	bool exit_(Gui3D::PanelElement* e);
	virtual void createPanel();
	bool play_(Gui3D::PanelElement* e);
	bool credits_(Gui3D::PanelElement* e);
	virtual bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	Ogre::Vector2 getScreenCenterMouseDistance();
	virtual bool mouseMoved(const OIS::MouseEvent &arg);
	EscenasManager* scnM;

	bool exit;

	Ogre::Vector3 cameraDirection;

	// Gui3D main object
	Gui3D::Gui3D* mGui3D;

	// The main panel (display in 3D)
	Gui3D::Panel* mPanel;

	// The screen Panel (display in 2D)
	Gui3D::ScreenPanel* mSPanel;
	Gui3D::ScreenPanel* mSPanel2;

	// Keep track of some captions to modify their contents on callbacks
	Gui3D::Caption* captionButton;

	//MyEnvironmentDemoPanelColors mMyEnvironmentDemoPanelColors;

	// As Gui3D doesn't fully abstract Gorilla, you still have to deal with it. 
	
	Gorilla::Layer* mMousePointerLayer;
	Gorilla::Rectangle* mMousePointer;
	Ogre::Vector2 mNormalizedMousePosition;

	int mClicksOnButton;
	
	MyPurplePanelColors mMyPurplePanelColors;
//variables vienen de escenas.h
};