#include "RigidBody_c.h"
#include <iostream>
#include "Render_c.h"
//LA Z ES LA ALTURA CUANDO SE METE A BULLET
RigidBody_c::RigidBody_c(Entidad* _ent, 
	float _profundo, float _ancho, float _alto, btScalar _masa/* bool isTrigger*/)
{
	ent = _ent;
	motorFisico = MotorFisico::getInstancia();
	bulletWorld = motorFisico->getBulletWorld();
	alto = _alto;
	ancho = _ancho;
	profundo = _profundo;
	masa = _masa;

	pTransform.setIdentity();
	pTransform.setOrigin(btVector3(ent->getPox(), ent->getPoy(), ent->getPoz()));
	btDefaultMotionState* motionState = new btDefaultMotionState(pTransform); // damos dimesiones al box
	Render_c* render = new Render_c();
	btVector3 localInertia(0, 0, 0); // La inercia inicial siempre es 0
	shape = new btBoxShape(btVector3(ancho, profundo, alto));
    /*if (isTrigger){
        trigger = new btGhostObject();
        trigger->setCollisionShape(shape);
    }*/
	shape->calculateLocalInertia(masa, localInertia); // inicializamos el cuerpo
	btRigidBody::btRigidBodyConstructionInfo RigidBodyInfo(masa, motionState, shape, localInertia);
	rb = new btRigidBody(RigidBodyInfo);
	rb->setLinearFactor(btVector3(1,0,1));
	rb->setSleepingThresholds(0, 0);
	bulletWorld->addRigidBody(rb);

	rb->setCollisionFlags(rb->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	rb->setUserPointer(ent);
}


RigidBody_c::~RigidBody_c()
{
	bulletWorld->removeRigidBody(rb);
	delete rb;
	delete shape;
	delete motionState;
}

void RigidBody_c::Update(){
	btTransform trans;
	trans = rb->getWorldTransform();
	float x = trans.getOrigin().getX();
	float y = trans.getOrigin().getY();
	float z = trans.getOrigin().getZ();
	ent->setPox(x);
	ent->setPoy(y);
	ent->setPoz(z);
}

void RigidBody_c::actualizarPos(float x, float y, float z){
	btTransform trans;
	trans.setIdentity();
	trans.setOrigin(btVector3(x, y, z));
	rb->setWorldTransform(trans);
}

