#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H
#include "Entidad.h"
#include "Component.h"
#include "Ogre.h"
#include <OISMouse.h>
#include <OISKeyboard.h>
#include <OISJoyStick.h>
#include <OISInputManager.h>
#include <OgreRenderWindow.h>

class InputManager : OIS::KeyListener , OIS::MouseListener
{
public:
	static InputManager * getInstancia(){
		if (instancia == nullptr)
			instancia = new InputManager();
		return instancia;
	}
	void initialise(Ogre::RenderWindow *renderWindow);
	void capture(void);

	void addKeyListener(OIS::KeyListener *keyListener, const std::string& instanceName);
	void addMouseListener(OIS::MouseListener *mouseListener, const std::string& instanceName);

	void removeKeyListener(const std::string& instanceName);
	void removeMouseListener(const std::string& instanceName);


	void removeKeyListener(OIS::KeyListener *keyListener);
	void removeMouseListener(OIS::MouseListener *mouseListener);


	void removeAllListeners(void);
	void removeAllKeyListeners(void);
	void removeAllMouseListeners(void);
	void setWindowExtents(int width, int height);
	Entidad* entidad;
	OIS::Mouse*    getMouse(void);
	OIS::Keyboard* getKeyboard(void);

private:
	InputManager();
	virtual ~InputManager();
	InputManager(const InputManager&) { }
	InputManager & operator = (const InputManager& i);

	bool keyPressed(const OIS::KeyEvent &e);
	bool keyReleased(const OIS::KeyEvent &e);

	bool mouseMoved(const OIS::MouseEvent &e);
	bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);


	OIS::Mouse        *mMouse;
	OIS::Keyboard     *mKeyboard;
	OIS::InputManager *mInputSystem;
	Ogre::RenderWindow *renderWindow;

	std::map<std::string, OIS::KeyListener*> mKeyListeners;
	std::map<std::string, OIS::MouseListener*> mMouseListeners;

	std::map<std::string, OIS::KeyListener*>::iterator itKeyListener;
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListener;

	std::map<std::string, OIS::KeyListener*>::iterator itKeyListenerEnd;
	std::map<std::string, OIS::MouseListener*>::iterator itMouseListenerEnd;

	static InputManager *instancia;
};
#endif

