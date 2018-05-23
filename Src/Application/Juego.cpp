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
PlayerController_c* pC;
PatrullarNPC* patroll;
Trigger_c* trig;
ComportamientoEnem_c* mE;
Mision_c* mision;
StatsEntJuego_c* stats;
StatsPJ_c* statspj;
RigidBody_c* rb;

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
	
	cont = 0;
	this->escenasManager = escenasManager;
	inputcomp_ = InputComponent::getSingletonPtr();
	inputcomp_->initialise(mWindow);
	inputcomp_->addKeyListener(this, "teclado3");
	inputcomp_->addMouseListener(this, "raton3");

	// create the camera
	cam = scnMgr->createCamera("Cam");
	cam->setNearClipDistance(0.1); //esto antes era 1
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	cam->setQueryFlags(MY_QUERY_IGNORE);
	//////////////////////////////////////////////////////rb del pj PRINCIPAL////////////////////////////////////////////////////
	Entidad* ent1 = new Entidad("p");
	//1683, 50, 2116
	ent1->setPox(1700);
	ent1->setPoy(5);
	ent1->setPoz(1800);
	Render_c* render = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode("p"), ent1, "Sinbad", "p");
	StatsPJ_c* stas = new StatsPJ_c(100, 20, 50, 50,this,ent1);
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
	creaNpcMisiones(1700,5,1850,3,125,1,300,3,650,3,1400,1,3200,"p2");
	/////////////////////////////////////	MISION  1	////////////////////////////////////////////////////////////////////
	creaPan(1750, 5, 1750, "pan1");
	creaPan(1650, 5, 1700, "pan2");
	creaPan(1700, 5, 1650, "pan3");
	/////////////////////////////////////	MISION  2	////////////////////////////////////////////////////////////////////
	creaOgreEnemyMele(1900, 5, 1800,100,25,0, "ogreEnemy1");
	/////////////////////////////////////	MISION  3	////////////////////////////////////////////////////////////////////
	creaOgreEnemyMele(1700, 5, 2100, 200, 45, 50, "ogreEnemy2");
	creaOgreEnemyMele(1800, 5, 2100, 200, 45, 50, "ogreEnemy3");
	creaOgreEnemyMele(1650, 5, 2100, 200, 45, 50, "ogreEnemy4");
	/////////////////////////////////////	MISION  4	////////////////////////////////////////////////////////////////////
	creaOgreEnemyMele(1400, 5, 1800, 200, 80, 100, "ogreEscolta1");
	creaOgreEnemyMele(1400, 5, 1800, 200, 80, 100, "ogreEscolta2");
	creaOgreEnemyMele(1250, 5, 1800, 400, 125, 200, "ogreBoss");
	/////////////////////////////////////	MISION  5	////////////////////////////////////////////////////////////////////
	creaPan(1200, 5, 1800, "prisionero");
	/////////////////////////////////////	Extra   1	////////////////////////////////////////////////////////////////////
	creaOgreEnemyMele(1700, 5, 1450, 700, 250, 200, "muerte1");
	creaOgreEnemyMele(1250, 5, 1500, 500, 300, 200, "muerte2");
	creaOgreEnemyMele(1700, 5, 2300, 600, 225, 200, "muerte3");
	creaOgreEnemyMele(1700, 5, 2300, 1500, 25, 200, "muerte4");
	creaOgreEnemyMele(1050, 5, 1800, 1000, 420, 200, "muerte5");




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

	//// also need to tell where we are
	//camNode = scnMgr->getSceneNode("p")->createChildSceneNode();
	//camNode->setPosition(Ogre::Vector3(0, 5, -35));
	//camNode->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3::UNIT_Y));
	//camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	//// create the camera
	//cam = scnMgr->createCamera("Cam");
	//cam->setNearClipDistance(0.1); //esto antes era 1
	//cam->setFarClipDistance(10000);
	//cam->setAutoAspectRatio(true);
	//camNode->attachObject(cam);
	//cam->setQueryFlags(MY_QUERY_IGNORE);


	// and tell it to render into the main window
	Viewport* vp;
	vp = mWindow->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));

	//GUI
	guiGame = new GUI(inputcomp_, vp, scnMgr, cam, camNode, this, false);	
	guiGame->createUI();
	//Terrain
	mapa = new Mapa(scnMgr, light, bulletWorld);
	mapa->createmap();
	mapa->setPhysics();
	mapa->getRigidBody()->setUserPointer(mapa);

	numArboles = 30;
	contArboles = 0;
	arbolitos.reserve(numArboles);
	createArbolitos();

	pC = new PlayerController_c();
	patroll = new PatrullarNPC();
	trig = new Trigger_c();
	mE = new ComportamientoEnem_c();
	mision = new Mision_c();
	stats = new StatsEntJuego_c();
	statspj = new StatsPJ_c();
	rb = new RigidBody_c();
}
void Juego::createArbolitos(){
	for (int i = 0; i < numArboles; i++){
		std::stringstream ss;

		ss << i;
		std::string str = ss.str();
		arbolitos.push_back(new Entidad(str));
		arbolitos[i]->setPox(rand() % 12000);// posicion 
		arbolitos[i]->setPoy(250);
		arbolitos[i]->setPoz(rand() % 12000);

		Render_c* render8 = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode(str), arbolitos[i], "tree.09", str);
		arbolitos[i]->AddComponent(render8);
		RigidBody_c* static_rb7 = new RigidBody_c(arbolitos[i], bulletWorld, 50, 50, 50, 0);
		static_rb7->getRigidBody()->setCollisionFlags(static_rb7->getRigidBody()->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
		static_rb7->getRigidBody()->setUserPointer(arbolitos[i]);
		arbolitos[i]->AddComponent(static_rb7);
		entidades.push_back(arbolitos[i]);
	}
}


