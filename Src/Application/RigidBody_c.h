#ifndef RIGIDBODY_C
#define RIGIDBODY_C
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "BulletCollision\CollisionDispatch\btGhostObject.h"
#include "Component.h"
#include "Entidad.h"
#include "MotorFisico.h"

class RigidBody_c : public Component
{
public:
	RigidBody_c(Entidad* _ent,
		float _profundo, float _ancho, float _alto, btScalar _masa/*bool isTrigger*/);
	RigidBody_c(){};
	~RigidBody_c();
	void Update();
	btRigidBody* getRigidBody(){
		return rb;
	}
    Entidad* getentity(){
        return ent;
    }
	void actualizarPos(float x, float y, float z);
private:
	Entidad* ent;
	MotorFisico* motorFisico;
	btDynamicsWorld* bulletWorld;
	float alto, ancho, profundo;
	btTransform pTransform;
	btScalar masa; 
	btCollisionShape* shape;
	btDefaultMotionState* motionState;
	btRigidBody* rb;
    //btGhostObject* trigger;

};

#endif
