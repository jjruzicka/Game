#include "Menu.h"
#include "Render_c.h"
#include "PlayerController_c.h"
#include "RigidBody_c.h"
#include <iostream>

#include "Juego.h"
#include "InputManager.h"
#include "Camera_c.h"

using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
Menu::Menu()
{
	motorGrafico = MotorGrafico::getInstancia();
	estadosManager = EstadosManager::getInstancia();

	exit = false;
	goJuego = false;
	Ogre::Vector3 lightdir(0.55, -0.3, 0.75);
	lightdir.normalise();

	light = motorGrafico->getSceMgr()->createLight("tstLight");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(lightdir);
	light->setDiffuseColour(Ogre::ColourValue::White);
	light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));

	motorGrafico->getSceMgr()->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));

	// also need to tell where we are
	//camNode = motorGrafico->getSceMgr()->getRootSceneNode()->createChildSceneNode();

	// para la escena, pruebas
	/*camNode->setPosition(Ogre::Vector3(0, 5, -35));
	camNode->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3::UNIT_Y));
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);
	*/
	// create the camera
	/*cam = motorGrafico->getSceMgr()->createCamera("Cam");
	cam->setNearClipDistance(0.1);
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	cam->setQueryFlags(MY_QUERY_IGNORE);

	*/

	Entidad * camera = new Entidad();
	Camera_c * cam = new Camera_c(camera);
	camera->AddComponent(cam);
	entidades.push_back(camera);

	// and tell it to render into the main window

	/*vp = motorGrafico->getWindow()->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue::Black);
	*/

	gui = new GUI(camera, this, true);
	gui->createPanel();
	
	

}
void Menu::MenuToExit(){
	//scnM->Exit();
	exit = true;
}

void Menu::MenuToPlay(){
	//estadosManager->changeEstado("Nivel", "..//Media//Levels//Nivel1.txt");
	goJuego = true;
}

bool Menu::run(){

	// A lo mejor este for no es necesario ya que no hay nada que actualizar
	for (int i = 0; i<entidades.size(); i++)
		entidades[i]->Update();

	if (exit)
		estadosManager->exitGame();
	else if (goJuego)
		estadosManager->changeEstado("Nivel", "..//Media//Levels//Nivel1.txt");
		//estadosManager->changeEstado("Menu", "");
	return true;
}

void Menu::initCamera(){

}
Menu::~Menu()
{
	motorGrafico->getSceMgr()->destroyLight(light);
	//delete light;
	delete gui;
}

