#include "RigidBody_c.h"


RigidBody_c::RigidBody_c(Entidad* ent, const btRigidBody::btRigidBodyConstructionInfo &info) : rb(btRigidBody(info))
{
	this->ent = ent;
	rb = btRigidBody(info);

}


RigidBody_c::~RigidBody_c()
{
	delete rb.getMotionState();
	delete rb.getCollisionShape();
}

void RigidBody_c::Update(){
	
	btTransform trans;
	rb.getMotionState()->getWorldTransform(trans);
	
	float x = trans.getOrigin().getX();
	float y = trans.getOrigin().getY();
	float z = trans.getOrigin().getZ();

	ent->setPox(x);
	ent->setPoy(y);
	ent->setPoz(z);
}

void RigidBody_c::actualizarPos(){
	btTransform trans;
	trans.setOrigin(btVector3(ent->getPox(), ent->getPoy(), ent->getPoz()));
	rb.applyCentralForce(btVector3(0, 0, 500));

	//rb.getMotionState()->setWorldTransform(trans);
}