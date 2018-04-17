#pragma once
#ifndef CAMERA_C_H
#define CAMERA_C_H

#include <OgreCamera.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreRenderTarget.h>
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include "PlayerController_c.h"
//#include "InputComponent.h"

class Camera_c : public Component
{
public:
    Camera_c(Entidad* e, Ogre::SceneNode* camNode);
    ~Camera_c();

    void Update(){}
    void updateKey(float dt, const OIS::KeyEvent& keyP);
    void updateMouse(float dt, const OIS::MouseEvent& me);

    void releaseMouse();
    /*void updateKey(float dt, const OIS::KeyEvent& keyP);
    void updateMouse(float dt, const OIS::MouseEvent& me);

    Ogre::SceneNode* getNode() { return node; }
    Ogre::Camera* getOgreCamera() { return cam; }
    */
private:
    //void initViewports();

    float spd, turn_spd, pitch_spd;
	//float x, y;
    //Ogre::Camera* cam;
    //Ogre::SceneNode* node;
    Ogre::SceneNode* cam_node;
	//bool teclaPulsada;
    //Ogre::SceneNode* pitch_node;
    //Ogre::RenderWindow* rndWindow;
    //InputComponent* input;

    Entidad* entidad;
};
#endif