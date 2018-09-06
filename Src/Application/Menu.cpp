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


	Entidad * camera = new Entidad();
	Camera_c * cam = new Camera_c(camera);
	camera->AddComponent(cam);
	entidades.push_back(camera);


	gui = new GUI(camera, this, true);
	gui->createPanel();
	
	

}
void Menu::MenuToExit(){
	exit = true;
}

void Menu::MenuToPlay(){
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
	return true;
}

void Menu::initCamera(){

}
Menu::~Menu()
{
	motorGrafico->getSceMgr()->destroyLight(light);
	delete gui;
}

