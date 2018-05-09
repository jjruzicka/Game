#include "EscenasManager.h"
#include "Menu.h"
#include "Juego.h"

enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
EscenasManager::EscenasManager()
{
#ifdef _DEBUG
	plugins = "OgreD/plugins_d.cfg";
	recursos = "OgreD/resources_d.cfg";
#else
	plugins = "Ogre/plugins.cfg";
	recursos = "Ogre/resources.cfg";
#endif
	initBullet();
	initOgre();
	juegoB = false;
	menuB = true;

	if (menuB){
		menu = new Menu(this,mWindow,scnMgr,bulletWorld);
		juego = nullptr;
	}
	else if (juegoB){
		juego = new Juego(mWindow, scnMgr, bulletWorld);
		menu = nullptr;
	}
}

bool EscenasManager::run(){
	if (juegoB)
		juego->run();
	else if (menuB)
		menu->run();
	return true;
}

void EscenasManager::MenuToGame(){
	menuB = false;
	juegoB = true;
	delete menu;
	juego = new Juego(mWindow, scnMgr, bulletWorld);
	run();
}
void EscenasManager::GameToMenu(){
	menuB = true;
	juegoB = false;
	menu = new Menu(this, mWindow, scnMgr, bulletWorld);
	delete juego;
	run();
}
EscenasManager::~EscenasManager()
{
	if (menuB)
		delete menu;
	else if (juegoB)
		delete juego;
}

bool EscenasManager::initOgre(){

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
bool EscenasManager::initBullet(){
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