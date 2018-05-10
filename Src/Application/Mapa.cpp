#include "Mapa.h"


Mapa::Mapa(Ogre::SceneManager * scnMgr, Ogre::Light* light, btDiscreteDynamicsWorld* World) : mTerrainGroup(0), bulletWorld(World),
mTerrainGlobals(0), scn(scnMgr), luz(light)
{

}

void Mapa::createmap(){
	// Terrain
	
	mTerrainGlobals = OGRE_NEW Ogre::TerrainGlobalOptions();

	mTerrainGroup = OGRE_NEW Ogre::TerrainGroup(
		scn,
		Ogre::Terrain::ALIGN_X_Z,
		65, 12000.0);
	mTerrainGroup->setFilenameConvention(Ogre::String("terrain"), Ogre::String("dat"));
	mTerrainGroup->setOrigin(Ogre::Vector3::ZERO);

	configureTerrainDefaults(luz);

	for (long x = 0; x <= 0; ++x)
	for (long y = 0; y <= 0; ++y)
		defineTerrain(x, y);

	mTerrainGroup->loadAllTerrains(true);

	if (mTerrainsImported)
	{
		Ogre::TerrainGroup::TerrainIterator ti = mTerrainGroup->getTerrainIterator();

		while (ti.hasMoreElements())
		{
			Ogre::Terrain* t = ti.getNext()->instance;
			initBlendMaps(t);
			
		}
	}
	
	mTerrainGroup->freeTemporaryResources();
	
	scn->setSkyDome(true, "Examples/CloudySky", 5, 8);
}

void Mapa::setPhysics(){

	Ogre::Terrain* pTerrain = mTerrainGroup->getTerrain(0, 0);
	int terrainPageSize = pTerrain->getSize();

	float *pTerrainHeightData = pTerrain->getHeightData();
	float *pTerrainHeightDataConvert = new float [terrainPageSize * terrainPageSize];
	for (int i = 0; i < terrainPageSize; ++i)
	{
		memcpy(pTerrainHeightDataConvert + terrainPageSize * i,
			pTerrainHeightData + terrainPageSize * (terrainPageSize - i - 1),
			sizeof(float)*(terrainPageSize));
	}

	btHeightfieldTerrainShape* pHeightShape
		= new btHeightfieldTerrainShape(terrainPageSize,
		terrainPageSize,
		pTerrainHeightDataConvert,
		1, /* Terrains getHeightData() is already scaled perfectly */
		pTerrain->getMinHeight(),
		pTerrain->getMaxHeight(),
		1, /* upVector is Y positive in ogre-, bullet- and our world */
		PHY_FLOAT,
		true);

	// Scale the mesh along x/z
	float unitsBetweenVertices = pTerrain->getWorldSize() / (terrainPageSize - 1);
	btVector3 scaling(unitsBetweenVertices, 1, unitsBetweenVertices);
	pHeightShape->setLocalScaling(scaling);

	// Ogre uses DiamonSubdivision for Terrain-mesh, so bullet should use it too
	pHeightShape->setUseDiamondSubdivision(true);

	// Now we create a btRigidBody
	btRigidBody *pBody = new btRigidBody(0.0 /* mass 0.0 means static */,
		new btDefaultMotionState(),
		pHeightShape);

	// 
    //pBody->setCollisionFlags(4);
	Ogre::Vector3 terrainPosition = pTerrain->getPosition();
	pBody->getWorldTransform().setOrigin(btVector3(terrainPosition.x,
		terrainPosition.y
		+ (pTerrain->getMaxHeight() - pTerrain->getMinHeight()) / 2, // Bullet's position differs from Ogre's. Ogre's y is at the bottom, bullet needs the middle if the height to be positioned right
		terrainPosition.z));

	pBody->getWorldTransform().setRotation(btQuaternion(Ogre::Quaternion::IDENTITY.x,
		Ogre::Quaternion::IDENTITY.y,
		Ogre::Quaternion::IDENTITY.z,
		Ogre::Quaternion::IDENTITY.w));

	bulletWorld->addRigidBody(pBody);

}


