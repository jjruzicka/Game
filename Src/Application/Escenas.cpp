#include "Escenas.h"
#include "Render_c.h"
#include "PlayerController_c.h"
//#include "RigidBody_c.h"
#include "Objeto.h"
#include "Collider_c.h"
#include "CameraMove_c.h"
using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
Escenas::Escenas()
{
#ifdef _DEBUG
	plugins = "OgreD/plugins_d.cfg";
	recursos = "OgreD/resources_d.cfg";
#else
	plugins = "OgreD/plugins.cfg";
	recursos = "OgreD/resources.cfg";
#endif
	initOgre();
	initBullet();
	
	camNode = scnMgr->getRootSceneNode()->createChildSceneNode();

	// create the camera
	cam = scnMgr->createCamera("Cam");
	cam->setNearClipDistance(0.1); //esto antes era 1
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	//cam->setPolygonMode(Ogre::PM_WIREFRAME);  // en material
	camNode->attachObject(cam);
	cam->setQueryFlags(MY_QUERY_IGNORE);


	
	inputcomp_ = InputComponent::getSingletonPtr();
	inputcomp_->initialise(mWindow);
	//////////////////////////////////////////////////////rb del pj PRINCIPAL////////////////////////////////////////////////////
	Entidad* ent1 = new Entidad();
	//1683, 50, 2116
	ent1->setPox(1700);// posicion 
	ent1->setPoy(50);
	ent1->setPoz(2000);
	Render_c* render = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode("personaje"), ent1, "Sinbad","Sinbad");
	PlayerController_c * ois = new PlayerController_c(ent1, inputcomp_);
	ent1->AddComponent(render);
	ent1->AddComponent(ois);
	entidades.push_back(ent1);
	btCollisionShape* fallShape = new btBoxShape(btVector3(10,5,10));
	btDefaultMotionState* fallMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(ent1->getPox(), ent1->getPoy(), ent1->getPoz())));
	btScalar mass = 1;
	btVector3 fallInertia(0, 9.8f, 0);
	fallShape->calculateLocalInertia(mass, fallInertia);
	//btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, fallShape, fallInertia);
	//RigidBody_c* rb = new RigidBody_c(ent1, fallRigidBodyCI);
	//ent1->AddComponent(rb);
	//bulletWorld->addRigidBody(rb->getRigidbody());
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////rb del PJ2////////////////////////////////////////////////////
	/*Entidad* ent2 = new Entidad();
	entidades.push_back(ent2);
	ent2->setPox(1700);// posicion 
	ent2->setPoy(25);
	ent2->setPoz(2000);
	Render_c* render2 = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode("personaje2"), ent2, "Sinbad","Sinbad2");
	ent2->AddComponent(render2);
	btCollisionShape* fallShape2 = new btBoxShape(btVector3(10, 5, 10));
	btDefaultMotionState* fallMotionState2 = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(ent2->getPox(), ent2->getPoy(), ent2->getPoz())));
	btScalar mass2 = 1;
	btVector3 fallInertia2(0, 9.8f, 0);
	fallShape2->calculateLocalInertia(mass2, fallInertia2);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI2(mass2, fallMotionState2, fallShape2, fallInertia2);
	RigidBody_c* rb2 = new RigidBody_c(ent2, fallRigidBodyCI2);
	ent2->AddComponent(rb2);
	bulletWorld->addRigidBody(rb2->getRigidbody());*/
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Ogre::Vector3 lightdir(0.55, -0.3, 0.75);
	lightdir.normalise();

	Ogre::Light* light = scnMgr->createLight("tstLight");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(lightdir);
	light->setDiffuseColour(Ogre::ColourValue::White);
	light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));

	scnMgr->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));

	/*// also need to tell where we are
	camNode = scnMgr->getSceneNode("personaje")->createChildSceneNode();
	camNode->setPosition(Ogre::Vector3(0, 5, -35));
	camNode->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3::UNIT_Y));
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	// create the camera
	cam = scnMgr->createCamera("Cam");
	cam->setNearClipDistance(0.1); //esto antes era 1
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	cam->setQueryFlags(MY_QUERY_IGNORE);*/

	camNode->setPosition(Ogre::Vector3(ent1->getPox(), ent1->getPoy() + 20, ent1->getPoz() - 30));
	camNode->rotate(Ogre::Vector3(0, 0, 1), Ogre::Degree(180));
	camNode->lookAt(Ogre::Vector3(ent1->getPox(), ent1->getPoy(), ent1->getPoz()), Ogre::Node::TS_WORLD);

	Entidad* entCamara = new Entidad();
	CameraMove_c* camMove = new CameraMove_c(entCamara, ent1, camNode, inputcomp_);
	entCamara->AddComponent(camMove);
	entidades.reserve(1);
	entidades.push_back(entCamara);


	// and tell it to render into the main window
	Viewport* vp;
	vp = mWindow->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));

	//Terrain
	mapa = new Mapa(scnMgr, light, bulletWorld);
	mapa->createmap();
	mapa->setPhysics();
}
bool Escenas::initOgre(){

	//------------------------------------------------------------------------------------------------------
	//Setting UP Resources 

	//Parsing the config file into the system.
	root = new Ogre::Root(plugins);
	try{
		cf.load(recursos);
	}
	catch (Ogre::Exception e){
		std::cout << "\n" << e.getFile();
	}

	//name: Path to resources in disk,
	//loctype: defines what kind of location the element is (e.g. Filesystem, zip..)
	Ogre::String name, locType;

	//We now iterate through rach section in the resources.cfg.
	//Sections are signaled as [NAME]
	Ogre::ConfigFile::SectionIterator secIt = cf.getSectionIterator();
	while (secIt.hasMoreElements())
	{
		Ogre::ConfigFile::SettingsMultiMap* settings = secIt.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator it;

		//Now we are iterating INSIDE the section [secIt]
		for (it = settings->begin(); it != settings->end(); ++it)
		{
			locType = it->first;
			name = it->second;

			//We now know the type of the element and its path.
			//We add it as a location to the Resource Group Manager
			try {
				Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, locType);
				std::cout << "inserting:\n";
				std::cout << name << locType << std::endl;
			}
			catch (Ogre::Exception e)
			{

			}
		}
	}
	//------------------------------------------------------------------------------------------------------
	// Render System Config

	//If there is no previous Ogre.cfg, this displays the config dialog
	if (!(root->restoreConfig() || root->showConfigDialog()))
		return false;

	//------------------------------------------------------------------------------------------------------
	//Render Window Creation
	mWindow = root->initialise(true, "P3");

	//------------------------------------------------------------------------------------------------------
	//Resources Init

	//We are only going to use 5 mimpams at a time. Mipmaps are efficent ways to save a texture.
	//Taking only 1/3 more of space, we can have several sizes of the texture to choose from.
	Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

	//Now we init every resource previously added
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	//------------------------------------------------------------------------------------------------------
	//SceneManager Set Up

	//we generate the default sceneManager. (more SceneManagers in Ogre::ST_....)
	scnMgr = root->createSceneManager(Ogre::ST_GENERIC);


	return true;
}
bool Escenas::initBullet(){
	//build the broadPhase
	broadPhase = new btDbvtBroadphase();

	//Set up the collision configuration and dispacher
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);

	//the actual physics solver
	solver = new btSequentialImpulseConstraintSolver();

	//the world
	bulletWorld = new btDiscreteDynamicsWorld(dispatcher, broadPhase, solver, collisionConfiguration);
	bulletWorld->setGravity(btVector3(0, -10, 0));
	return true;
}

bool Escenas::run(){
	

	clock_t lastTicks = clock();
	clock_t elapsedTicks = 0;
	double deltaTime = 0;

	while (true)
	{
		deltaTime = ((double)elapsedTicks) / 1000.f/*CLOCKS_PER_SEC*/;
		lastTicks = clock();

		inputcomp_->capture();

		for (int i = 0; i<entidades.size(); i++)
			entidades[i]->Update();

		

		// render ogre
		Ogre::WindowEventUtilities::messagePump();
		//Tick de la fisica
		bulletWorld->stepSimulation((float)deltaTime);
		
		//comprobar si la ventana est� abierta
		if (mWindow->isClosed())return false;
		if (!root->renderOneFrame())return false;
		elapsedTicks = clock() - lastTicks;
	}
	return true;
}


Escenas::~Escenas()
{
	for (int i = 0; i < entidades.size(); i++)
		delete entidades[i];

	delete bulletWorld;
	delete collisionConfiguration;
	delete dispatcher;
	delete solver;
	delete broadPhase;
}

