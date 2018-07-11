#include "Trigger_c.h"
#include <iostream>
#include "StatsEntJuego_c.h"
StatsEntJuego_c* st;
Trigger_c::Trigger_c(Entidad* _ent, Entidad* _entEne, btDynamicsWorld* _bulletWorld,
    float _profundo, float _ancho, float _alto)
{
    ent = _ent;
	entPadre = _entEne;
    bulletWorld = _bulletWorld;
    alto = _alto;
    ancho = _ancho;
    profundo = _profundo;

    trigger = new btCollisionObject();
    trigger->setCollisionShape(new btBoxShape(btVector3(ancho, profundo, alto)));
    pTransform.setIdentity();
    pTransform.setOrigin(btVector3(ent->getPox(), ent->getPoy(), ent->getPoz()));

    trigger->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
    bulletWorld->addCollisionObject(trigger);
	st = new StatsEntJuego_c();

	actualizarPos(ent->getPox(), ent->getPoy(), ent->getPoz());
	trigger->setUserPointer(ent);
}


Trigger_c::~Trigger_c()
{
}

void Trigger_c::Update(){

	//std::cout << entPadre->GetComponent(st)->getVida() << "\n";
	if (entPadre->GetComponent(st)->getVida() <= 0){
		trigger->setCollisionFlags(4);
		bulletWorld->removeCollisionObject(trigger);
		ent->DestroyComponent(this);
	}
	else {
		actualizarPos(entPadre->getPox(), entPadre->getPoy(), entPadre->getPoz());
		btTransform trans;
		trans = trigger->getWorldTransform();
		float x = trans.getOrigin().getX();
		float y = trans.getOrigin().getY();
		float z = trans.getOrigin().getZ();
		ent->setPox(x);
		ent->setPoy(y);
		ent->setPoz(z);
	}
}

void Trigger_c::actualizarPos(float x, float y, float z){
    btTransform trans;
    trans.setIdentity();
    trans.setOrigin(btVector3(x, y, z));
    trigger->setWorldTransform(trans);
}