#pragma once
#include "InputComponent.h"
#include "Entidad.h"
#include <OgreRenderWindow.h>
class PlayerController_c :
	public InputComponent
{
public:
	PlayerController_c(Entidad* ent, InputComponent * input);
	void Update();

	~PlayerController_c();
private:
	bool keyPressed(const OIS::KeyEvent& keyP);
	bool keyReleased(const OIS::KeyEvent& keyP);
	bool mouseMoved(const OIS::MouseEvent& me);
	bool mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	InputComponent* inputcomp_;
	Entidad* entidad;
	float auxX, auxY, auxZ;
	bool mas, istimetoStop;
};

