#include "PlayerController_c.h"


PlayerController_c::PlayerController_c(Entidad * ent) : entidad(ent)
{
	OIS::ParamList param;
	unsigned int windowHandle;
	std::ostringstream wHandleStr;

	win->getCustomAttribute("WINDOW", &windowHandle);
	wHandleStr << windowHandle;
	param.insert(std::make_pair("WINDOW", wHandleStr.str()));

	_inputManager = OIS::InputManager::createInputSystem(param);
	_keyboard = static_cast<OIS::Keyboard*>(_inputManager->createInputObject(OIS::OISKeyboard, false));
	_mouse = static_cast<OIS::Mouse*>(_inputManager->createInputObject(OIS::OISMouse, false));

}



void PlayerController_c::Update(){
	frameStarted();
}

bool PlayerController_c::frameStarted(/*const Ogre::FrameEvent& evt*/){
	_keyboard->capture();
	if (_keyboard->isKeyDown(OIS::KC_ESCAPE)) return false;
	if (_keyboard->isKeyDown(OIS::KC_UP)) return true;
	if (_keyboard->isKeyDown(OIS::KC_DOWN)) return true;
	if (_keyboard->isKeyDown(OIS::KC_LEFT)) return true;
	if (_keyboard->isKeyDown(OIS::KC_RIGHT)) return true;

	_mouse->capture();
	bool leftMouseDown = _mouse->getMouseState().buttonDown(OIS::MB_Left);
	bool rightMouseDown = _mouse->getMouseState().buttonDown(OIS::MB_Right);
}

PlayerController_c::~PlayerController_c()
{
	_inputManager->destroyInputObject(_keyboard);
	_inputManager->destroyInputObject(_mouse);
	OIS::InputManager::destroyInputSystem(_inputManager);
}
