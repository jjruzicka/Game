#ifndef ESCENAS_H
#define ESCENAS_H
#include <vector>
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
#include "InputManager.h"
#include "Mapa.h"

#include "MotorGrafico.h"
#include "MotorFisico.h"

class Escenas
{
public:
	Escenas();
	virtual ~Escenas();
	virtual bool run() = 0;
	

	virtual void addEntidad(Entidad * ent){
		entidades.push_back(ent);
	};

protected:

	MotorGrafico * motorGrafico;
	MotorFisico * motorFisico;
	std::vector<Entidad*> entidades;
	Ogre::Viewport* vp = nullptr;

	////////////////////////////////////
	Mapa* mapa;

	///// OGRE
	Ogre::Light* light;
	Ogre::SceneNode* lightNode = nullptr;
	Ogre::Camera* cam = nullptr;
	Ogre::SceneNode* camNode = nullptr;
	///////////////////////
};
#endif