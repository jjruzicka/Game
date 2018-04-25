#include "Collider_c.h"


Collider_c::Collider_c(Entidad* ent, btCollisionObject* collisionObject)
{
	this->ent = ent;
	this->collisionObject = collisionObject;
	collisionShape = new btBoxShape(btVector3(10,10,10));
	collisionObject->setCollisionShape(collisionShape);
	btScalar scalar = ent->getAngRot();
	q = new btQuaternion(ent->getRox(), ent->getRoy(), ent->getRoz(),scalar);
	trans.setOrigin(btVector3(ent->getPox(), ent->getPoy(), ent->getPoz()));
	trans.setRotation(*q);
	collisionObject->setWorldTransform(trans);
}


Collider_c::~Collider_c()
{
	delete collisionShape;
	delete collisionObject;
	delete ent;
}

void Collider_c::Update(){//LA ROTACION NO ES IMPORTANTE
	btScalar scalar = ent->getAngRot();
	trans.setOrigin(btVector3(ent->getPox(), ent->getPoy(), ent->getPoz()));
	trans.setRotation(*q);
	collisionObject->setWorldTransform(trans);
}