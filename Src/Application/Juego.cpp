#include "Juego.h"
#include <iostream>
#include "Render_c.h"
#include "PlayerController_c.h"
#include "RigidBody_c.h"
#include "StatsPJ_c.h"
#include "StatsEntJuego_c.h"
#include "PatrullarNPC.h"
#include "CameraMove_c.h"
#include "EntidadRender.h"
#include "Trigger_c.h"
#include "ComportamientoEnem_c.h"
#include <stdio.h>
#include <fstream>
using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};

PlayerController_c* pC;
Mision_c* mision;
StatsEntJuego_c* stats;
StatsPJ_c* statspj;
RigidBody_c* rb;
Render_c * render;

Juego::Juego(std::string path)
{
	motorFisico = MotorFisico::getInstancia();
	motorGrafico = MotorGrafico::getInstancia();

	camNode = motorGrafico->getSceMgr()->getRootSceneNode()->createChildSceneNode();
	
	cont = 0;

	// create the camera
	cam = motorGrafico->getSceMgr()->createCamera("CamJuego");
	cam->setNearClipDistance(0.1); //esto antes era 1
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	cam->setQueryFlags(MY_QUERY_IGNORE);
	//////////////////////////////////////////////////////rb del pj PRINCIPAL////////////////////////////////////////////////////
	entidadFactory(path);
	/*
	Entidad* ent3 = new Entidad("GM");
	gm = new GameManager_c(ent1);
	ent3->AddComponent(gm);
	entidades.push_back(ent3);
*/

	Ogre::Vector3 lightdir(0.55, -0.3, 0.75);
	lightdir.normalise();

	Ogre::Light* light = motorGrafico->getSceMgr()->createLight("tstLight2");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(lightdir);
	light->setDiffuseColour(Ogre::ColourValue::White);
	light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));

	motorGrafico->getSceMgr()->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));

	// also need to tell where we are
	camNode->setPosition(Ogre::Vector3(entidades[0]->getPox(), entidades[0]->getPoy() + 10, entidades[0]->getPoz() - 30));
	camNode->rotate(Ogre::Vector3(0, 0, 1), Ogre::Degree(180));
	camNode->lookAt(Ogre::Vector3(entidades[0]->getPox(), entidades[0]->getPoy() + 5, entidades[0]->getPoz()), Ogre::Node::TS_WORLD);

	Entidad* entCamara = new Entidad("camara");
	//CameraMove_c* camMove = new CameraMove_c(entCamara, ent1, camNode, inputcomp_);
	//entCamara->AddComponent(camMove);
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
	motorGrafico->getWindow()->removeAllViewports();
	vp = motorGrafico->getWindow()->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));

	//GUI
	//guiGame = new GUI(inputcomp_, vp, motorGrafico->getSceMgr(), cam, camNode, this, false);
	//guiGame->createUI();
	//Terrain
	mapa = new Mapa(motorGrafico->getSceMgr(), light, motorFisico->getBulletWorld());
	mapa->createmap();
	mapa->setPhysics();
	mapa->getRigidBody()->setUserPointer(mapa);

	/*numArboles = 30;
	contArboles = 0;
	arbolitos.reserve(numArboles);
	createArbolitos();*/

	stats = new StatsEntJuego_c();
	statspj = new StatsPJ_c();
	render = new Render_c();
	pC = new PlayerController_c();
	mision = new Mision_c();
	stats = new StatsEntJuego_c();
	statspj = new StatsPJ_c();
	rb = new RigidBody_c();
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
	
	//Tick de la fisica
	motorFisico->getBulletWorld()->stepSimulation(1.f / 60.f, 10);
	//updateGUI();
	for (int i = 0; i < entidades.size(); i++)
		entidades[i]->Update();
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
		motorFisico->getBulletWorld()->removeRigidBody(aux->GetComponent(rb)->getRigidBody());
		entidades.pop_back();
		motorGrafico->getSceMgr()->destroyEntity(obj->GetComponent(render)->getIDRender());
	}
}
void Juego::muerteJugador(){
	//escenasManager->GameToMenu();
}

