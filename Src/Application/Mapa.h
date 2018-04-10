#pragma once

#include "OgreSceneNode.h"
#include <OgreTerrain.h>
#include <OgreTerrainGroup.h>
#include <iostream>

class Mapa
{
public:
	Mapa(Ogre::SceneManager * scnMgr, Ogre::Light* light);
	~Mapa();
	void createmap();
private:
	void defineTerrain(long x, long y);
	void initBlendMaps(Ogre::Terrain* terrain);
	void configureTerrainDefaults(Ogre::Light* light);

	Ogre::SceneManager * scn;
	Ogre::Light* luz;
	bool mTerrainsImported;
	Ogre::TerrainGroup* mTerrainGroup;
	Ogre::TerrainGlobalOptions* mTerrainGlobals;
	//OgreBites::Label* mInfoLabel;

};



