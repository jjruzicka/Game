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
#include "Animacion_c.h"
#include "Camera_c.h"

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
	motorGrafico = MotorGrafico::getInstancia();
	motorFisico = MotorFisico::getInstancia();
	cont = 0;

	entidadFactory(path);

	Ogre::Vector3 lightdir(0.55, -0.3, 0.75);
	lightdir.normalise();

	Ogre::Light* light = motorGrafico->getSceMgr()->createLight("tstLight2");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(lightdir);
	light->setDiffuseColour(Ogre::ColourValue::White);
	light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));

	motorGrafico->getSceMgr()->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));

	// and tell it to render into the main window

	//GUI
	//guiGame = new GUI(inputcomp_, vp, motorGrafico->getSceMgr(), cam, camNode, this, false);
	//guiGame->createUI();

	//Terrain
	mapa = new Mapa(light);
	

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
			std::string tipo, target;
			file >> tipo;
			float x, y, vida, armor, damage, numMisiones, numTargets, exp;
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
				Animacion_c * anim = new Animacion_c(ent);
				ent->AddComponent(anim);
				PlayerController_c * ois = new PlayerController_c(ent, this, stas);
				ent->AddComponent(ois);
				entidades.push_back(ent);

				Entidad * camera = new Entidad();
				Camera_c * cam = new Camera_c(camera);
				camera->AddComponent(cam);
				CameraMove_c * camMove = new CameraMove_c(camera, ent);
				camera->AddComponent(camMove);
				entidades.push_back(camera);

				Entidad* ent3 = new Entidad();
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
				file >> numMisiones;
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
				for (int i = 0; i < numMisiones; ++i){
					file >> numTargets >> target >> exp;
					Mision_c* mision = new Mision_c(numTargets, target, exp, ent2);
					ent2->AddComponent(mision);
				}
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
				Render_c* render8 = new Render_c("arbol" + std::to_string(contArbol), ent, "tree.09", "arbol" + std::to_string(contArbol));
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

