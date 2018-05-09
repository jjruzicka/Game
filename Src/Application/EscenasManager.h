#pragma once
#include "Escenas.h"
#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include <OgreCamera.h>
#include <OgreEntity.h>
#include "OgreSceneNode.h"
#include <OgreConfig.h>
#include "OgreConfigFile.h"
#include <OgreTextureManager.h>
#include <OgreWindowEventUtilities.h>
#include <OgreException.h>
class EscenasManager
{
public:
	EscenasManager();
	~EscenasManager();
	bool run();
	void MenuToGame();
	void GameToMenu();
	
private:
	bool initOgre();
	bool initBullet();
	bool juegoB;//la B es de bool
	bool menuB;//la B es de bool
	Escenas* juego;
	Escenas* menu;
	///// OGRE
	std::string recursos, plugins;
	Ogre::Root *root;
	Ogre::ConfigFile cf;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;
	////////////////

	///// FISICA
	btDiscreteDynamicsWorld* bulletWorld;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btBroadphaseInterface* broadPhase;
	////////////////
};