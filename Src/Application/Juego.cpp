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
Juego::Juego(Ogre::RenderWindow* mWindow, Ogre::SceneManager * scnMgrOgre, btDiscreteDynamicsWorld* bulletWorld)
{
	this->mWindow = mWindow;
	this->scnMgr = scnMgrOgre;
	this->bulletWorld = bulletWorld;
	inputcomp_ = InputComponent::getSingletonPtr();
	inputcomp_->initialise(mWindow);
	
	
	Entidad* ent1 = new Entidad();
	//1683, 50, 2116
	ent1->setPox(1700);// posicion 
	ent1->setPoy(50);
	ent1->setPoz(900); //cuanto menor sea el numero, mas se aleja de la camara
	Render_c* render = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode("personaje"), ent1, "Sinbad");
	PlayerController_c * ois = new PlayerController_c(ent1, inputcomp_);
	ent1->AddComponent(render);
	ent1->AddComponent(ois);
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

	Ogre::Light* light = scnMgr->createLight("tstLight");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(lightdir);
	light->setDiffuseColour(Ogre::ColourValue::White);
	light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));

	scnMgr->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));

	// also need to tell where we are
	Ogre::SceneNode* camNode = scnMgr->getSceneNode("personaje")->createChildSceneNode();
	/*camNode->setPosition(0, 0, 100);
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_WORLD); //esto lo que habia antes
	*/
	// para la escena, pruebas
	camNode->setPosition(Ogre::Vector3(0, 5, -35));
	camNode->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3::UNIT_Y));
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);
	
	// create the camera
	Ogre::Camera* cam = scnMgr->createCamera("Cam");
	cam->setNearClipDistance(0.1); //esto antes era 1
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	//cam->setPolygonMode(Ogre::PM_WIREFRAME);  // en material
	camNode->attachObject(cam);
	cam->setQueryFlags(MY_QUERY_IGNORE);




	// and tell it to render into the main window
	
	Ogre::Viewport* vp = mWindow->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));
	//vp->setBackgroundColour(Ogre::ColourValue(1, 1, 1));
	/*i = new GUI(inputcomp_, vp, scnMgr, cam, camNode, this);
	gui->createPanel();*/
	//Terrain
	/*mapa = new Mapa(scnMgr, light, bulletWorld);
	mapa->createmap();
	mapa->setPhysics();*/

	

}


bool Juego::run(){
	

	clock_t lastTicks = clock();
	clock_t elapsedTicks = 0;
	double deltaTime = 0;
	

	while (true)
	{
		deltaTime = ((double)elapsedTicks) / 1000.f/*CLOCKS_PER_SEC*/;
		lastTicks = clock();
		// Actualize counters
		/*globalClock.addTime(lastTicks);
		localClock.addTime(lastTicks);*/

		/*std::ostringstream s;
		s << "global time: " << std::fixed << globalClock.getTimeSec() << "s";
		captionGlobalTime->text(s.str());*/

		/*s.str("");
		s << "local time: " << std::fixed << localClock.getTimeSec() << "s";
		captionLocalTime->text(s.str());*/

		/*mPanel->injectTime(deltaTime);
		mSPanel->injectTime(deltaTime);
		mSPanel2->injectTime(deltaTime);*/
		inputcomp_->capture();

		for (int i = 0; i<entidades.size(); i++)
			entidades[i]->Update();

		

		// render ogre
		Ogre::WindowEventUtilities::messagePump();
		bulletWorld->stepSimulation((float)deltaTime);
		
		//comprobar si la ventana está abierta
		if (mWindow->isClosed())return false;
		elapsedTicks = clock() - lastTicks;
	}
	return true;
}

Juego::~Juego()
{

}

