#ifndef MOTORFISICO
#define MOTORFISICO
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "BulletCollision\CollisionDispatch\btGhostObject.h"
class MotorFisico
{
public:
	static MotorFisico * getInstancia(){
		if (instancia == nullptr)
			instancia = new MotorFisico();
		return instancia;
	}
	btDynamicsWorld* getBulletWorld(){ return bulletWorld; }
private:
	MotorFisico();
	~MotorFisico();
	btDynamicsWorld* bulletWorld;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btBroadphaseInterface* broadPhase;
	static MotorFisico * instancia;

};
#endif