void Juego::entidadFactory(std::string path){
	int contPan = 1, contEnemigo = 1, contArbol = 1;
	bool finish = false;
	std::ifstream file(path);
	//If the map couldn`t be loaded
	if (false)
	{
		std::cout << "Unable to load map file!\n";
	}
	else{
		while (!file.fail() && !finish){
			std::string tipo;
			file >> tipo;
			float x, y, vida, armor, damage, misionT1, expM1, misionT2, expM2,  misionT3,expM3,misionT4, expM4,misionT5,expM5;
			file >> x >> y;

			if (tipo == "Jugador"){
				Entidad* ent = new Entidad("p");
				ent->setPox(x);
				ent->setPoy(5);
				ent->setPoz(y);
				Render_c* render = new Render_c("p", ent, "Sinbad", "p");
				ent->AddComponent(render);
				StatsPJ_c* stas = new StatsPJ_c(100, 20, 50, 50, this, ent);
				ent->AddComponent(stas);
				RigidBody_c* player_rb = new RigidBody_c(ent, 5, 5, 5, 1);
				ent->AddComponent(player_rb);
				PlayerController_c * ois = new PlayerController_c(ent, this, stas);
				ent->AddComponent(ois);
				entidades.push_back(ent);

				Entidad* ent3 = new Entidad("GM");
				gm = new GameManager_c(ent);
				ent3->AddComponent(gm);
				entidades.push_back(ent3);
			}
			else if(tipo == "Pan"){
				Entidad* ent = new Entidad("pan");
				ent->setPox(x);// posicion 
				ent->setPoy(5);
				ent->setPoz(y);
				Render_c* render = new Render_c("pan" + std::to_string(contPan), ent, "WoodPallet", "pan" + std::to_string(contPan));
				++contPan;
				ent->AddComponent(render);
				RigidBody_c* static_rb = new RigidBody_c(ent, 5, 5, 5, 1);
				ent->AddComponent(static_rb);
				entidades.push_back(ent);
			}
			else if (tipo == "Npc"){
				file >> misionT1 >> expM1 >> misionT2 >> expM2 >> misionT3 >> expM3 >> misionT4 >> expM4 >> misionT5 >> expM5;
				Entidad* ent2 = new Entidad("p2");
				ent2->setPox(x);// posicion 
				ent2->setPoy(5);
				ent2->setPoz(y);
				Render_c * render = new Render_c("p2", ent2, "Sinbad", "p2");
				ent2->AddComponent(render);
				RigidBody_c* static_rb = new RigidBody_c(ent2, 5, 5, 5, 1);
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
			else if(tipo == "Enemigo"){
				file >> vida >> armor >> damage;
				Entidad* ent = new Entidad("ogroEnemy");
				ent->setPox(x);// posicion 
				ent->setPoy(5);
				ent->setPoz(y);
				Render_c* render2 = new Render_c("ogroEnemy" + std::to_string(contEnemigo), ent, "Sinbad", "ogroEnemy" + std::to_string(contEnemigo));
				++contEnemigo;
				ent->AddComponent(render2);
				RigidBody_c* rb = new RigidBody_c(ent, 5, 5, 5, 1);
				ent->AddComponent(rb);
				ComportamientoEnem_c* compEnem = new ComportamientoEnem_c(ent);
				ent->AddComponent(compEnem);
				StatsEntJuego_c* statsE = new StatsEntJuego_c(vida, armor, damage, this, ent);
				ent->AddComponent(statsE);
				entidades.push_back(ent);

				Entidad* trigger = new Entidad("trigger");
				trigger->setPox(x);// posicion 
				trigger->setPoy(5);
				trigger->setPoz(y);
				Trigger_c* t = new Trigger_c(trigger, ent, motorFisico->getBulletWorld(), 50, 50, 50);
				t->actualizarPos(trigger->getPox(), trigger->getPoy(), trigger->getPoz());
				t->getTrigger()->setUserPointer(trigger);
				trigger->AddComponent(t);
				entidades.push_back(trigger);
			}
			else if (tipo == "Arbol"){
				Entidad* ent = new Entidad("arbol");
				ent->setPox(x);// posicion 
				ent->setPoy(250);
				ent->setPoz(y);
				Render_c* render8 = new Render_c("arbol" + std::to_string(contArboles), ent, "tree.09", "arbol" + std::to_string(contArboles));
				++contArbol;
				ent->AddComponent(render8);
				RigidBody_c* static_rb = new RigidBody_c(ent, 100, 100, 100, 100);
				ent->AddComponent(static_rb);
				entidades.push_back(ent);
			}
			else if (tipo == ""){
				std::cout << "Finished reading the file!\n";
				finish = true;
			}
			else
				std::cout << "Type of entity doesn`t exist!\n";


		}
	}
}

Juego::~Juego()
{
	delete mapa;

	delete guiGame;

	//scnMgr->getRootSceneNode()->removeAllChildren();
	//root->destroySceneManager(scnMgr);
	//root->destroyRenderTarget("P3");
	//delete root;
}

