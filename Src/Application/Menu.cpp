#include "Menu.h"
#include "Render_c.h"
#include "PlayerController_c.h"
#include "RigidBody_c.h"
#include <iostream>

#include "Juego.h"

#include "InputManager.h"
using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
Menu::Menu()
{
	motorGrafico = MotorGrafico::getInstancia();
	estadosManager = EstadosManager::getInstancia();
	//initBullet();

	//this->scnM = scnM;

	//inputcomp_ = InputComponent::getSingletonPtr();
	//inputcomp_->initialise(mWindow);

	exit = false;

	/*Entidad* ent1 = new Entidad("p");
	//1683, 50, 2116
	ent1->setPox(1700);// posicion 
	ent1->setPoy(50);
	ent1->setPoz(2000); //cuanto menor sea el numero, mas se aleja de la camara
	Render_c* render = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode("p"), ent1, "Sinbad", "p");
	ent1->AddComponent(render);
	entidades.push_back(ent1);*/

	Ogre::Vector3 lightdir(0.55, -0.3, 0.75);
	lightdir.normalise();

	Ogre::Light* light = motorGrafico->getSceMgr()->createLight("tstLight");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(lightdir);
	light->setDiffuseColour(Ogre::ColourValue::White);
	light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));

	motorGrafico->getSceMgr()->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));

	// also need to tell where we are
	camNode = motorGrafico->getSceMgr()->getRootSceneNode()->createChildSceneNode();

	// para la escena, pruebas
	camNode->setPosition(Ogre::Vector3(0, 5, -35));
	camNode->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3::UNIT_Y));
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	// create the camera
	cam = motorGrafico->getSceMgr()->createCamera("Cam");
	cam->setNearClipDistance(0.1);
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	cam->setQueryFlags(MY_QUERY_IGNORE);




	// and tell it to render into the main window

	vp = motorGrafico->getWindow()->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue::Black);

	gui = new GUI(vp, motorGrafico->getSceMgr(), cam, camNode, this, true);
	gui->createPanel();

	

}
void Menu::MenuToExit(){
	//scnM->Exit();
}

void Menu::MenuToPlay(){
	//Escenas * juego = new Juego();
	//estadosManager->changeEstado(juego);
}

bool Menu::run(){

	// A lo mejor este for no es necesario ya que no hay nada que actualizar
	for (int i = 0; i<entidades.size(); i++)
		entidades[i]->Update();

	return true;
}

Menu::~Menu()
{
/*	InputManager * inputManager = InputManager::getInstancia();
	inputManager->removeKeyListener(gui);
	inputManager->removeMouseListener(gui);*/
	delete gui;
}

