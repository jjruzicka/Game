#include "RigidBody_c.h"
#include <iostream>
//LA Z ES LA ALTURA CUANDO SE METE A BULLET
RigidBody_c::RigidBody_c(Entidad* _ent, physicType _tipo, btDiscreteDynamicsWorld* _bulletWorld,
	float _profundo, float _ancho, float _alto, btScalar _masa)
{
	ent = _ent;
	tipo = _tipo;
	bulletWorld = _bulletWorld;
	alto = _alto;
	ancho = _ancho;
	profundo = _profundo;
	masa = _masa;

	pTransform.setIdentity();
	pTransform.setOrigin(btVector3(ent->getPox(), ent->getPoy(), ent->getPoz()));
	
	btDefaultMotionState* motionState = new btDefaultMotionState(pTransform); // damos dimesiones al box

	btVector3 localInertia(0, 0, 0); // La inercia inicial siempre es 0
	if (tipo == physicType::dinamico)
		localInertia.setY(-10);
	shape = new btBoxShape(btVector3(ancho, profundo, alto));
	shape->calculateLocalInertia(masa, localInertia); // inicializamos el cuerpo

	btRigidBody::btRigidBodyConstructionInfo RigidBodyInfo(masa, motionState, shape, localInertia);
	rb = new btRigidBody(RigidBodyInfo);
    //rb->setCollisionFlags(rb->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	bulletWorld->addRigidBody(rb);
}


RigidBody_c::~RigidBody_c()
{
	delete rb;
	delete motionState;
	delete shape;
}

void RigidBody_c::Update(){
	
	btTransform trans;
	trans = rb->getCenterOfMassTransform();
	float x = trans.getOrigin().getX();
	float y = trans.getOrigin().getY();
	float z = trans.getOrigin().getZ();
	ent->setPox(x);
	ent->setPoy(y);
	ent->setPoz(z);

}

/*void RigidBody_c::actualizarPos(){
	btTransform trans;
	trans.setOrigin(btVector3(ent->getPox(), ent->getPoy(), ent->getPoz()));
	rb.applyCentralForce(btVector3(0, 0, 500));

	rb.getMotionState()->setWorldTransform(trans);
}*/

void RigidBody_c::actualizarPos(float x, float y, float z){

	//std::cout << "Posicion rb: " << x << ", " << y << ", " << z << std::endl;

	btTransform trans;
	// CAMBIANDO LA POSICION SE MUEVE PERO NO COLISIONA
	trans.setIdentity();
	trans.setOrigin(btVector3(x, y, z));
	//rb->activate(true);
	//std::cout << "antes: " << trans.getOrigin().getX() << " , " << trans.getOrigin().getZ()<< std::endl;
	rb->proceedToTransform(trans);
	//rb->setCenterOfMassTransform(trans);
	
	// CON VELOCIDAD NI QUIERA SE MUEVE
	/*btVector3 vel = rb->getLinearVelocity();
	std::cout << "antes: " << vel.getX() << " , " << vel.getZ() << std::endl;
	vel = vel + btVector3(x * 30, 0, z * 30);
	rb->setLinearVelocity(vel);*/

}

