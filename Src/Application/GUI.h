#pragma once
#include "InputComponent.h"
#include "OgreViewport.h"
#include <OgreCamera.h>
#include "Gui3D.h"
#include "Gui3DPanel.h"
#include "Gui3DScreenPanel.h"
#include "MyPurplePanelColors.h"
#include "MyEnvironmentDemoPanelColors.h"
#include "Escenas.h"

class GUI: public InputComponent
{
public:
	GUI(InputComponent* input_, Ogre::Viewport* vp, Ogre::SceneManager * scnMgr, Ogre::Camera * cam, Ogre::SceneNode* camNode, Escenas* menuc, bool escena);
	void createPanel();
	void createPanelInGame();
	Gui3D::ScreenPanel* mSPanel2;
	Gui3D::Panel* panel;
	void setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Degree ang);
	void setText(Ogre::String text, Ogre::Real y);
	void _createPanel();
	void createUI();
	~GUI();
	Gui3D::Caption* getCaptionVida(){
		return captionButton;
	}
	Gui3D::Caption* getCaptionExp(){
		return captionExperiencia;
	}
	Gui3D::Caption* getCaptionDamage(){
		return captionDamage;
	}
	Gui3D::Caption* getCaptionNivel(){
		return captionLevel;
	}
private:

	Escenas* menu;

	InputComponent* icomp_;
	Ogre::SceneManager * scn;
	Ogre::Viewport* view;
	bool exitGame(Gui3D::PanelElement* e);
	bool textChanged(Gui3D::PanelElement* e);
	bool play_(Gui3D::PanelElement* e);
	bool exit_(Gui3D::PanelElement* e);
	bool buttonPressed(Gui3D::PanelElement* e);
	bool keyPressed(const OIS::KeyEvent& keyP);
	bool keyReleased(const OIS::KeyEvent& keyP);
	bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	Ogre::Vector2 getScreenCenterMouseDistance();
	bool mouseMoved(const OIS::MouseEvent &arg);
	bool menuEscena;

	Gui3D::Caption* captionButton;
	Gui3D::Caption* captionDamage;
	Gui3D::Caption* captionExperiencia;
	Gui3D::Caption* captionLevel;
	// Gui3D main object
	Gui3D::Gui3D* mGui3D;
	Gui3D::Gui3D* UI3D;
	// The main panel (display in 3D)
	Gui3D::Panel* mPanel;

	// The screen Panel (display in 2D)
	Gui3D::ScreenPanel* mSPanel;


	// Keep track of some captions to modify their contents on callbacks
	
	Gui3D::Caption* captionDisplayTextZone;
	Gui3D::Caption* captionLocalTime;

	//conversations
	Gui3D::Caption* captionChecked;
	Gui3D::Caption* captionCombobox;

	MyEnvironmentDemoPanelColors mMyEnvironmentDemoPanelColors;

	// As Gui3D doesn't fully abstract Gorilla, you still have to deal with it. 
	// See http://www.valentinfrechaud.fr/Gui3DWiki/index.php/Gui3D_and_Gorilla for more infos.
	Gorilla::Layer* mMousePointerLayer;
	Gorilla::Rectangle* mMousePointer;
	Ogre::Vector2 mNormalizedMousePosition;
	Gorilla::Screen* myScreen;
	int mClicksOnButton;

	Gui3D::Clock globalClock;
	Gui3D::Clock localClock;

	// Keep track of number of frames
	int nbFramesSinceStart;
	int numFrameLastClicked;
	Ogre::Vector3 cameraDirection;
	Ogre::Camera * camera;
	Ogre::SceneNode* cNode;

	MyPurplePanelColors* mMyPurplePanelColors;
	
};

