#include "InputManager.h"
#include "MotorGrafico.h"

InputManager::InputManager() :mMouse(0),
mKeyboard(0),
mInputSystem(0)
{
	MotorGrafico * motorGrafico = MotorGrafico::getInstancia();
	initialise(motorGrafico->getWindow());
}


InputManager::~InputManager()
{
	if (mInputSystem) {
		if (mMouse) {
			mInputSystem->destroyInputObject(mMouse);
			mMouse = 0;
		}

		if (mKeyboard) {
			mInputSystem->destroyInputObject(mKeyboard);
			mKeyboard = 0;
		}
		mInputSystem->destroyInputSystem(mInputSystem);
		mInputSystem = 0;

		// Clear Listeners
		mKeyListeners.clear();
		mMouseListeners.clear();
	}


}

void InputManager::initialise(Ogre::RenderWindow *renderWindow) {
	if (!mInputSystem) {
		// Setup basic variables
		OIS::ParamList paramList;
		size_t windowHnd = 0;
		std::ostringstream windowHndStr;

		// Get window handle
		this->renderWindow = renderWindow;
		this->renderWindow->getCustomAttribute("WINDOW", &windowHnd);

		// Fill parameter list
		windowHndStr << (unsigned int)windowHnd;
		paramList.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
		paramList.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND")));
		paramList.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
		paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
		paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));

		// Create inputsystem
		mInputSystem = OIS::InputManager::createInputSystem(paramList);


		if (mInputSystem->getNumberOfDevices(OIS::OISKeyboard) > 0) {
			mKeyboard = static_cast<OIS::Keyboard*>(mInputSystem->createInputObject(OIS::OISKeyboard, true));
			mKeyboard->setEventCallback(this);
		}

		if (mInputSystem->getNumberOfDevices(OIS::OISMouse) > 0) {
			mMouse = static_cast<OIS::Mouse*>(mInputSystem->createInputObject(OIS::OISMouse, true));
			mMouse->setEventCallback(this);

			// Get window size
			unsigned int width, height, depth;
			int left, top;
			this->renderWindow->getMetrics(width, height, depth, left, top);

			// Set mouse region
			this->setWindowExtents(width, height);
		}
	}
}

void InputManager::capture(void) {
	// Need to capture / update each device every frame
	if (mMouse) {
		mMouse->capture();
	}

	if (mKeyboard) {
		mKeyboard->capture();
	}
}

void InputManager::addKeyListener(OIS::KeyListener *keyListener, const std::string& instanceName) {
	if (mKeyboard) {
		// Check for duplicate items
		std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.find(instanceName);
		if (itKeyListener == mKeyListeners.end()) {
			mKeyListeners[instanceName] = keyListener;
		}
		else {
			// Duplicate Item
		}
	}
}

void InputManager::addMouseListener(OIS::MouseListener *mouseListener, const std::string& instanceName) {
	if (mMouse) {
		// Check for duplicate items
		std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.find(instanceName);
		if (itMouseListener == mMouseListeners.end()) {
			mMouseListeners[instanceName] = mouseListener;
		}
		else {
			// Duplicate Item
		}
	}
}

void InputManager::removeKeyListener(const std::string& instanceName) {
	// Check if item exists
	std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.find(instanceName);
	if (itKeyListener != mKeyListeners.end()) {
		mKeyListeners.erase(itKeyListener);
	}
	else {
		// Doesn't Exist
	}
}

void InputManager::removeMouseListener(const std::string& instanceName) {
	// Check if item exists
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.find(instanceName);
	if (itMouseListener != mMouseListeners.end()) {
		mMouseListeners.erase(itMouseListener);
	}
	else {
		// Doesn't Exist
	}
}



void InputManager::removeKeyListener(OIS::KeyListener *keyListener) {
	std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
	std::map<std::string, OIS::KeyListener*>::iterator itKeyListenerEnd = mKeyListeners.end();
	for (; itKeyListener != itKeyListenerEnd; ++itKeyListener) {
		if (itKeyListener->second == keyListener) {
			mKeyListeners.erase(itKeyListener);
			break;
		}
	}
}

void InputManager::removeMouseListener(OIS::MouseListener *mouseListener) {
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListenerEnd = mMouseListeners.end();
	for (; itMouseListener != itMouseListenerEnd; ++itMouseListener) {
		if (itMouseListener->second == mouseListener) {
			mMouseListeners.erase(itMouseListener);
			break;
		}
	}
}


void InputManager::removeAllListeners(void) {
	mKeyListeners.clear();
	mMouseListeners.clear();
}

void InputManager::removeAllKeyListeners(void) {
	mKeyListeners.clear();
}

void InputManager::removeAllMouseListeners(void) {
	mMouseListeners.clear();
}



void InputManager::setWindowExtents(int width, int height) {
	const OIS::MouseState &mouseState = mMouse->getMouseState();
	mouseState.width = width;
	mouseState.height = height;
}

OIS::Mouse* InputManager::getMouse(void) {
	return mMouse;
}

OIS::Keyboard* InputManager::getKeyboard(void) {
	return mKeyboard;
}





bool InputManager::keyPressed(const OIS::KeyEvent &e) {
	std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
	std::map<std::string, OIS::KeyListener*>::iterator itKeyListenerEnd = mKeyListeners.end();
	for (; itKeyListener != itKeyListenerEnd; ++itKeyListener) {
		if (!itKeyListener->second->keyPressed(e))
			break;
	}

	return true;
}

bool InputManager::keyReleased(const OIS::KeyEvent &e) {
	std::map<std::string, OIS::KeyListener*>::iterator itKeyListener = mKeyListeners.begin();
	std::map<std::string, OIS::KeyListener*>::iterator itKeyListenerEnd = mKeyListeners.end();
	for (; itKeyListener != itKeyListenerEnd; ++itKeyListener) {
		if (!itKeyListener->second->keyReleased(e))
			break;
	}

	return true;
}

bool InputManager::mouseMoved(const OIS::MouseEvent &e) {
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListenerEnd = mMouseListeners.end();
	for (; itMouseListener != itMouseListenerEnd; ++itMouseListener) {
		if (!itMouseListener->second->mouseMoved(e))
			break;
	}

	return true;
}

bool InputManager::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id) {
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListenerEnd = mMouseListeners.end();
	for (; itMouseListener != itMouseListenerEnd; ++itMouseListener) {
		if (!itMouseListener->second->mousePressed(e, id))
			break;
	}

	return true;
}

bool InputManager::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id) {
	int tamInicial = mMouseListeners.size();
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListener = mMouseListeners.begin();
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListenerEnd = mMouseListeners.end();
	for (; itMouseListener != itMouseListenerEnd; ++itMouseListener) {
		if (!itMouseListener->second->mouseReleased(e, id) || mMouseListeners.size() != tamInicial)
			break;
	}

	return true;
}

