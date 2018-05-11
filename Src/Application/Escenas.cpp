#include "Escenas.h"
#include "Render_c.h"
#include "PlayerController_c.h"
#include "RigidBody_c.h"
#include "Objeto.h"
#include "Collider_c.h"
#include "StatsPJ_c.h"
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
	plugins = "Ogre/plugins.cfg";
	recursos = "Ogre/resources.cfg";
#endif
	initOgre();
	initBullet();
	

	
	inputcomp_ = InputComponent::getSingletonPtr();
	inputcomp_->initialise(mWindow);
	//////////////////////////////////////////////////////rb del pj PRINCIPAL////////////////////////////////////////////////////
	Entidad* ent1 = new Entidad("p");
	//1683, 50, 2116
	ent1->setPox(1700);// posicion 
	ent1->setPoy(10);
	ent1->setPoz(1800);
	Render_c* render = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode("p"), ent1, "Sinbad","p");
	StatsPJ_c* stas= new StatsPJ_c(5,10,2,100);
	PlayerController_c * ois = new PlayerController_c(ent1, inputcomp_,this ,stas);
	ent1->AddComponent(stas);
	ent1->AddComponent(render);
	ent1->AddComponent(ois);
	// RigidBody del personaje principal (KINEMATICO)
	RigidBody_c* player_rb = new RigidBody_c(ent1, physicType::kinematico, bulletWorld, 5, 5 ,5, 1);
    player_rb->getRigidBody()->setCollisionFlags(player_rb->getRigidBody()->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);

    player_rb->getRigidBody()->setUserPointer(ent1);
	ent1->AddComponent(player_rb);
	entidades.push_back(ent1);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////rb del PJ2////////////////////////////////////////////////////
	Entidad* ent2 = new Entidad("p2");
	ent2->setPox(1700);// posicion 
	ent2->setPoy(10);
	ent2->setPoz(1850);
	Render_c* render2 = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode("p2"), ent2, "Sinbad","p2");
	ent2->AddComponent(render2);
	
	RigidBody_c* static_rb = new RigidBody_c(ent2, physicType::kinematico, bulletWorld, 5, 5, 5, 1);
    static_rb->getRigidBody()->setCollisionFlags(static_rb->getRigidBody()->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
    static_rb->getRigidBody()->setUserPointer(ent2);
	ent2->AddComponent(static_rb);
	Mision_c* mision = new Mision_c(1,"ogroEnemy",500,ent2);
	ent2->AddComponent(mision);
	entidades.push_back(ent2);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Entidad* ent3 = new Entidad("GM");
	gm = new GameManager_c(ent1);
	ent3->AddComponent(gm);
	entidades.push_back(ent3);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Entidad* ent4 = new Entidad("ogroEnemy");
	ent4->setPox(1700);// posicion 
	ent4->setPoy(10);
	ent4->setPoz(1750);
	Render_c* render3 = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode("ogroEnemy"), ent4, "Sinbad", "ogroEnemy");
	ent4->AddComponent(render3);
	RigidBody_c* static_rb2 = new RigidBody_c(ent4, physicType::kinematico, bulletWorld, 5, 5, 5, 1);
	static_rb2->getRigidBody()->setCollisionFlags(static_rb2->getRigidBody()->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	static_rb2->getRigidBody()->setUserPointer(ent4);
	ent4->AddComponent(static_rb2);
	StatsEntJuego_c* statsE = new StatsEntJuego_c(2,10,2,this,ent4);
	ent4->AddComponent(statsE);
	entidades.push_back(ent4);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Ogre::Vector3 lightdir(0.55, -0.3, 0.75);
	lightdir.normalise();

	Ogre::Light* light = scnMgr->createLight("tstLight");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(lightdir);
	light->setDiffuseColour(Ogre::ColourValue::White);
	light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));

	scnMgr->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));

	// also need to tell where we are
	camNode = scnMgr->getSceneNode("p")->createChildSceneNode();
	camNode->setPosition(Ogre::Vector3(0, 5, -35));
	camNode->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3::UNIT_Y));
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	// create the camera
	cam = scnMgr->createCamera("Cam");
	cam->setNearClipDistance(0.1); //esto antes era 1
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	cam->setQueryFlags(MY_QUERY_IGNORE);




	// and tell it to render into the main window
	Viewport* vp;
	vp = mWindow->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));

	//Terrain
	mapa = new Mapa(scnMgr, light, bulletWorld);
	mapa->createmap();
	mapa->setPhysics();
    mapa->getRigidBody()->setUserPointer(mapa);
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
bool callbackfunction(btManifoldPoint& cp,const btCollisionObjectWrapper * colObj0,int partId0,int index0,const btCollisionObjectWrapper * colObj1,int partId1,int index1){
    if (((Entidad*)colObj0->getCollisionObject()->getUserPointer()) != nullptr && ((Entidad*)colObj1->getCollisionObject()->getUserPointer()) != nullptr){
        if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "p2"){
			PlayerController_c* pC = new PlayerController_c();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(1, (Entidad*)colObj1->getCollisionObject()->getUserPointer());
		}
		else if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "ogroEnemy"){
			PlayerController_c* pC = new PlayerController_c();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(2, ((Entidad*)colObj1->getCollisionObject()->getUserPointer()));
		}
		else if (((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p"){
			PlayerController_c* pC = new PlayerController_c();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(0,nullptr);
		}
    }
    return false;
}
bool Escenas::initBullet(){
    gContactAddedCallback = callbackfunction;
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
	bulletWorld->stepSimulation((float)deltaTime);
	//////////////////////////////////////
	RigidBody_c* RB = new RigidBody_c();
	/////////////////////////////////////
	while (true)
	{
		deltaTime = ((double)elapsedTicks) / 1000.f/*CLOCKS_PER_SEC*/;
		lastTicks = clock();
		if (elapsedTicks >= 0.5){
			inputcomp_->capture();
			elapsedTicks = 0;
		}
		//Tick de la fisica
		bulletWorld->stepSimulation((float)deltaTime);
		for (int i = 0; i < entidades.size(); i++)
			entidades[i]->Update();

		// render ogre
		Ogre::WindowEventUtilities::messagePump();
		//comprobar si la ventana está abierta
		if (mWindow->isClosed())return false;
		if (!root->renderOneFrame())return false;
		elapsedTicks = clock() - lastTicks;
	}
	return true;
}

void Escenas::activaMision(Entidad* npc){
	Mision_c* mision = new Mision_c();	
	mision = npc->GetComponent(mision);
	if (mision != nullptr)
		gm->dameMision(mision);
}
void Escenas::atacar(Entidad* npc){
	StatsEntJuego_c* stats = new StatsEntJuego_c();
	StatsPJ_c* statspj = new StatsPJ_c();
	npc->GetComponent(stats)->restaVida(entidades[0]->GetComponent(statspj)->getDamage());
}

void Escenas::killAdd(Entidad* obj){
	gm->killADDMision(obj->getID());
	int i = 0;
	bool encontrado = false;
	while (!encontrado && i < entidades.size()){
		if (obj == entidades[i])
			encontrado = true;
		else i++;
	}
	if (i < entidades.size()){
		Entidad* aux = entidades[i];
		entidades[i] = entidades[entidades.size() - 1];
		entidades[entidades.size() - 1] = aux;
		RigidBody_c* rb = new RigidBody_c();
		aux->GetComponent(rb)->getRigidBody()->setCollisionFlags(4);
		entidades.pop_back();
		scnMgr->destroyEntity(obj->getID());
	}
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

