#pragma once

#include "OgreSceneNode.h"
#include <OgreTerrain.h>
#include <OgreTerrainGroup.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "btHeightfieldTerrainShape.h"
#include <iostream>

class Mapa
{
public:
	Mapa(Ogre::SceneManager * scnMgr, Ogre::Light* light, btDiscreteDynamicsWorld* World);
	~Mapa();
	void createmap();
	void setPhysics();

private:
	void defineTerrain(long x, long y);
	void initBlendMaps(Ogre::Terrain* terrain);
	void configureTerrainDefaults(Ogre::Light* light);
	
	Ogre::SceneManager * scn;
	Ogre::Light* luz;
	btDiscreteDynamicsWorld* bulletWorld;
	bool mTerrainsImported;
	Ogre::TerrainGroup* mTerrainGroup;
	Ogre::TerrainGlobalOptions* mTerrainGlobals;
	//OgreBites::Label* mInfoLabel;

};



