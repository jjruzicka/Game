#pragma once
#ifndef CAMERA_MOVE_C_H
#define CAMERA_MOVE_C_H

#include <OgreCamera.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreRenderTarget.h>
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include "InputComponent.h"

class CameraMove_c : public InputComponent
{
public:
	CameraMove_c(Entidad* eCam, Entidad* eJug, Ogre::SceneNode* camNode, InputComponent * input);
	~CameraMove_c();

	void Update();
	//void updateKey(float dt, const OIS::KeyEvent& keyP);
	//void updateMouse(float dt, const OIS::MouseEvent& me);
	/*void updateKey(float dt, const OIS::KeyEvent& keyP);
	void updateMouse(float dt, const OIS::MouseEvent& me);

	Ogre::SceneNode* getNode() { return node; }
	Ogre::Camera* getOgreCamera() { return cam; }
	*/
private:
	//void initViewports();

	float spd, follow_spd;// , turn_spd, pitch_spd;
	int distMin;
	Ogre::Vector3 offset;
	bool keyPressed(const OIS::KeyEvent& keyP);
	bool keyReleased(const OIS::KeyEvent& keyP);
	bool mouseMoved(const OIS::MouseEvent& me);
	bool mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	void calculaOffset();
	InputComponent* inputcomp_;
	//Ogre::Camera* cam;
	//Ogre::SceneNode* node;
	Ogre::SceneNode* cam_node;
	float angulo;
	//Ogre::SceneNode* pitch_node;
	//Ogre::RenderWindow* rndWindow;
	//InputComponent* input;

	Entidad* entidadJugador;
	Entidad* entidadCamara;
	Ogre::Vector3 posAnterior;
	
};
#endif