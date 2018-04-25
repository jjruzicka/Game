#pragma once
#include <vector>
#include <iostream>
#include "Entidad.h"
#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include <OgreCamera.h>
#include <OgreEntity.h>
#include "OgreSceneNode.h"
#include <OgreConfig.h>
#include "OgreConfigFile.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <OgreTextureManager.h>
#include <OgreWindowEventUtilities.h>
#include <OgreException.h>
#include "Mapa.h"
#include "InputComponent.h"
class Escenas
{
public:
	Escenas();
	~Escenas();
	bool run();
	bool initBullet();
private:

	bool initOgre();
	std::vector<Entidad*> entidades;


	btDiscreteDynamicsWorld* bulletWorld;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btBroadphaseInterface* broadPhase;


	Mapa* mapa;
	std::string recursos, plugins;
	Ogre::Root *root;
	Ogre::ConfigFile cf;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;
	Ogre::Light* light;
	Ogre::SceneNode* lightNode = nullptr;

	Ogre::Camera* cam = nullptr;
	Ogre::SceneNode* camNode = nullptr;

	InputComponent* inputcomp_;

};