#ifndef CAMERA_H
#define CAMERA_H

#include <OgreCamera.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreRenderTarget.h>
#include "OgreRenderWindow.h"
#include "OgreViewport.h"

class Camera
{
public:
    Camera(Ogre::SceneNode* sn, Ogre::RenderWindow* rw);
    virtual ~Camera();

    void update(float dt);

    Ogre::SceneNode* getNode() { return node; }
    Ogre::Camera* getOgreCamera() { return cam; }

private:
    void initViewports();

    float spd, turn_spd, pitch_spd;

    Ogre::Camera* cam;
    Ogre::SceneNode* node;
    Ogre::SceneNode* cam_node;
    Ogre::SceneNode* pitch_node;
    Ogre::RenderWindow* rndWindow;
};
#endif