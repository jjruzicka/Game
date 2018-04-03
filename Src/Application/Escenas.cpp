#include "Escenas.h"
#include "Render_c.h"

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
	plugins = "OgreD/plugins.cfg";
	recursos = "OgreD/resources.cfg";
#endif
	initOgre();
	Entidad* ent1 = new Entidad();
	Render_c* render = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode("ogrehead"), ent1, "ogrehead");
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

bool Escenas::run(){
	// without light we would just get a black screen    
	Light* light = scnMgr->createLight("Light");
	light->setDirection(Ogre::Vector3::NEGATIVE_UNIT_Z); // !!! opngl <-> dirección a la fuente de luz
	lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	lightNode->setPosition(0, 0, 100);
	lightNode->attachObject(light);

	Light* spotLight = scnMgr->createLight("SpotLight");
	spotLight->setDiffuseColour(0, 0, 1.0);
	spotLight->setSpecularColour(0, 0, 1.0);
	spotLight->setType(Light::LT_SPOTLIGHT);
	spotLight->setDirection(Vector3::NEGATIVE_UNIT_Z);
	SceneNode* spotLightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	spotLightNode->attachObject(spotLight);
	spotLightNode->setDirection(-1, -1, 0);
	spotLightNode->setPosition(Vector3(200, 200, 0));
	spotLight->setSpotlightRange(Degree(60), Degree(100));


	// also need to tell where we are
	camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	camNode->setPosition(0, 0, 100);
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_WORLD);

	// create the camera
	cam = scnMgr->createCamera("Cam");
	cam->setNearClipDistance(1);
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	//cam->setPolygonMode(Ogre::PM_WIREFRAME);  // en material
	camNode->attachObject(cam);
	cam->setQueryFlags(MY_QUERY_IGNORE);

	


	// and tell it to render into the main window
	Viewport* vp;
	vp = mWindow->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));
	//vp->setBackgroundColour(Ogre::ColourValue(1, 1, 1));
	
	while (true)
	{

		/*mInputMgr->capture();
		if (cont == 2) {
			handleInput();
			cont = 0;
		}
		*/
		//else{
			//cont++;
			for (int i = 0; entidades.size();i++)
				entidades[i]->Update();
		//}
		// render ogre
		Ogre::WindowEventUtilities::messagePump();


		//comprobar si la ventana está abierta
		if (mWindow->isClosed())return false;
		if (!root->renderOneFrame())return false;
	}
	return true;
}


Escenas::~Escenas()
{
	for (int i = 0; i < entidades.size();i++)
		delete entidades[i];
}
