#ifndef CAMERA_MOVE_C_H
#define CAMERA_MOVE_C_H

#include <OgreCamera.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreRenderTarget.h>
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include "InputManager.h"

class CameraMove_c //: public InputComponent
{
public:
	CameraMove_c(Entidad* eCam, Entidad* eJug, Ogre::SceneNode* camNode/*, InputComponent * input*/);
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
	
};
#endif