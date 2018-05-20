#include "Juego.h"
#include <iostream>
#include "Render_c.h"
#include "PlayerController_c.h"
#include "RigidBody_c.h"
#include "Objeto.h"
#include "Collider_c.h"
#include "StatsPJ_c.h"
#include "StatsEntJuego_c.h"
#include "PatrullarNPC.h"
#include "CameraMove_c.h"
#include "EntidadRender.h"
#include "Trigger_c.h"
#include "ComportamientoEnem_c.h"
using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
Juego::Juego(EscenasManager* escenasManager)
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

	camNode = scnMgr->getRootSceneNode()->createChildSceneNode();

	// create the camera
	cam = scnMgr->createCamera("Cam");
	cam->setNearClipDistance(0.1); 
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	cam->setQueryFlags(MY_QUERY_IGNORE);

	this->escenasManager = escenasManager;
	inputcomp_ = InputComponent::getSingletonPtr();
	inputcomp_->initialise(mWindow);
	//////////////////////////////////////////////////////rb del pj PRINCIPAL////////////////////////////////////////////////////
	Entidad* ent1 = new Entidad("p");
	//1683, 50, 2116
	ent1->setPox(1700);
	ent1->setPoy(5);
	ent1->setPoz(1800);
	Render_c* render = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode("p"), ent1, "Sinbad", "p");
	StatsPJ_c* stas = new StatsPJ_c(5, 10, 2, 100,this);
	ent1->AddComponent(stas);
	ent1->AddComponent(render);

	RigidBody_c* player_rb = new RigidBody_c(ent1, bulletWorld, 5, 5, 5, 1);
	player_rb->getRigidBody()->setCollisionFlags(player_rb->getRigidBody()->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	player_rb->getRigidBody()->setUserPointer(ent1);
	ent1->AddComponent(player_rb);
	PlayerController_c * ois = new PlayerController_c(ent1, inputcomp_, this, stas);
	ent1->AddComponent(ois);
	entidades.push_back(ent1);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Entidad* ent3 = new Entidad("GM");
	gm = new GameManager_c(ent1);
	ent3->AddComponent(gm);
	entidades.push_back(ent3);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	creaNpcMisiones(1700,5,1850,2,200,2,500,"p2");
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	creaOgreEnemyMele(1700, 5, 1750, "ogreEnemy1");
	creaOgreEnemyMele(1700, 5, 1750, "ogreEnemy2");
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	creaPan(1750,5,1750,"pan1");
	creaPan(1650, 5, 1700, "pan2");
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
	camNode->setPosition(Ogre::Vector3(ent1->getPox(), ent1->getPoy() + 10, ent1->getPoz() - 30));
	camNode->rotate(Ogre::Vector3(0, 0, 1), Ogre::Degree(180));
	camNode->lookAt(Ogre::Vector3(ent1->getPox(), ent1->getPoy() + 5, ent1->getPoz()), Ogre::Node::TS_WORLD);

	Entidad* entCamara = new Entidad("camara");
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
	mapa->getRigidBody()->setUserPointer(mapa);
}
void Juego::creaNpcMisiones(int x, int y, int z, int misionT1, int expM1, int misionT2, int expM2, std::string idRender){
	Entidad* ent2 = new EntidadRender("p2", idRender, scnMgr);
	ent2->setPox(x);// posicion 
	ent2->setPoy(y);
	ent2->setPoz(z);

	RigidBody_c* static_rb = new RigidBody_c(ent2, bulletWorld, 5, 5, 5, 1);
	static_rb->getRigidBody()->setCollisionFlags(static_rb->getRigidBody()->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	static_rb->getRigidBody()->setUserPointer(ent2);
	ent2->AddComponent(static_rb);
	PatrullarNPC* patrulla = new PatrullarNPC(10, ent2);
	ent2->AddComponent(patrulla);
	Mision_c* mision = new Mision_c(misionT1, "Pan", expM1, ent2);
	ent2->AddComponent(mision);
	Mision_c* mision2 = new Mision_c(misionT2, "ogroEnemy", expM2, ent2);
	ent2->AddComponent(mision2);
	entidades.push_back(ent2);
}
void Juego::creaPan(int x, int y, int z, std::string idRender){
	Entidad* ent = new EntidadRender("Pan",idRender,scnMgr);
	ent->setPox(x);// posicion 
	ent->setPoy(y);
	ent->setPoz(z);
	RigidBody_c* static_rb3 = new RigidBody_c(ent, bulletWorld, 5, 5, 5, 1);
	static_rb3->getRigidBody()->setCollisionFlags(static_rb3->getRigidBody()->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	static_rb3->getRigidBody()->setUserPointer(ent);
	ent->AddComponent(static_rb3);
	entidades.push_back(ent);
}
void Juego::creaOgreEnemyMele(int x, int y, int z, std::string idRender){
	EntidadRender* ent2 = new EntidadRender("ogroEnemy");
	ent2->setIdRender(idRender);
	ent2->setPox(x);// posicion 
	ent2->setPoy(y);
	ent2->setPoz(z);
	Render_c* render2 = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode(idRender), ent2, "Sinbad", idRender);
	ent2->AddComponent(render2);
	RigidBody_c* static_rb = new RigidBody_c(ent2, bulletWorld, 5, 5, 5, 1);
	static_rb->getRigidBody()->setCollisionFlags(static_rb->getRigidBody()->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	static_rb->getRigidBody()->setUserPointer(ent2);
	ent2->AddComponent(static_rb);
	ComportamientoEnem_c* compEnem = new ComportamientoEnem_c(ent2);
	ent2->AddComponent(compEnem);
	StatsEntJuego_c* statsE = new StatsEntJuego_c(2, 3, 2, this, ent2);
	ent2->AddComponent(statsE);
	entidades.push_back(ent2);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Entidad* trigger = new Entidad("trigger");
	trigger->setPox(x);// posicion 
	trigger->setPoy(y);
	trigger->setPoz(z);
	Trigger_c* t = new Trigger_c(trigger, ent2, bulletWorld, 50, 50, 50);
	t->actualizarPos(trigger->getPox(), trigger->getPoy(), trigger->getPoz());
	t->getTrigger()->setUserPointer(trigger);
	trigger->AddComponent(t);
	entidades.push_back(trigger);
}

bool callbackfunction(btManifoldPoint& cp, const btCollisionObjectWrapper * colObj0, int partId0, int index0, const btCollisionObjectWrapper * colObj1, int partId1, int index1){
	if (((Entidad*)colObj0->getCollisionObject()->getUserPointer()) != nullptr && ((Entidad*)colObj1->getCollisionObject()->getUserPointer()) != nullptr){
		if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "p2"){
			PlayerController_c* pC = new PlayerController_c();
			PatrullarNPC* patroll = new PatrullarNPC();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(1, (Entidad*)colObj1->getCollisionObject()->getUserPointer());
			((Entidad*)colObj1->getCollisionObject()->getUserPointer())->GetComponent(patroll)->chocasCon(1);
		}
		else if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "ogroEnemy"){
			PlayerController_c* pC = new PlayerController_c();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(2, ((Entidad*)colObj1->getCollisionObject()->getUserPointer()));
		}
        else if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "trigger"){
            //std::cout << "aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
			Trigger_c* trig = new Trigger_c();
			ComportamientoEnem_c* mE = new ComportamientoEnem_c();
			((Entidad*)colObj1->getCollisionObject()->getUserPointer())->GetComponent(trig)->getFather()->GetComponent(mE)->actua((Entidad*)colObj0->getCollisionObject()->getUserPointer());
        }
		else if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "Pan"){
			PlayerController_c* pC = new PlayerController_c();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(3, ((Entidad*)colObj1->getCollisionObject()->getUserPointer()));
		}
		else if (((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p"){
			PlayerController_c* pC = new PlayerController_c();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(0, nullptr);
		}
		else if (((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p2"){
			PatrullarNPC* patroll = new PatrullarNPC();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(patroll)->chocasCon(0);
		}
	}
	return false;
}
bool Juego::initBullet(){
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
bool Juego::run(){
	


	clock_t lastTicks = clock();
	clock_t elapsedTicks = 0;
	double deltaTime = 0;
	while (true)
	{
		deltaTime = ((double)elapsedTicks) / 1000.f/*CLOCKS_PER_SEC*/;
		lastTicks = clock();
		if (elapsedTicks >= 0.5){
			inputcomp_->capture();
			elapsedTicks = 0;
		}
		//Tick de la fisica
		bulletWorld->stepSimulation(1.f / 60.f, 10);

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
void Juego::activaMision(Entidad* npc){
	Mision_c* mision = new Mision_c();
	mision = npc->GetComponent(mision);
	if (mision != nullptr)
		gm->dameMision(mision);
}
void Juego::atacar(Entidad* npc){
	StatsEntJuego_c* stats = new StatsEntJuego_c();
	StatsPJ_c* statspj = new StatsPJ_c();
	npc->GetComponent(stats)->restaVida(entidades[0]->GetComponent(statspj)->getDamage());
}

void Juego::killAdd(Entidad* obj){
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
		bulletWorld->removeRigidBody(aux->GetComponent(rb)->getRigidBody());
		entidades.pop_back();
		scnMgr->destroyEntity(static_cast<EntidadRender*>(obj)->getIdRender());
	}
}
void Juego::muerteJugador(){
	escenasManager->GameToMenu();
}

Juego::~Juego()
{
	delete mapa;
	delete bulletWorld;
	delete collisionConfiguration;
	delete dispatcher;
	delete solver;
	delete broadPhase;

	scnMgr->getRootSceneNode()->removeAllChildren();
	root->destroySceneManager(scnMgr);
	root->destroyRenderTarget("P3");
	delete root;
}

