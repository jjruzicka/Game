#include "Escenas.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Menu.h"
#include "Render_c.h"
#include "PlayerController_c.h"
#include "RigidBody_c.h"
#include "Objeto.h"
#include "Collider_c.h"
using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
Escenas::Escenas()
{
#ifdef _DEBUG
	plugins = "OgreD/plugins_d.cfg";
	recursos = "OgreD/resources_d.cfg";
#else
	plugins = "Ogre/plugins.cfg";
	recursos = "Ogre/resources.cfg";
#endif

	initOgre();
	initCamera();
	
	
	inputcomp_ = InputComponent::getSingletonPtr();
	inputcomp_->initialise(mWindow);


	escenasState = new EscenasManager();
	


	
}
bool Escenas::initOgre(){

	//------------------------------------------------------------------------------------------------------
	//Setting UP Resources 

	//Parsing the config file into the system.
	
	root = new Ogre::Root(plugins);
	try{
		cf.load(recursos);
	}
	catch (Ogre::Exception e){
		std::cout << "\n" << e.getFile();
	}

	//name: Path to resources in disk,
	//loctype: defines what kind of location the element is (e.g. Filesystem, zip..)
	Ogre::String name, locType;

	//We now iterate through rach section in the resources.cfg.
	//Sections are signaled as [NAME]
	Ogre::ConfigFile::SectionIterator secIt = cf.getSectionIterator();
	while (secIt.hasMoreElements())
	{
		Ogre::ConfigFile::SettingsMultiMap* settings = secIt.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator it;

		//Now we are iterating INSIDE the section [secIt]
		for (it = settings->begin(); it != settings->end(); ++it)
		{
			locType = it->first;
			name = it->second;

			//We now know the type of the element and its path.
			//We add it as a location to the Resource Group Manager
			try {
				Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, locType);
				std::cout << "inserting:\n";
				std::cout << name << locType << std::endl;
			}
			catch (Ogre::Exception e)
			{

			}
		}
	}
	//------------------------------------------------------------------------------------------------------
	// Render System Config

	//If there is no previous Ogre.cfg, this displays the config dialog
	if (!(root->restoreConfig() || root->showConfigDialog()))
		return false;

	//------------------------------------------------------------------------------------------------------
	//Render Window Creation
	
	mWindow = root->initialise(true, "P3");

	//mWindow->setFullscreen(true, mWindow->getWidth(), mWindow->getHeight());

	//------------------------------------------------------------------------------------------------------
	//Resources Init

	//We are only going to use 5 mimpams at a time. Mipmaps are efficent ways to save a texture.
	//Taking only 1/3 more of space, we can have several sizes of the texture to choose from.
	Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

	//Now we init every resource previously added
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	//------------------------------------------------------------------------------------------------------
	//SceneManager Set Up

	//we generate the default sceneManager. (more SceneManagers in Ogre::ST_....)
	scnMgr = root->createSceneManager(Ogre::ST_GENERIC);


	return true;
}


	

bool Escenas::initCamera(){
	cam = scnMgr->createCamera("Cam");

	vp = mWindow->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue::Black);
	return true;
}

bool Escenas::run(){
	clock_t lastTicks = clock();
	clock_t elapsedTicks = 0;
	double deltaTime = 0;

	
	while (true)
	{
		deltaTime = ((double)elapsedTicks) / 1000.f/*CLOCKS_PER_SEC*/;
		lastTicks = clock();

		//escenasState->currentState()->render();
		inputcomp_->capture();
		
		escenasState->states[0]->update();
	



		// render ogre
		Ogre::WindowEventUtilities::messagePump();
		if (escenasState->states[0]->bulletWorld != nullptr)
			escenasState->states[0]->bulletWorld->stepSimulation((float)deltaTime);

		//comprobar si la ventana está abierta
		if (mWindow->isClosed())return false;
		if (!root->renderOneFrame())return false;
		elapsedTicks = clock() - lastTicks;
	}
	mWindow->destroy();
	return true;
}




Escenas::~Escenas()
{
	


	/////LEER INIT Y DESTRIR DE ABAJO A ARRIBA LO MISMO CON BULLET



}

