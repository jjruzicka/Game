#ifndef MAPA_H
#define MAPA_H

#include "OgreSceneNode.h"
#include <OgreTerrain.h>
#include <OgreTerrainGroup.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "btHeightfieldTerrainShape.h"
#include <iostream>
#include "MotorGrafico.h"

class Mapa
{
public:
	Mapa(Ogre::Light* light);
	~Mapa();
	void createmap();
	void setPhysics();

private:
	MotorGrafico * motorGrafico;

	void defineTerrain(long x, long y);
	void initBlendMaps(Ogre::Terrain* terrain);
	void configureTerrainDefaults(Ogre::Light* light);
	

	Ogre::Light* luz;
	bool mTerrainsImported;
	Ogre::TerrainGroup* mTerrainGroup;
	Ogre::TerrainGlobalOptions* mTerrainGlobals;
};
#endif



