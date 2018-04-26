#ifndef RIGIDBODY_C
#define RIGIDBODY_C
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "Component.h"
#include "Entidad.h"
class RigidBody_c : public Component
{
public:
	RigidBody_c(Entidad* ent, const btRigidBody::btRigidBodyConstructionInfo & info);
	RigidBody_c() :rb(btRigidBody(0, nullptr, nullptr)){};
	~RigidBody_c();
	void Update();
	btRigidBody * getRigidbody(){
		return &rb;
	}

	void actualizarPos(float x, float y, float z);
private:
	btRigidBody rb;
	Entidad* ent;
};

#endif
