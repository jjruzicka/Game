#include "GUI.h"
#include <iostream>
#include "Menu.h"
#include "Juego.h"

typedef struct PanelAndDirection
{
	Gui3D::Panel* panel;
	Ogre::Vector3 cameraDirection;
	int yaw;
} PanelAndDirection;

GUI::GUI(InputComponent* input_, Ogre::Viewport* vp, Ogre::SceneManager * scnMgr, Ogre::Camera * cam, Ogre::SceneNode* camNode, Escenas* menuc, bool escena)
{
	menu = menuc;
	scn = scnMgr;
	camera = cam;
	cNode = camNode;
	icomp_ = input_;
	icomp_->addKeyListener(this, "teclado2");
	icomp_->addMouseListener(this, "raton2");
	
	pant = escena;
	mMyPurplePanelColors = new MyPurplePanelColors();
	mGui3D = new Gui3D::Gui3D(mMyPurplePanelColors);
	mGui3D->createScreen(vp, "purple", "mainScreen");
	
	// Create a layer for the mousePointer
	if (pant){
		
		mNormalizedMousePosition = Ogre::Vector2(0.5, 0.5);
		mMousePointerLayer = mGui3D->getScreen("mainScreen")->createLayer(1);
		mMousePointer = mMousePointerLayer->createRectangle(vp->getActualWidth() / 2,
			vp->getActualHeight() / 2, 12, 18);
   
		mMousePointer->background_image("mousepointer");
	}
	else{
		//mGui3D = new Gui3D::Gui3D(&mMyEnvironmentDemoPanelColors);
		//mGui3D->createScreen(vp, "environmentDemo", "mainScreen");
		////mPanel = _createPanel(Ogre::Vector3(0, 5.3, -2.5), 180);
		//camera->setPosition(0, 6.f, -8);
		//camera->setDirection(Ogre::Vector3(0, 0, 1));

	}

  

	view = vp;
	

	numFrameLastClicked = 0;
	nbFramesSinceStart = 0;
	mClicksOnButton = 0;

}

void GUI::_createPanel()
{
	Gui3D::Panel* panel = new Gui3D::Panel(
		mGui3D, scn, Ogre::Vector2(400, 400), 15, "environmentDemo", "kikoo");

	panel->mNode->setPosition(0, 5.3, -2.5);
	panel->mNode->yaw(Ogre::Degree(180));

	panel->makeCaption(10, 10, 380, 30, "Move the TV please...", Gorilla::TextAlign_Centre);

	panel->makeCaption(10, 100, 90, 100, "Left", Gorilla::TextAlign_Centre, Gorilla::VerticalAlign_Middle);
	panel->makeCaption(310, 100, 90, 100, "Right", Gorilla::TextAlign_Centre, Gorilla::VerticalAlign_Middle);

	mPanel = panel;
}
void GUI::createPanel(){
	myScreen = mGui3D->getScreen("mainScreen");

	// 2nd test panel
	mSPanel2 = new Gui3D::ScreenPanel(
		mGui3D,
		myScreen,
		Ogre::Vector2(300, 200),
		Ogre::Vector2(400, 400),
		"purple",
		"test_screenPanel2");


	
	mSPanel2->makeButton(0, 0, 400, 100, "PLAY")
		->setPressedCallback(this, &GUI::play_);
	mSPanel2->makeButton(0, 150, 400, 100, "CREDITS")
		->setPressedCallback(this, &GUI::exit_);
	mSPanel2->makeButton(0, 300, 400, 100, "EXIT")
		->setPressedCallback(this, &GUI::exit_);

	// We don't want any panels to display mouse cursor. It is handled
	//  by our Simple2DDemo.
	mSPanel2->hideInternalMousePointer();
	
}

void GUI::createPanelInGame(){
	myScreen = mGui3D->getScreen("mainScreen");

	// 2nd test panel
	mSPanel2 = new Gui3D::ScreenPanel(
		mGui3D,
		myScreen,
		Ogre::Vector2(800, 700),
		Ogre::Vector2(0, 0),
		"purple",
		"test_screenPanel2");



	mSPanel2->makeButton(0, 0, 200, 50, "P to EXIT")
		->setPressedCallback(this, &GUI::exitGame);
	

	// We don't want any panels to display mouse cursor. It is handled
	//  by our Simple2DDemo.
	mSPanel2->hideInternalMousePointer();
	
}


