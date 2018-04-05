#include "Camera.h"

Camera::Camera(Ogre::SceneNode* sn, Ogre::RenderWindow* rw)
    : spd(10),
    turn_spd(12),
    pitch_spd(4),
    node(sn),
    cam_node(0),
    pitch_node(0),
    rndWindow(rw)
{
    cam = node->getCreator()->createCamera("UserCamera");
    cam->setNearClipDistance(.1);
    cam_node = node->createChildSceneNode();
    cam_node->setPosition(0, 1.8, 3);
    pitch_node = cam_node->createChildSceneNode();
    pitch_node->attachObject(cam);

    initViewports();
}

void Camera::initViewports()
{
    Ogre::Viewport* vp = rndWindow->addViewport(cam);
        
    vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

    cam->setAspectRatio(
        Ogre::Real(vp->getActualWidth()) /
        Ogre::Real(vp->getActualHeight()));
}
void Camera::update(float dt){
    Ogre::Vector3 movement(0, 0, 0);
    Ogre::Vector3 direction = node->getOrientation() * Ogre::Vector3::NEGATIVE_UNIT_Z;
    direction.normalise();

    //GameManager::instance().player->runAnimation(false)

    //necesitamos el input de OIs
    const Input input = GameManager::instance().input_system->input;

    if (input.up)
        movement += direction;
    if (input.down)
        movement -= direction;
    if (input.right)
    {
        movement.x -= direction.z;
        movement.z += direction.x;
    }
    if (input.left)
    {
        movement.x += direction.z;
        movement.z -= direction.x;
    }

    if (movement.x == 0 && movement.z == 0)
    {
       // GameManager::instance().player->setAnimation("idle");
    }
    else
    {
        movement.normalise();;
        node->translate(dt * spd * movement);
        //GameManager::instance().player->setAnimation("walk");
    }

    node->yaw(Ogre::Degree(dt * -input.rot_x * turn_spd));
    pitch_node->pitch(Ogre::Degree(dt * -input.rot_y * pitch_spd));

   // GameManager::instance().player->runAnimation(true);


}