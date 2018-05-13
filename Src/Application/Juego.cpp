#include "Juego.h"
#include "Render_c.h"
#include "PlayerController_c.h"
#include "RigidBody_c.h"
#include "Objeto.h"
#include "Collider_c.h"
#include <iostream>
using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
Juego::Juego(Escenas* scn) : Estados(scn)
{
	
	this->scnM = scn;

	initBullet();
	

	Entidad* ent1 = new Entidad();
	//1683, 50, 2116
	ent1->setPox(1700);// posicion 
	ent1->setPoy(50);
	ent1->setPoz(900); //cuanto menor sea el numero, mas se aleja de la camara
	Render_c* render = new Render_c(scnM->scnMgr->getRootSceneNode()->createChildSceneNode("personaje5"), ent1, "Sinbad");
	//PlayerController_c * ois = new PlayerController_c(ent1, inputcomp_);
	ent1->AddComponent(render);
	//ent1->AddComponent(ois);
	entidades.push_back(ent1);

	btCollisionShape* fallShape = new btSphereShape(1);
	btDefaultMotionState* fallMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 30, 0)));
	btScalar mass = 1;
	btVector3 fallInertia(0, 9.8f, 0);
	fallShape->calculateLocalInertia(mass, fallInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, fallShape, fallInertia);
	RigidBody_c* rb = new RigidBody_c(ent1, fallRigidBodyCI);
	ent1->AddComponent(rb);
	bulletWorld->addRigidBody(rb->getRigidbody());

	

	Ogre::Vector3 lightdir(0.55, -0.3, 0.75);
	lightdir.normalise();

	Ogre::Light* light = scnM->scnMgr->createLight("tstLight");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(lightdir);
	light->setDiffuseColour(Ogre::ColourValue::White);
	light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));

	scnM->scnMgr->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));

	// also need to tell where we are
	camNode = scnM->scnMgr->getSceneNode("personaje5")->createChildSceneNode();
	/*camNode->setPosition(0, 0, 100);
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_WORLD); //esto lo que habia antes
	*/
	// para la escena, pruebas
	camNode->setPosition(Ogre::Vector3(0, 5, -35));
	camNode->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3::UNIT_Y));
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);
	
	// create the camera
	//
	//cam->setNearClipDistance(0.1); //esto antes era 1
	//cam->setFarClipDistance(10000);
	//cam->setAutoAspectRatio(true);
	//cam->setPolygonMode(Ogre::PM_WIREFRAME);  // en material
	/*camNode->attachObject(cam);*/
	/*cam->setQueryFlags(MY_QUERY_IGNORE);
*/



	// and tell it to render into the main window
	
	/*vp = scnM->mWindow->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));*/
	//vp->setBackgroundColour(Ogre::ColourValue(1, 1, 1));
	/*i = new GUI(inputcomp_, vp, scnMgr, cam, camNode, this);
	gui->createPanel();*/
	//Terrain
	mapa = new Mapa(scnM->scnMgr, light, bulletWorld);
	mapa->createmap();
	mapa->setPhysics();

	

}

bool Juego::initBullet(){
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



Juego::~Juego()
{
	for (int i = 0; i < entidades.size(); i++)
		delete entidades[i];
	//inputcomp_->removeKeyListener(inputcomp_);
	//inputcomp_->removeMouseListener(inputcomp_);*/
}

