#include "CameraMove_c.h"
#include <iostream>
#include <math.h>

CameraMove_c::CameraMove_c(Entidad* ent, Entidad* eJug)
	: entidadCamara(ent), entidadJugador(eJug){
	distMax = 25;
	
	camComponent = new Camera_c();
	cam_node = entidadCamara->GetComponent(camComponent)->getCamNode();

	// Con esto lo colocamnos detras de objetivo
	cam_node->setPosition(Ogre::Vector3(entidadJugador->getPox(), 15,
		entidadJugador->getPoz() - distMax));

	// Actualizamos la posicion de la entidad de la camara a la del nodo de la camara
	entidadCamara->setPox(cam_node->getPosition().x);
	entidadCamara->setPoy(cam_node->getPosition().y);
	entidadCamara->setPoz(cam_node->getPosition().z);
	cam_node->setFixedYawAxis(true);
}
CameraMove_c::~CameraMove_c()
{
	//delete camComponent;
}

void CameraMove_c::Update(){
	calculaOffset();
	float distancia = sqrtf(pow(offset.x, 2) + pow(offset.z, 2));
	if (distancia != distMax){
		float alfa = distMax / distancia;
		Ogre::Vector3 offsetObjetivo = offset * alfa;
		Ogre::Vector3 posicionObjetivo = offsetObjetivo + Ogre::Vector3(entidadJugador->getPox(), entidadJugador->getPoy(), entidadJugador->getPoz());
		cam_node->setPosition(Ogre::Vector3(posicionObjetivo.x, 15, posicionObjetivo.z));
	}

	cam_node->lookAt(Ogre::Vector3(entidadJugador->getPox(), entidadJugador->getPoy()+ 5, entidadJugador->getPoz()), Ogre::Node::TS_WORLD);

	entidadCamara->setPox(cam_node->getPosition().x);
	entidadCamara->setPoy(cam_node->getPosition().y);
	entidadCamara->setPoz(cam_node->getPosition().z);
}

void CameraMove_c::calculaOffset(){
	offset = Ogre::Vector3((entidadCamara->getPox() - entidadJugador->getPox()),
		(entidadCamara->getPoy() - entidadJugador->getPoy()),
		(entidadCamara->getPoz() - entidadJugador->getPoz()));
}
