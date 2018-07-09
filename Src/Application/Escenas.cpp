#include "Escenas.h"
#include <iostream>
#include <sstream>

using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
Escenas::Escenas()
{
}

bool Escenas::initBullet(){
	//build the broadPhase
	broadPhase = new btDbvtBroadphase();

	//Set up the collision configuration and dispacher
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);

	//the actual physics solver
	solver = new btSequentialImpulseConstraintSolver();

	//the world
	bulletWorld = new btDiscreteDynamicsWorld(dispatcher, broadPhase, solver, collisionConfiguration);
	bulletWorld->setGravity(btVector3(0, -10, 0));
	return true;
}

Escenas::~Escenas()
{
	for (int i = 0; i < entidades.size(); i++)
		delete entidades[i];
}