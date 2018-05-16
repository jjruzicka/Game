#include "RigidBody_c.h"
#include <iostream>
#include "Render_c.h"
//LA Z ES LA ALTURA CUANDO SE METE A BULLET
RigidBody_c::RigidBody_c(Entidad* _ent, btDynamicsWorld* _bulletWorld,
	float _profundo, float _ancho, float _alto, btScalar _masa)
{
	ent = _ent;
	bulletWorld = _bulletWorld;
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
	shape->calculateLocalInertia(masa, localInertia); // inicializamos el cuerpo
	btRigidBody::btRigidBodyConstructionInfo RigidBodyInfo(masa, motionState, shape, localInertia);
	rb = new btRigidBody(RigidBodyInfo);
	rb->setLinearFactor(btVector3(1,0,1));
	rb->setSleepingThresholds(0, 0);
	bulletWorld->addRigidBody(rb);
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

