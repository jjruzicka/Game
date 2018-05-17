#include "Trigger_c.h"


Trigger_c::Trigger_c(Entidad* _ent, btDynamicsWorld* _bulletWorld,
    float _profundo, float _ancho, float _alto)
{
    ent = _ent;
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
}


Trigger_c::~Trigger_c()
{
}

void Trigger_c::Update(){
   btTransform trans;
    trans = trigger->getWorldTransform();
    float x = trans.getOrigin().getX();
    float y = trans.getOrigin().getY();
    float z = trans.getOrigin().getZ();
    ent->setPox(x);
    ent->setPoy(y);
    ent->setPoz(z);
}

void Trigger_c::actualizarPos(float x, float y, float z){
    btTransform trans;
    trans.setIdentity();
    trans.setOrigin(btVector3(x, y, z));
    trigger->setWorldTransform(trans);
}