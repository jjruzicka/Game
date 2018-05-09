#pragma once
#include <vector>
#include <iostream>
#include "Entidad.h"
#include "Ogre.h"
#include "InputComponent.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

class Escenas
{
public:
	Escenas();
	virtual ~Escenas();
	virtual bool run()  = 0;
protected:
	std::vector<Entidad*> entidades;
	


	///// FISICA
	btDiscreteDynamicsWorld* bulletWorld;
	////////////////
	
	InputComponent* inputcomp_;
	Ogre::Viewport* vp;
	Ogre::Camera* cam;
	Ogre::SceneNode* camNode;
	Ogre::Light* light;
	///// OGRE
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;
	////////////////
	

};