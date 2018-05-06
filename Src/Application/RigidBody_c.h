#ifndef RIGIDBODY_C
#define RIGIDBODY_C
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "Component.h"
#include "Entidad.h"

enum class physicType { kinematico, estatico, dinamico /*No se se si sera necesario*/ };

class RigidBody_c : public Component
{
public:
	RigidBody_c(Entidad* _ent, physicType _tipo, btDiscreteDynamicsWorld* _bulletWorld, 
		float _alto, float _ancho, float _profundo, btScalar _masa);
	RigidBody_c(){};
	~RigidBody_c();
	void Update();


	void actualizarPos(float x, float y, float z);
private:
	Entidad* ent;
	physicType tipo;
	btDiscreteDynamicsWorld* bulletWorld;
	float alto, ancho, profundo;
	btTransform pTransform;
	btScalar masa; 
	btCollisionShape* shape;
	btDefaultMotionState* motionState;
	btRigidBody* rb;

};

#endif
