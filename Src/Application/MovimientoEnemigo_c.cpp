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
	//node->translate(Ogre::Vector3(entidadHeroe->getPox() - entidad->getPox(), 0, entidadHeroe->getPoz() - entidad->getPoz()), Ogre::Node::TS_WORLD);
	node->translate(Ogre::Vector3(1, 0, 0), Ogre::Node::TS_WORLD);
	entidad->GetComponent(rb)->actualizarPos(node->getPosition().x, node->getPosition().y, node->getPosition().z);
}