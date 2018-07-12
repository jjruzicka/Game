#include "MotorFisico.h"
#include "Entidad.h"
#include "PlayerController_c.h"
#include "Trigger_c.h"
#include "PatrullarNPC.h"
#include "ComportamientoEnem_c.h"

bool callbackfunction(btManifoldPoint& cp, const btCollisionObjectWrapper * colObj0, int partId0, int index0, const btCollisionObjectWrapper * colObj1, int partId1, int index1){
	if (((Entidad*)colObj0->getCollisionObject()->getUserPointer()) != nullptr && ((Entidad*)colObj1->getCollisionObject()->getUserPointer()) != nullptr){
		if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "p2"){
			PlayerController_c * pC = new PlayerController_c();
			PatrullarNPC* patroll = new PatrullarNPC();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(1, (Entidad*)colObj1->getCollisionObject()->getUserPointer());
			//((Entidad*)colObj1->getCollisionObject()->getUserPointer())->GetComponent(patroll)->chocasCon(1);
		}
		else if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "ogroEnemy"){
			PlayerController_c * pC = new PlayerController_c();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(2, ((Entidad*)colObj1->getCollisionObject()->getUserPointer()));
		}
		else if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "trigger"){
			Trigger_c * trig = new Trigger_c();
			ComportamientoEnem_c* mE = new ComportamientoEnem_c;
			((Entidad*)colObj1->getCollisionObject()->getUserPointer())->GetComponent(trig)->getFather()->GetComponent(mE)->actua((Entidad*)colObj0->getCollisionObject()->getUserPointer());
		}
		else if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "pan"){
			PlayerController_c * pC = new PlayerController_c();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(3, ((Entidad*)colObj1->getCollisionObject()->getUserPointer()));
		}
		else if ((((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p") && ((Entidad*)colObj1->getCollisionObject()->getUserPointer())->getID() == "arbol"){
			PlayerController_c * pC = new PlayerController_c();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(3, ((Entidad*)colObj1->getCollisionObject()->getUserPointer()));
		}
		else if (((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p"){
			PlayerController_c * pC = new PlayerController_c();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(pC)->chocasCon(0, nullptr);
		}
		else if (((Entidad*)colObj0->getCollisionObject()->getUserPointer())->getID() == "p2"){
			PatrullarNPC* patroll = new PatrullarNPC();
			((Entidad*)colObj0->getCollisionObject()->getUserPointer())->GetComponent(patroll)->chocasCon(0);
		}
	}


	return false;
}
MotorFisico::MotorFisico()
{
	gContactAddedCallback = callbackfunction;
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
}


MotorFisico::~MotorFisico()
{
	delete bulletWorld;
	delete collisionConfiguration;
	delete dispatcher;
	delete solver;
	delete broadPhase;
}


