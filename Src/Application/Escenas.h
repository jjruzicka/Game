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
#include "EscenasManager.h"




class Escenas 
{
public:
	Escenas();
	
	virtual ~Escenas();
	virtual bool run();
	

	///// OGRE
	std::string recursos, plugins;
	Ogre::Root *root;
	Ogre::ConfigFile cf;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;
	

	////////////////
	Ogre::Light* light;
	Ogre::SceneNode* lightNode = nullptr;
	Ogre::Camera* cam = nullptr;
	Ogre::Viewport* vp = nullptr;
	
	EscenasManager* escenasState;
	InputComponent* inputcomp_;
	/*virtual bool keyPressed(const OIS::KeyEvent &e){ return true; };
	virtual bool keyReleased(const OIS::KeyEvent &e){ return true; };
	virtual bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id){ return true; };
	virtual bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id){ return true; };
	virtual bool mouseMoved(const OIS::MouseEvent &arg){ return true; };*/

protected:
	bool initOgre();
	bool initCamera();
	

};