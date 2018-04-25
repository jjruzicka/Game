#pragma once
#ifndef COLLIDER_C_H
#define COLLIDER_C_H

#include "Entidad.h"
#include "Component.h"
#include "btBulletDynamicsCommon.h"

class Collider_c : public Component
{
public:
	Collider_c(Entidad* ent, btCollisionObject* collisionObject);
	~Collider_c();
	void Update();
private:
	btCollisionShape* collisionShape;
	btCollisionObject* collisionObject;
	Entidad* ent;
	btQuaternion* q;
	btTransform trans;
};

#endif