void Juego::creaNpcMisiones(int x, int y, int z, int misionT1, int expM1, int misionT2, int expM2, int misionT3, int expM3, int misionT4, int expM4, int misionT5, int expM5, std::string idRender){
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
	Mision_c* mision9 = new Mision_c(1, "ogroEnemy", 4000, ent2);
	ent2->AddComponent(mision9);
	Mision_c* mision8 = new Mision_c(2, "ogroEnemy", 4500, ent2);
	ent2->AddComponent(mision8);
	Mision_c* mision7 = new Mision_c(1, "ogroEnemy", 1000, ent2);
	ent2->AddComponent(mision7);
	Mision_c* mision6 = new Mision_c(1, "ogroEnemy", 2000, ent2);
	ent2->AddComponent(mision6);
	Mision_c* mision5 = new Mision_c(misionT5, "Pan", expM5, ent2);
	ent2->AddComponent(mision5);
	Mision_c* mision4 = new Mision_c(misionT4, "ogroEnemy", expM4, ent2);
	ent2->AddComponent(mision4);
	Mision_c* mision3 = new Mision_c(misionT3, "ogroEnemy", expM3, ent2);
	ent2->AddComponent(mision3);
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

bool Juego::keyPressed(const OIS::KeyEvent& keyP){
	switch (keyP.key)
	{
	case OIS::KC_M:
		switch (cont){
		case 0:
			break;
		case 1:
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return true;
}
bool Juego::keyReleased(const OIS::KeyEvent& keyP){

	switch (keyP.key)
	{
	case OIS::KC_M:

		cont++;
		break;
	default:
		break;
	}
	return true;
}


void Juego::creaOgreEnemyMele(int x, int y, int z, int vida, int damage, int armor, std::string idRender){
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
	StatsEntJuego_c* statsE = new StatsEntJuego_c(vida, armor, damage, this, ent2);
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
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(1, (Entidad*)colObj1->getCollisionObject()->getUserPointer());
			((Entidad*)colObj1->getCollisionObject()->getUserPointer())->GetComponent(patroll)->chocasCon(1);
		}
		else if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "ogroEnemy"){
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(2, ((Entidad*)colObj1->getCollisionObject()->getUserPointer()));
		}
        else if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "trigger"){
			((Entidad*)colObj1->getCollisionObject()->getUserPointer())->GetComponent(trig)->getFather()->GetComponent(mE)->actua((Entidad*)colObj0->getCollisionObject()->getUserPointer());
        }
		else if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "Pan"){
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(3, ((Entidad*)colObj1->getCollisionObject()->getUserPointer()));
		}
		else if (((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p"){
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(0, nullptr);
		}
		else if (((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p2"){
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
void Juego::updateGUI(){

	//VIDA
	std::ostringstream s;
	s << "Vida: " << std::fixed << entidades[0]->GetComponent(statspj)->getVida() << " / " << std::fixed << entidades[0]->GetComponent(statspj)->getVidaMax();
	guiGame->getCaptionVida()->text(s.str());

	//DAMAGE
	std::ostringstream a;
	a << "Damage: " << std::fixed << entidades[0]->GetComponent(statspj)->getDamage();
	guiGame->getCaptionDamage()->text(a.str());

	//EXPERIENCIA
	std::ostringstream b;
	b << "Exp: " << std::fixed << entidades[0]->GetComponent(statspj)->getExpRestante();
	guiGame->getCaptionExp()->text(b.str());

	//NIVEL
	std::ostringstream c;
	c << "Nivel: " << std::fixed << entidades[0]->GetComponent(statspj)->getNivel();
	guiGame->getCaptionNivel()->text(c.str());

	//Curacion
	std::ostringstream z;
	PlayerController_c * playerC = entidades[0]->GetComponent(pC);
	if (playerC->getCdCuracion() <= playerC->getContCuracion())
		z << "Curacion disponible pulsa Q";
	else
		z << "Curacion en CD";
	guiGame->getCaptionCura()->text(z.str());
	//MISION
	std::ostringstream x,x2,x3;
	if (gm->getMisionIsActive()){
		if (gm->getObjetive() == "Pan")
			x << "Recolecta: " << gm->getObjetive();
		else
			x << "Mata: " << gm->getObjetive();
		guiGame->getMisionActiva1()->text(x.str());

		x2 << "LLeva: " << gm->getObjetiveCOnt() << " / " << gm->getObjetiveNum();
		guiGame->getMisionActiva2()->text(x2.str());

		x3 << "Exp dada: " << gm->getObjetiveExp();
		guiGame->getMisionActiva3()->text(x3.str());
	}
	else{
		x << "No hay misiones activas";
		guiGame->getMisionActiva1()->text(x.str());

		x2 << "Habla al npc";
		guiGame->getMisionActiva2()->text(x2.str());

		x3 << " ";
		guiGame->getMisionActiva3()->text(x3.str());
	}

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
		updateGUI();
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
	mision = new Mision_c();
	mision = npc->GetComponent(mision);
	if (mision != nullptr){
		gm->dameMision(mision);
	}
}
void Juego::atacar(Entidad* npc){
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

	delete guiGame;

	scnMgr->getRootSceneNode()->removeAllChildren();
	root->destroySceneManager(scnMgr);
	root->destroyRenderTarget("P3");
	delete root;
}

