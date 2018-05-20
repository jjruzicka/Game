#include "ComportamientoEnem_c.h"
#include "StatsPJ_c.h"
#include "StatsEntJuego_c.h"

ComportamientoEnem_c::ComportamientoEnem_c(Entidad* ent)
{
	chocoCon = 0;
	entidad = ent;
	rb = new RigidBody_c();
	Render_c* rc = new Render_c();
	node = entidad->GetComponent(rc)->getNode();
	//reloj
	entidad = ent;
	cooldown = 0;
	getTime = true;
}


ComportamientoEnem_c::~ComportamientoEnem_c()
{
}

void ComportamientoEnem_c::Update(){
}

void ComportamientoEnem_c::actua(Entidad* entidadHeroe){
	float distancia = calculaDistancia(entidadHeroe);
	if (distancia > 11){
		Ogre::Vector3 angIni(0, 0, 1);
		Ogre::Vector3 angFin(entidadHeroe->getPox() - entidad->getPox(), 0, entidadHeroe->getPoz() - entidad->getPoz());
		node->setOrientation(angIni.getRotationTo(angFin));
		node->translate(node->getOrientation() * Ogre::Vector3(0, 0, 0.1));
		entidad->GetComponent(rb)->actualizarPos(node->getPosition().x, node->getPosition().y, node->getPosition().z);
	}
	else {
		if (getTime){
			start = std::clock();
			getTime = false;
		}

		cooldown = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		if (cooldown > 4){
			getTime = true;
			StatsPJ_c* st = new StatsPJ_c();
			StatsEntJuego_c* sj = new StatsEntJuego_c();
			entidadHeroe->GetComponent(st)->restaVida(entidad->GetComponent(sj)->getDamage());
			std::cout << "Te quedan " << entidadHeroe->GetComponent(st)->getVida()<< " de vida" << std::endl;
		}
	}
}

float ComportamientoEnem_c::calculaDistancia(Entidad* entidadHeroe){
	return sqrtf(pow(entidadHeroe->getPox() - entidad->getPox(), 2) + pow(entidadHeroe->getPoz() - entidad->getPoz(), 2));
}