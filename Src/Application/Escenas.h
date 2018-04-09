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

#include <OgreTextureManager.h>
#include <OgreWindowEventUtilities.h>
#include <OgreException.h>
#include <PxPhysics.h>
#include <PxPhysicsAPI.h>
#include <PxPhysXConfig.h>
#include "InputComponent.h"
class Escenas
{
public:
	Escenas();
	~Escenas();
	bool run();
	bool initPhysx();
private:

	bool initOgre();
	std::vector<Entidad*> entidades;

	physx::PxFoundation* mFoundation;
	physx::PxPhysics* mPhysics;
	physx::PxPvd* mPvd;
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