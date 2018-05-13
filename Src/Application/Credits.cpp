#include "Credits.h"
#include "Render_c.h"
#include "PlayerController_c.h"
#include "RigidBody_c.h"
#include "Objeto.h"
#include "Collider_c.h"
#include "Menu.h"
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};

Credits::Credits(Escenas* scn) :Menu(scn)
{

	scnM = scn;

	

	cameraON = false;

	
	//// and tell it to render into the main window
	//vp = scnM->mWindow->addViewport(cam);
	//vp->setBackgroundColour(Ogre::ColourValue::Black);

	init = false;
	// Create a layer for the mousePointer
	mNormalizedMousePosition = Ogre::Vector2(0.5, 0.5);
	mMousePointerLayer = getGUI()->getScreen("mainScreen")->createLayer(2);

	mMousePointer = mMousePointerLayer->createRectangle(getVp()->getActualWidth() / 2,
		getVp()->getActualHeight() / 2, 12, 18);
	mMousePointer->background_image("mousepointer");
	
	createPanel();


}

void Credits::render(){
	
	
	

	
}



void Credits::createPanel(){
	Gorilla::Screen* myScreen2 = getGUI()->getScreen("mainScreen");


	// 2nd test panel
	mPanel = new Gui3D::ScreenPanel(
		getGUI(),
		myScreen2,
		Ogre::Vector2(300, 200),
		Ogre::Vector2(400, 400),
		"purple",
		"test_screenPanel3");

	mPanel->makeButton(0, 500, 400, 100, "MENU")
		->setPressedCallback(this, &Credits::creditsToMenu);


	mPanel->hideInternalMousePointer();
	
}

bool Credits::creditsToMenu(Gui3D::PanelElement* e){
	scnM->escenasState->changeState(new Menu(scnM));
	return true;
}
bool Credits::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
	mPanel->injectMousePressed(evt, id);
	return true;
}

bool Credits::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
	mPanel->injectMouseReleased(evt, id);
	return true;
}


bool Credits::mouseMoved(const OIS::MouseEvent &arg)
{
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

	mPanel->injectMouseMoved(mNormalizedMousePosition.x * getVp()->getActualWidth(),
		mNormalizedMousePosition.y * getVp()->getActualHeight());
	return true;
}



	

Credits::~Credits()
{
	
}