void getTerrainImage(bool flipX, bool flipY, Ogre::Image& img)
{
	img.load("terrain.png", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

	if (flipX)
		img.flipAroundY();
	if (flipY)
		img.flipAroundX();

}

void Mapa::defineTerrain(long x, long y)
{
	Ogre::String filename = mTerrainGroup->generateFilename(x, y);

	bool exists =
		Ogre::ResourceGroupManager::getSingleton().resourceExists(
		mTerrainGroup->getResourceGroup(),
		filename);

	if (exists)
		mTerrainGroup->defineTerrain(x, y);
	else
	{
		Ogre::Image img;
		getTerrainImage(x % 2 != 0, y % 2 != 0, img);
		mTerrainGroup->defineTerrain(x, y, &img);

		mTerrainsImported = true;
	}
}

void Mapa::initBlendMaps(Ogre::Terrain* terrain)
{
	Ogre::Real minHeight0 = 70;
	Ogre::Real fadeDist0 = 40;
	Ogre::Real minHeight1 = 70;
	Ogre::Real fadeDist1 = 15;

	Ogre::TerrainLayerBlendMap* blendMap0 = terrain->getLayerBlendMap(1);
	Ogre::TerrainLayerBlendMap* blendMap1 = terrain->getLayerBlendMap(2);

	float* pBlend0 = blendMap0->getBlendPointer();
	float* pBlend1 = blendMap1->getBlendPointer();

	for (Ogre::uint16 y = 0; y < terrain->getLayerBlendMapSize(); ++y)
	{
		for (Ogre::uint16 x = 0; x < terrain->getLayerBlendMapSize(); ++x)
		{
			Ogre::Real tx, ty;

			blendMap0->convertImageToTerrainSpace(x, y, &tx, &ty);
			Ogre::Real height = terrain->getHeightAtTerrainPosition(tx, ty);
			Ogre::Real val = (height - minHeight0) / fadeDist0;
			val = Ogre::Math::Clamp(val, (Ogre::Real)0, (Ogre::Real)1);
			*pBlend0++ = val;

			val = (height - minHeight1) / fadeDist1;
			val = Ogre::Math::Clamp(val, (Ogre::Real)0, (Ogre::Real)1);
			*pBlend1++ = val;
		}
	}

	blendMap0->dirty();
	blendMap1->dirty();
	blendMap0->update();
	blendMap1->update();

}

void Mapa::configureTerrainDefaults(Ogre::Light* light)
{
	mTerrainGlobals->setMaxPixelError(8);
	mTerrainGlobals->setCompositeMapDistance(3000);

	mTerrainGlobals->setLightMapDirection(light->getDerivedDirection());
	mTerrainGlobals->setCompositeMapAmbient(scn->getAmbientLight());
	mTerrainGlobals->setCompositeMapDiffuse(light->getDiffuseColour());

	Ogre::Terrain::ImportData& importData = mTerrainGroup->getDefaultImportSettings();
	importData.terrainSize = 65;
	importData.worldSize = 12000.0;
	importData.inputScale = 600;
	importData.minBatchSize = 33;
	importData.maxBatchSize = 65;

	importData.layerList.resize(3);
	importData.layerList[0].worldSize = 100;
	importData.layerList[0].textureNames.push_back(
		"dirt_grayrocky_diffusespecular.dds");
	importData.layerList[0].textureNames.push_back(
		"dirt_grayrocky_normalheight.dds");
	importData.layerList[1].worldSize = 30;
	importData.layerList[1].textureNames.push_back(
		"grass_green-01_diffusespecular.dds");
	importData.layerList[1].textureNames.push_back(
		"grass_green-01_normalheight.dds");
	importData.layerList[2].worldSize = 200;
	importData.layerList[2].textureNames.push_back(
		"growth_weirdfungus-03_diffusespecular.dds");
	importData.layerList[2].textureNames.push_back(
		"growth_weirdfungus-03_normalheight.dds");

}


Mapa::~Mapa()
{
	OGRE_DELETE mTerrainGroup;
	OGRE_DELETE mTerrainGlobals;
}
