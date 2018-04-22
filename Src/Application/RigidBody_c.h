#ifndef RIGIDBODY_C
#define RIGIDBODY_C
#include <btBulletCollisionCommon.h>
//#include <btBulletDynamicsCommon.h>
#include "Component.h"
#include "Entidad.h"
class RigidBody_c : public Component
{
public:
	RigidBody_c(Entidad* ent, btRigidBody* rb);
	~RigidBody_c();
	void Update();
private:
	btRigidBody* rb;
	Entidad* ent;
};

#endif
