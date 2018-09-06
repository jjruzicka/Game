#ifndef MOTORGRAFICO
#define MOTORGRAFICO
#include <iostream>
#include <string>

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





class MotorGrafico
{
public:
	static MotorGrafico * getInstancia(){
		if (instancia == nullptr)
			instancia = new MotorGrafico();
		return instancia;
	}

	Ogre::Root * getRoot(){ return root; };
	Ogre::RenderWindow* getWindow(){ return mWindow; }
	Ogre::SceneManager * getSceMgr(){ return scnMgr; }

private:
	static MotorGrafico * instancia;
	MotorGrafico();
	virtual ~MotorGrafico();
	bool initOgre();

	std::string recursos, plugins;
	Ogre::Root *root;
	Ogre::ConfigFile cf;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;
};
#endif
