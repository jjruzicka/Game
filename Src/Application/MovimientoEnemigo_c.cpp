#include "MovimientoEnemigo_c.h"


MovimientoEnemigo_c::MovimientoEnemigo_c(Entidad* ent)
{
	chocoCon = 0;
	entidad = ent;
	rb = new RigidBody_c();
	Render_c* rc = new Render_c();
	node = entidad->GetComponent(rc)->getNode();
}


MovimientoEnemigo_c::~MovimientoEnemigo_c()
{
}

/*void MovimientoEnemigo_c::chocasCon(int i, Entidad* ent){//0 para cuando no es nada, 1 npc
	chocoCon = i;
	entColision = ent;
}*/

void MovimientoEnemigo_c::Update(){
	//entidad->GetComponent(rb)->actualizarPos(entidad->getPox(), entidad->getPoy(), entidad->getPoz());
}

void MovimientoEnemigo_c::mueve(Entidad* entidadHeroe){
	//node->translate(Ogre::Vector3(entidadHeroe->getPox() - entidad->getPox(), 0, entidadHeroe->getPoz() - entidad->getPoz()), Ogre::Node::TS_LOCAL);
	Ogre::Vector3 angIni(0,0,1);
	Ogre::Vector3 angFin(entidadHeroe->getPox() - entidad->getPox(), 0, entidadHeroe->getPoz() - entidad->getPoz());
	// = Ogre::Quaternion(Ogre::Degree(0), Ogre::Vector3(entidadHeroe->getPox() - entidad->getPox(), entidad->getRoy(), entidadHeroe->getPoz() - entidad->getPoz()));
	node->setOrientation(angIni.getRotationTo(angFin));
	node->translate(node->getOrientation() * Ogre::Vector3(0, 0, 0.1));
	//node->translate(Ogre::Vector3(1, 0, 0), Ogre::Node::TS_WORLD);
	entidad->GetComponent(rb)->actualizarPos(node->getPosition().x, node->getPosition().y, node->getPosition().z);
}