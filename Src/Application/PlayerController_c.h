#pragma once
#include "InputComponent.h"
#include "Entidad.h"
#include <OgreRenderWindow.h>
#include "RigidBody_c.h"
#include "Render_c.h"
#include "StatsPJ_c.h"
class PlayerController_c :
	public InputComponent
{
public:
	PlayerController_c(Entidad* ent, InputComponent * input, StatsPJ_c* estadisticas);
	void Update();

	~PlayerController_c();
private:
	bool keyPressed(const OIS::KeyEvent& keyP);
	bool keyReleased(const OIS::KeyEvent& keyP);
	bool mouseMoved(const OIS::MouseEvent& me);
	bool mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	InputComponent* inputcomp_;
	Entidad* entidad;
	float auxX, auxY, auxZ;
	bool mas, istimetoStop;
	RigidBody_c* rb;
	Render_c * rc;
	StatsPJ_c* estadisticas;
	Ogre::SceneNode* node;
};

