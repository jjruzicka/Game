#include <stdio.h>
#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include <OgreCamera.h>
#include <OgreEntity.h>
#include "OgreSceneNode.h"
#include <OgreConfig.h>
#include "OgreConfigFile.h"

#include <OgreTextureManager.h>
#include <OgreWindowEventUtilities.h>
#include <OgreException.h>
#include <iostream>
#include "Escenas.h"

#ifdef _DEBUG || !_WIN32
int main() {
#else
#include<Windows.h>
int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
	) {
#endif
	
	std::string recursos, plugins;
	Ogre::Root *root;
	Ogre::ConfigFile cf;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager * scnMgr;
	

#ifdef _DEBUG
	plugins = "OgreD/plugins_d.cfg";
	recursos = "OgreD/resources_d.cfg";
#else
	plugins = "OgreD/plugins.cfg";
	recursos = "OgreD/resources.cfg";
#endif

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



	Escenas* escena = new Escenas();

	system("PAUSE");
	delete escena;
    return 0;

}