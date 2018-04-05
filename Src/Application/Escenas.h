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
class Escenas
{
public:
	Escenas();
	~Escenas();
	bool run();
    Ogre::RenderWindow* getWindow(){ return mWindow; }
private:

	bool initOgre();
	bool initOIS();
	std::vector<Entidad*> entidades;


	std::string recursos, plugins;
	Ogre::Root *root;
	Ogre::ConfigFile cf;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;
	Ogre::Light* light;
	Ogre::SceneNode* lightNode = nullptr;

	Ogre::Camera* cam = nullptr;
	Ogre::SceneNode* camNode = nullptr;
	/*  //Gestor de paneles

	OgreBites::CameraMan* camMan = nullptr;
	SinbadMan* sinBadMgr = nullptr;
	KnotFly* knotMgr = nullptr;
	BombMan* bombMgr = nullptr;

	ReflejoMan* planeMgr = nullptr;

	std::vector<ObjectMan*> vecObjMan;

	Ogre::SceneManager* scnMgr = nullptr;

  OgreBites::TrayManager* trayMgr = nullptr;
  Ogre::SceneNode* lightNode = nullptr;
  Ogre::SceneNode* camNode = nullptr;
  Ogre::RaySceneQuery * rayScnQuery = nullptr;
  Ogre::Camera* cam = nullptr;
  */

};

