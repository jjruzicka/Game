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
	//bool callbackfunction(btManifoldPoint& cp, const btCollisionObjectWrapper * colObj0, int partId0, int index0, const btCollisionObjectWrapper * colObj1, int partId1, int index1);
private:
	MotorFisico();
	~MotorFisico();
	btDynamicsWorld* bulletWorld;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btBroadphaseInterface* broadPhase;
	static MotorFisico * instancia;
	//InputComponent* inputcomp_;

};
#endif

