#include "RigidBody_c.h"


RigidBody_c::RigidBody_c(Entidad* ent, btRigidBody* rb)
{
	this->ent = ent;
	this->rb = rb;
}


RigidBody_c::~RigidBody_c()
{
}

void RigidBody_c::Update(){

}