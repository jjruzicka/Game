#pragma once
#include "Escenas.h"
#include "InputComponent.h"
#include "Gui3D.h"
#include "Gui3DPanel.h"
#include "Gui3DScreenPanel.h"
#include "MyPurplePanelColors.h"
#include "MyEnvironmentDemoPanelColors.h"
#include "Render_c.h"
#include "PlayerController_c.h"
#include "RigidBody_c.h"
#include "Objeto.h"
#include "Collider_c.h"
class Estados
{
public:
	Estados(Escenas* scn);
	~Estados();
	virtual void update();
	

	std::vector<Entidad*> entidades;
	
	btDiscreteDynamicsWorld* bulletWorld;
protected:
	bool cameraON;
	Ogre::Camera* getCamera();
	Ogre::Viewport* getVp();

	InputComponent* getInput();

	MyPurplePanelColors mMyPurplePanelColors;
	
	Escenas* escen;
	

};

