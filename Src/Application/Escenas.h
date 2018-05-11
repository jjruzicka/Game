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
#include "Mapa.h"
#include "InputComponent.h"
#include "GameManager_c.h"
class Escenas
{
public:
	Escenas();
	~Escenas();
	bool run();
	bool initBullet();
	void activaMision(Entidad* npc);
	void atacar(Entidad* npc);
	void killAdd(Entidad* obj);
private:

	bool initOgre();
	std::vector<Entidad*> entidades;
	
	GameManager_c* gm;
	//Variables usadas para la iniciacion de bullet
	btDiscreteDynamicsWorld* bulletWorld;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btBroadphaseInterface* broadPhase;

	//Varibales usadas por Ogre
	Mapa* mapa;
	std::string recursos, plugins;
	Ogre::Root *root;
	Ogre::ConfigFile cf;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;
	Ogre::Light* light;
	Ogre::SceneNode* lightNode = nullptr;

	Ogre::Camera* cam = nullptr;
	Ogre::SceneNode* camNode = nullptr;

	//Componente de imput
	InputComponent* inputcomp_;

};