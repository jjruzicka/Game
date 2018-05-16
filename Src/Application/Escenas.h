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
#include "InputComponent.h"
#include "Mapa.h"

class Escenas
{
public:
	Escenas();
	virtual ~Escenas();
	virtual bool run() = 0;
	
	virtual btDynamicsWorld* getBulletWorld(){
		return bulletWorld;
	};

	virtual void addEntidad(Entidad * ent){
		entidades.push_back(ent);
	};

	virtual Ogre::SceneManager * getSceneManger(){
		return scnMgr;
	}

protected:


	virtual bool initBullet();
	virtual bool initOgre();
	std::vector<Entidad*> entidades;
	Ogre::Viewport* vp = nullptr;


	///// FISICA
	btDynamicsWorld* bulletWorld;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btBroadphaseInterface* broadPhase;	
	InputComponent* inputcomp_;
	////////////////////////////////////
	Mapa* mapa;

	///// OGRE
	std::string recursos, plugins;
	Ogre::Root *root;
	Ogre::ConfigFile cf;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;
	Ogre::Light* light;
	Ogre::SceneNode* lightNode = nullptr;
	Ogre::Camera* cam = nullptr;
	Ogre::SceneNode* camNode = nullptr;
	///////////////////////
};