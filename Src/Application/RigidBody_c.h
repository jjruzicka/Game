#ifndef RIGIDBODY_C
#define RIGIDBODY_C

#include "Component.h"
#include "Entidad.h"
#include <PxPhysics.h>

class RigidBody_c : public Component
{
public:
	RigidBody_c(Entidad* ent);
	~RigidBody_c();
	void Update();
private:
	Entidad* ent;
};

#endif
