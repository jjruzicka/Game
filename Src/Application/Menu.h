#pragma once
#include "InputComponent.h"
#include "EscenasManager.h"
#include "Gui3D.h"
#include "MyPurplePanelColors.h"
#include "Gui3DPanelElement.h"
#include "Gui3DPanel.h"
#include "Gui3DScreenPanel.h"
#include "Estados.h"
class Menu : public Estados, OIS::MouseListener
{
public:
	Menu(Escenas* scn);
	~Menu();
	
	bool putCamera();
	
protected:
	
	virtual void update();

	
	bool exit_(Gui3D::PanelElement* e);
	virtual void createPanel();
	bool play_(Gui3D::PanelElement* e);
	
	virtual bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	Ogre::Vector2 getScreenCenterMouseDistance();
	virtual bool mouseMoved(const OIS::MouseEvent &arg);
	
	bool exit;
	bool init;

	Ogre::Vector3 cameraDirection;
	Ogre::SceneNode* camNode = nullptr;

	// Gui3D main object
	
	// The main panel (display in 3D)
	Gui3D::Gui3D* mGui3D;
	MyPurplePanelColors mMyPurplePanelColors;

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
	
	
//variables vienen de escenas.h
};