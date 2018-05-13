#include "Menu.h"
#include "Render_c.h"
#include "PlayerController_c.h"
#include "RigidBody_c.h"
#include "Objeto.h"
#include "Collider_c.h"
#include "Juego.h"

#include <iostream>
using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
Menu::Menu(Escenas* scn) : Estados(scn)
{
	bulletWorld = nullptr;
	
	getInput()->addMouseListener(this, "raton2");
	
	
	exit = false;
	init = false;
	
	cameraON = false;
	
	
	mGui3D = new Gui3D::Gui3D(&mMyPurplePanelColors);
	mGui3D->createScreen(getVp(), "purple", "mainScreen");

	createPanel();

	
	
	

	
	

}

void Menu::update(){
	if (!cameraON)
	putCamera();

		
}

void Menu::createPanel(){
	
	// 2D Panel (using Gorilla::Screen)
	Gorilla::Screen* myScreen = mGui3D->getScreen("mainScreen");


	// 2nd test panel
	mSPanel2 = new Gui3D::ScreenPanel(
		mGui3D,
		myScreen,
		Ogre::Vector2(300, 200),
		Ogre::Vector2(400, 400),
		"purple",
		"test_screenPanel2");


	mSPanel2->makeButton(0, 0, 400, 100, "PLAY")
		->setPressedCallback(this, &Menu::play_);
	
	mSPanel2->makeButton(0, 300, 400, 100, "EXIT")
		->setPressedCallback(this, &Menu::exit_);

	
	mSPanel2->hideInternalMousePointer();
}

bool Menu::putCamera(){
	


	camNode = escen->scnMgr->getRootSceneNode()->createChildSceneNode("personaje");

	// para la escena, pruebas
	camNode->setPosition(Ogre::Vector3(0, 2, -2));
	camNode->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3::UNIT_Y));
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	// create the camera

	getCamera()->setNearClipDistance(0.1); //esto antes era 1
	getCamera()->setFarClipDistance(10000);
	getCamera()->setAutoAspectRatio(true);
	//cam->setPolygonMode(Ogre::PM_WIREFRAME);  // en material
	camNode->attachObject(getCamera());
	getCamera()->setQueryFlags(MY_QUERY_IGNORE);


	cameraDirection = Ogre::Vector3(0, 0, -1);
	getCamera()->setDirection(cameraDirection);

	mNormalizedMousePosition = Ogre::Vector2(0.5, 0.5);
	mMousePointerLayer = mGui3D->getScreen("mainScreen")->createLayer(2);

	mMousePointer = mMousePointerLayer->createRectangle(getVp()->getActualWidth() / 2,
		getVp()->getActualHeight() / 2, 12, 18);
	mMousePointer->background_image("mousepointer");
	cameraON = true;
	return cameraON;
}

bool Menu::exit_(Gui3D::PanelElement* e)
{

	exit = true;
	return true;
}

bool Menu::play_(Gui3D::PanelElement* e){
	
	escen->escenasState->MenuToGame();
	return true;
}



bool Menu::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
	mSPanel2->injectMousePressed(evt, id);
	return true;
}

bool Menu::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
	
	mSPanel2->injectMouseReleased(evt, id);
	return true;
}

Ogre::Vector2 Menu::getScreenCenterMouseDistance()
{
	Ogre::Real posX = (mMousePointer->position().x - getVp()->getActualWidth())
		/ getVp()->getActualWidth();
	Ogre::Real posY = (mMousePointer->position().y - getVp()->getActualHeight())
		/ getVp()->getActualHeight();

	return Ogre::Vector2(posX + 0.5, posY + 0.5);
}

bool Menu::mouseMoved(const OIS::MouseEvent &arg)
{
	// Set the new camera smooth direction movement
	Ogre::Vector2 distance(getScreenCenterMouseDistance());
	getCamera()->setDirection(cameraDirection
		+ Ogre::Vector3(distance.x, -distance.y, 0) / 30);

	// Raycast for the actual panel
	Ogre::Real xMove = static_cast<Ogre::Real>(arg.state.X.rel);
	Ogre::Real yMove = static_cast<Ogre::Real>(arg.state.Y.rel);

	mNormalizedMousePosition.x += xMove / getVp()->getActualWidth();
	mNormalizedMousePosition.y += yMove / getVp()->getActualHeight();

	mNormalizedMousePosition.x = std::max<Ogre::Real>(mNormalizedMousePosition.x, 0);
	mNormalizedMousePosition.y = std::max<Ogre::Real>(mNormalizedMousePosition.y, 0);
	mNormalizedMousePosition.x = std::min<Ogre::Real>(mNormalizedMousePosition.x, 1);
	mNormalizedMousePosition.y = std::min<Ogre::Real>(mNormalizedMousePosition.y, 1);

	mMousePointer->position(
		mNormalizedMousePosition.x * getVp()->getActualWidth(),
		mNormalizedMousePosition.y * getVp()->getActualHeight());


	mSPanel2->injectMouseMoved(mNormalizedMousePosition.x * getVp()->getActualWidth(),
		mNormalizedMousePosition.y * getVp()->getActualHeight());

	return true;
}


Menu::~Menu()
{
	delete mGui3D;
	delete camNode;
	delete mSPanel2;
	getInput()->removeMouseListener("raton2");
	
}

