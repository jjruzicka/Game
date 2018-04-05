#include "InputComponent.h"

InputComponent *InputComponent::mInputComponent;

InputComponent::InputComponent(Entidad* ent) :mMouse(0),
mKeyboard(0),
mInputSystem(0)
{
	entidad = ent;
}


InputComponent::~InputComponent()
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
		//mInputSystem->destroyInputSystem();
		mInputSystem = 0;

		// Clear Listeners
		mKeyListeners.clear();
		mMouseListeners.clear();
		mJoystickListeners.clear();
	}


}

void InputComponent::initialise(Ogre::RenderWindow *renderWindow) {
	if (!mInputSystem) {
		// Setup basic variables
		OIS::ParamList paramList;
		size_t windowHnd = 0;
		std::ostringstream windowHndStr;

		// Get window handle
		renderWindow->getCustomAttribute("WINDOW", &windowHnd);

		// Fill parameter list
		windowHndStr << (unsigned int)windowHnd;
		paramList.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
		paramList.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND")));
		paramList.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
		paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
		paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));

		// Create inputsystem
		mInputSystem = OIS::InputManager::createInputSystem(paramList);

		// If possible create a buffered keyboard
		// (note: if below line doesn't compile, try:  if (mInputSystem->getNumberOfDevices(OIS::OISKeyboard) > 0) {
		//if( mInputSystem->numKeyboards() > 0 ) {
		if (mInputSystem->getNumberOfDevices(OIS::OISKeyboard) > 0) {
			mKeyboard = static_cast<OIS::Keyboard*>(mInputSystem->createInputObject(OIS::OISKeyboard, true));
			mKeyboard->setEventCallback(this);
		}

		// If possible create a buffered mouse
		// (note: if below line doesn't compile, try:  if (mInputSystem->getNumberOfDevices(OIS::OISMouse) > 0) {
		//if( mInputSystem->numMice() > 0 ) {
		if (mInputSystem->getNumberOfDevices(OIS::OISMouse) > 0) {
			mMouse = static_cast<OIS::Mouse*>(mInputSystem->createInputObject(OIS::OISMouse, true));
			mMouse->setEventCallback(this);

			// Get window size
			unsigned int width, height, depth;
			int left, top;
			renderWindow->getMetrics(width, height, depth, left, top);

			// Set mouse region
			this->setWindowExtents(width, height);
		}
	}
}

void InputComponent::capture(void) {
	// Need to capture / update each device every frame
	if (mMouse) {
		mMouse->capture();
	}

	if (mKeyboard) {
		mKeyboard->capture();
	}
}

void InputComponent::addKeyListener(OIS::KeyListener *keyListener, const std::string& instanceName) {
	if (mKeyboard) {
		// Check for duplicate items
		itKeyListener = mKeyListeners.find(instanceName);
		if (itKeyListener == mKeyListeners.end()) {
			mKeyListeners[instanceName] = keyListener;
		}
		else {
			// Duplicate Item
		}
	}
}

void InputComponent::addMouseListener(OIS::MouseListener *mouseListener, const std::string& instanceName) {
	if (mMouse) {
		// Check for duplicate items
		itMouseListener = mMouseListeners.find(instanceName);
		if (itMouseListener == mMouseListeners.end()) {
			mMouseListeners[instanceName] = mouseListener;
		}
		else {
			// Duplicate Item
		}
	}
}

void InputComponent::removeKeyListener(const std::string& instanceName) {
	// Check if item exists
	itKeyListener = mKeyListeners.find(instanceName);
	if (itKeyListener != mKeyListeners.end()) {
		mKeyListeners.erase(itKeyListener);
	}
	else {
		// Doesn't Exist
	}
}

void InputComponent::removeMouseListener(const std::string& instanceName) {
	// Check if item exists
	itMouseListener = mMouseListeners.find(instanceName);
	if (itMouseListener != mMouseListeners.end()) {
		mMouseListeners.erase(itMouseListener);
	}
	else {
		// Doesn't Exist
	}
}



void InputComponent::removeKeyListener(OIS::KeyListener *keyListener) {
	itKeyListener = mKeyListeners.begin();
	itKeyListenerEnd = mKeyListeners.end();
	for (; itKeyListener != itKeyListenerEnd; ++itKeyListener) {
		if (itKeyListener->second == keyListener) {
			mKeyListeners.erase(itKeyListener);
			break;
		}
	}
}

void InputComponent::removeMouseListener(OIS::MouseListener *mouseListener) {
	itMouseListener = mMouseListeners.begin();
	itMouseListenerEnd = mMouseListeners.end();
	for (; itMouseListener != itMouseListenerEnd; ++itMouseListener) {
		if (itMouseListener->second == mouseListener) {
			mMouseListeners.erase(itMouseListener);
			break;
		}
	}
}


void InputComponent::removeAllListeners(void) {
	mKeyListeners.clear();
	mMouseListeners.clear();
	mJoystickListeners.clear();
}

void InputComponent::removeAllKeyListeners(void) {
	mKeyListeners.clear();
}

void InputComponent::removeAllMouseListeners(void) {
	mMouseListeners.clear();
}



void InputComponent::setWindowExtents(int width, int height) {
	// Set mouse region (if window resizes, we should alter this to reflect as well)
	const OIS::MouseState &mouseState = mMouse->getMouseState();
	mouseState.width = width;
	mouseState.height = height;
}

OIS::Mouse* InputComponent::getMouse(void) {
	return mMouse;
}

OIS::Keyboard* InputComponent::getKeyboard(void) {
	return mKeyboard;
}





bool InputComponent::keyPressed(const OIS::KeyEvent &e) {
	itKeyListener = mKeyListeners.begin();
	itKeyListenerEnd = mKeyListeners.end();
	for (; itKeyListener != itKeyListenerEnd; ++itKeyListener) {
		if (!itKeyListener->second->keyPressed(e))
			break;
	}

	return true;
}

bool InputComponent::keyReleased(const OIS::KeyEvent &e) {
	itKeyListener = mKeyListeners.begin();
	itKeyListenerEnd = mKeyListeners.end();
	for (; itKeyListener != itKeyListenerEnd; ++itKeyListener) {
		if (!itKeyListener->second->keyReleased(e))
			break;
	}

	return true;
}

bool InputComponent::mouseMoved(const OIS::MouseEvent &e) {
	itMouseListener = mMouseListeners.begin();
	itMouseListenerEnd = mMouseListeners.end();
	for (; itMouseListener != itMouseListenerEnd; ++itMouseListener) {
		if (!itMouseListener->second->mouseMoved(e))
			break;
	}

	return true;
}

bool InputComponent::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id) {
	itMouseListener = mMouseListeners.begin();
	itMouseListenerEnd = mMouseListeners.end();
	for (; itMouseListener != itMouseListenerEnd; ++itMouseListener) {
		if (!itMouseListener->second->mousePressed(e, id))
			break;
	}

	return true;
}

bool InputComponent::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id) {
	itMouseListener = mMouseListeners.begin();
	itMouseListenerEnd = mMouseListeners.end();
	for (; itMouseListener != itMouseListenerEnd; ++itMouseListener) {
		if (!itMouseListener->second->mouseReleased(e, id))
			break;
	}

	return true;
}


InputComponent* InputComponent::getSingletonPtr(void) {
	if (!mInputComponent) {
		mInputComponent = new InputComponent();
	}

	return mInputComponent;
}
