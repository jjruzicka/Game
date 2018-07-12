#ifndef CAMERA_MOVE_C_H
#define CAMERA_MOVE_C_H

#include <OgreCamera.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreRenderTarget.h>
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include "InputManager.h"
#include "Camera_c.h"

class CameraMove_c : public Component
{
public:
	CameraMove_c(Entidad* ent, Entidad* eJug);
	~CameraMove_c();
	void Update();

private:

	float spd;
	int distMax;
	Ogre::Vector3 offset;
	bool mouseMoved(const OIS::MouseEvent& me);
	bool mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	void calculaOffset();
	//InputComponent* inputcomp_;

	Ogre::SceneNode* cam_node;
	float angulo;

	Entidad* entidadJugador;
	Entidad* entidadCamara;

	// getComponent
	Camera_c * camComponent;
};
#endif