bool GUI::textChanged(Gui3D::PanelElement* e)
{
	Gui3D::TextZone* t = (Gui3D::TextZone*)e;
	captionDisplayTextZone->text(t->text());
	return true;
}

bool GUI::play_(Gui3D::PanelElement* e)
{
	static_cast<Menu*>(menu)->MenuToPlay();

	return true;
}

bool GUI::exit_(Gui3D::PanelElement* e)
{
	
	static_cast<Menu*>(menu)->exit = true;
	return true;
}

bool GUI::exitGame(Gui3D::PanelElement* e){
	
	return true;
}

bool GUI::keyPressed(const OIS::KeyEvent& keyP){
	
	//mPanel->injectKeyPressed(keyP);
	switch (keyP.key)
	{
	case OIS::KC_P:
		static_cast<Juego*>(menu)->exit = true;
		break;
	default:
		break;
	}
	return true;
}
bool GUI::keyReleased(const OIS::KeyEvent& keyP){
	//mPanel->injectKeyReleased(keyP);
	switch (keyP.key)
	{
	case OIS::KC_P:
		
		break;
	default:
		break;
	}
	return true;
}


bool GUI::buttonPressed(Gui3D::PanelElement* e)
{
	mClicksOnButton++;
	std::ostringstream s;
	s << "The button has been pressed " << mClicksOnButton << " times";
	captionButton->text(s.str());
	return true;
}

bool GUI::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
	if (pant)
	mSPanel2->injectMousePressed(evt, id);
	else
	mPanel->injectMousePressed(evt, id);
	
	return true;
}

bool GUI::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
	if (pant)
	mSPanel2->injectMouseReleased(evt, id);
	else
		mPanel->injectMouseReleased(evt, id);
	
	return true;
}

Ogre::Vector2 GUI::getScreenCenterMouseDistance()
{
	Ogre::Real posX = (mMousePointer->position().x - view->getActualWidth())
		/ view->getActualWidth();
	Ogre::Real posY = (mMousePointer->position().y - view->getActualHeight())
		/ view->getActualHeight();

	return Ogre::Vector2(posX + 0.5, posY + 0.5);
}

bool GUI::mouseMoved(const OIS::MouseEvent &arg)
{
	if (pant){
		// Set the new camera smooth direction movement
		Ogre::Vector2 distance(getScreenCenterMouseDistance());
		camera->setDirection(cameraDirection
			+ Ogre::Vector3(distance.x, -distance.y, 0) / 30);

		// Raycast for the actual panel
		Ogre::Real xMove = static_cast<Ogre::Real>(arg.state.X.rel);
		Ogre::Real yMove = static_cast<Ogre::Real>(arg.state.Y.rel);

		mNormalizedMousePosition.x += xMove / view->getActualWidth();
		mNormalizedMousePosition.y += yMove / view->getActualHeight();

		mNormalizedMousePosition.x = std::max<Ogre::Real>(mNormalizedMousePosition.x, 0);
		mNormalizedMousePosition.y = std::max<Ogre::Real>(mNormalizedMousePosition.y, 0);
		mNormalizedMousePosition.x = std::min<Ogre::Real>(mNormalizedMousePosition.x, 1);
		mNormalizedMousePosition.y = std::min<Ogre::Real>(mNormalizedMousePosition.y, 1);

		mMousePointer->position(
			mNormalizedMousePosition.x * view->getActualWidth(),
			mNormalizedMousePosition.y * view->getActualHeight());

		mSPanel2->injectMouseMoved(mNormalizedMousePosition.x * view->getActualWidth(),
			mNormalizedMousePosition.y * view->getActualHeight());
	}
	else {
		Ogre::Real pitch = Ogre::Real(arg.state.Y.rel) * -0.005f;
		Ogre::Real yaw = Ogre::Real(arg.state.X.rel) * -0.005f;
		camera->pitch(Ogre::Radian(pitch));
		camera->yaw(Ogre::Radian(yaw));
		mPanel->injectMouseMoved(camera->getCameraToViewportRay(0.5f, 0.5f));
	}

	return true;
}

GUI::~GUI()
{
	delete mSPanel2;
	mMousePointer = nullptr;
	mMousePointerLayer->destroyAllRectangles();
	mGui3D->getScreen("mainScreen")->destroy(mMousePointerLayer);
	mGui3D->destroyScreen(myScreen);
	delete mGui3D;
	delete mMyPurplePanelColors;
	menu = nullptr;
	scn = nullptr;
	camera = nullptr;
	cNode = nullptr;
	icomp_ = nullptr;
	view = nullptr;
}
