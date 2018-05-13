#pragma once
#include "Estados.h"
#include "EscenasManager.h"
//#include <btBulletCollisionCommon.h>
//#include <btBulletDynamicsCommon.h>
class Juego : public Estados
{
public:
	Juego(Escenas* scn);
	virtual ~Juego();
	
	

private:
	bool initBullet();
	virtual void update(){};
	
	Escenas* scnM;
	Ogre::Light* light;
	Ogre::SceneNode* lightNode = nullptr;
	Ogre::Camera* cam = nullptr;
	Ogre::SceneNode* camNode = nullptr;
	MyPurplePanelColors mMyPurplePanelColors;
	Ogre::Viewport* vp = nullptr;

	Mapa* mapa;

	
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btBroadphaseInterface* broadPhase;
	///// FISICA
	
	////////////////
	//variables vienen de escenas.h
};