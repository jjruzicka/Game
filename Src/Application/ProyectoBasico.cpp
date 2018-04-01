#include <stdio.h>
#include <OgreRoot.h>
#include <PxPhysicsAPI.h>
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
	

    Ogre::Root *root;
	Escenas* escena = new Escenas();
#ifdef _DEBUG
    root = new Ogre::Root("OgreD/plugins_d.cfg");
	
#else
    root = new Ogre::Root("Ogre/plugins.cfg");
#endif
	system("PAUSE");
    return 0;

}