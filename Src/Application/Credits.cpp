#include "Credits.h"
#include "Render_c.h"
#include "PlayerController_c.h"
#include "RigidBody_c.h"
#include "Objeto.h"
#include "Collider_c.h"


Credits::Credits(EscenasManager* scnM)
{
#ifdef _DEBUG
	plugins = "OgreD/plugins_d.cfg";
	recursos = "OgreD/resources_d.cfg";
#else
	plugins = "Ogre/plugins.cfg";
	recursos = "Ogre/resources.cfg";
#endif
	Escenas::initOgre();
	Escenas::initBullet();

	this->scnM = scnM;


	inputcomp_ = InputComponent::getSingletonPtr();
	inputcomp_->initialise(mWindow);

	inputcomp_->addKeyListener(this, "teclado2");
	inputcomp_->addMouseListener(this, "raton2");

	Entidad* ent1 = new Entidad();
	//1683, 50, 2116
	ent1->setPox(1700);// posicion 
	ent1->setPoy(50);
	ent1->setPoz(2000); //cuanto menor sea el numero, mas se aleja de la camara
	Render_c* render = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode("personaje"), ent1, "Sinbad");
	PlayerController_c * ois = new PlayerController_c(ent1, inputcomp_);
	ent1->AddComponent(render);
	ent1->AddComponent(ois);
	entidades.push_back(ent1);
	
	Ogre::Vector3 lightdir(0.55, -0.3, 0.75);
	lightdir.normalise();

	Ogre::Light* light = scnMgr->createLight("tstLight");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(lightdir);
	light->setDiffuseColour(Ogre::ColourValue::White);
	light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));

	scnMgr->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));
	
	// also need to tell where we are
	camNode = scnMgr->getSceneNode("personaje")->createChildSceneNode();
	/*camNode->setPosition(0, 0, 100);
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_WORLD); //esto lo que habia antes
	*/
	// para la escena, pruebas
	camNode->setPosition(Ogre::Vector3(0, 2, -2));
	camNode->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3::UNIT_Y));
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	// create the camera
	cam = scnMgr->createCamera("Cam");
	cam->setNearClipDistance(0.1); //esto antes era 1
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	//cam->setPolygonMode(Ogre::PM_WIREFRAME);  // en material
	camNode->attachObject(cam);
	


	cameraDirection = Ogre::Vector3(0, 0, -1);
	cam->setDirection(cameraDirection);



	// and tell it to render into the main window
	vp = mWindow->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue::Black);

	mGui3D = new Gui3D::Gui3D(&mMyPurplePanelColors);
	mGui3D->createScreen(vp, "purple", "mainScreen");

	// Create a layer for the mousePointer
	mNormalizedMousePosition = Ogre::Vector2(0.5, 0.5);
	mMousePointerLayer = mGui3D->getScreen("mainScreen")->createLayer(2);

	mMousePointer = mMousePointerLayer->createRectangle(vp->getActualWidth() / 2,
		vp->getActualHeight() / 2, 12, 18);
	mMousePointer->background_image("mousepointer");



	createPanel();


}

void Credits::createPanel(){
	Gorilla::Screen* myScreen = mGui3D->getScreen("mainScreen");


	// 2nd test panel
	mSPanel2 = new Gui3D::ScreenPanel(
		mGui3D,
		myScreen,
		Ogre::Vector2(300, 200),
		Ogre::Vector2(400, 400),
		"purple",
		"test_screenPanel2");

	mSPanel2->makeButton(0, 500, 400, 100, "MENU")
		->setPressedCallback(this, &Credits::creditsToMenu);


	mSPanel2->hideInternalMousePointer();
}

bool Credits::creditsToMenu(Gui3D::PanelElement* e){
	scnM->CreditsToMenu();
	return true;
}
bool Credits::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
	mSPanel2->injectMousePressed(evt, id);
	return true;
}

bool Credits::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{

	mSPanel2->injectMouseReleased(evt, id);
	return true;
}

Ogre::Vector2 Credits::getScreenCenterMouseDistance()
{
	Ogre::Real posX = (mMousePointer->position().x - vp->getActualWidth())
		/ vp->getActualWidth();
	Ogre::Real posY = (mMousePointer->position().y - vp->getActualHeight())
		/ vp->getActualHeight();

	return Ogre::Vector2(posX + 0.5, posY + 0.5);
}

bool Credits::mouseMoved(const OIS::MouseEvent &arg)
{
	// Set the new camera smooth direction movement
	Ogre::Vector2 distance(getScreenCenterMouseDistance());
	cam->setDirection(cameraDirection
		+ Ogre::Vector3(distance.x, -distance.y, 0) / 30);

	// Raycast for the actual panel
	Ogre::Real xMove = static_cast<Ogre::Real>(arg.state.X.rel);
	Ogre::Real yMove = static_cast<Ogre::Real>(arg.state.Y.rel);

	mNormalizedMousePosition.x += xMove / vp->getActualWidth();
	mNormalizedMousePosition.y += yMove / vp->getActualHeight();

	mNormalizedMousePosition.x = std::max<Ogre::Real>(mNormalizedMousePosition.x, 0);
	mNormalizedMousePosition.y = std::max<Ogre::Real>(mNormalizedMousePosition.y, 0);
	mNormalizedMousePosition.x = std::min<Ogre::Real>(mNormalizedMousePosition.x, 1);
	mNormalizedMousePosition.y = std::min<Ogre::Real>(mNormalizedMousePosition.y, 1);

	mMousePointer->position(
		mNormalizedMousePosition.x * vp->getActualWidth(),
		mNormalizedMousePosition.y * vp->getActualHeight());


	mSPanel2->injectMouseMoved(mNormalizedMousePosition.x * vp->getActualWidth(),
		mNormalizedMousePosition.y * vp->getActualHeight());

	return true;
}

bool Credits::run(){


	clock_t lastTicks = clock();
	clock_t elapsedTicks = 0;
	double deltaTime = 0;


	while (true)
	{
		deltaTime = ((double)elapsedTicks) / 1000.f/*CLOCKS_PER_SEC*/;
		lastTicks = clock();

		inputcomp_->capture();

		for (int i = 0; i<entidades.size(); i++)
			entidades[i]->Update();



		// render ogre
		Ogre::WindowEventUtilities::messagePump();
		//bulletWorld->stepSimulation((float)deltaTime);

		//comprobar si la ventana está abierta
		if (mWindow->isClosed())return false;
		if (!root->renderOneFrame())return false;
		elapsedTicks = clock() - lastTicks;
	}
	
	return true;
}


	

Credits::~Credits()
{
	scnMgr->getRootSceneNode()->removeAllChildren();
	root->destroySceneManager(scnMgr);
	root->destroyRenderTarget("P3");
	delete root;
}

