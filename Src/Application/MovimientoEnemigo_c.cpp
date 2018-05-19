#include "MovimientoEnemigo_c.h"


MovimientoEnemigo_c::MovimientoEnemigo_c(Entidad* ent)
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
	modoAtaque = false;
}


MovimientoEnemigo_c::~MovimientoEnemigo_c()
{
}

void MovimientoEnemigo_c::Update(){
	if (modoAtaque){
		if (getTime){
			start = std::clock(); // get current time
			getTime = false;
		}

		cooldown = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		if (cooldown > 4){ // Dispara
			std::cout << "Disparo enemigo" << std::endl;
			getTime = true;
		}
	}
}

void MovimientoEnemigo_c::mueve(Entidad* entidadHeroe){
	float distancia = calculaDistancia(entidadHeroe);
	if (distancia > 11){
		Ogre::Vector3 angIni(0, 0, 1);
		Ogre::Vector3 angFin(entidadHeroe->getPox() - entidad->getPox(), 0, entidadHeroe->getPoz() - entidad->getPoz());
		node->setOrientation(angIni.getRotationTo(angFin));
		node->translate(node->getOrientation() * Ogre::Vector3(0, 0, 0.1));
		entidad->GetComponent(rb)->actualizarPos(node->getPosition().x, node->getPosition().y, node->getPosition().z);
		modoAtaque = false;
	}
	else {
		modoAtaque = true;
	}
}

float MovimientoEnemigo_c::calculaDistancia(Entidad* entidadHeroe){
	return sqrtf(pow(entidadHeroe->getPox() - entidad->getPox(), 2) + pow(entidadHeroe->getPoz() - entidad->getPoz(), 2));
}