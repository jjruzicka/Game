#include "Camera_c.h"
#include "iostream"
Camera_c::Camera_c(Entidad* e, Ogre::SceneNode* camNode) : entidad(e), cam_node(camNode){
	spd = 10;
	turn_spd = 12;
	pitch_spd = 4;
	//teclaPulsada = false;
	/*x = 0;
	y = 0;*/
}
Camera_c::~Camera_c(){

}
void Camera_c::updateKey(float dt, const OIS::KeyEvent& keyP){
	//cam_node->translate(Ogre::Vector3(entidad->getGPox(), entidad->getGPoy(), 0));
	//teclaPulsada = true;
	//cam_node->setPosition(Ogre::Vector3(entidad->getGPox(), entidad->getGPoy(), 100));
}
void Camera_c::updateMouse(float dt, const OIS::MouseEvent& me){
    //cam_node->rotate(Ogre::Vector3(0, 1, 0), Ogre::Degree(dt * -me.state.X.rel * turn_spd));
    if (me.state.X.rel != 0){
        float sammy = std::abs(dt * -me.state.X.rel * turn_spd);
        entidad->setVRot(sammy/2);
        if (me.state.X.rel > 0)
            entidad->setRoy(1);
        else
            entidad->setRoy(-1);
    }
    

    //cam_node->yaw(Ogre::Degree(dt * -me.state.X.rel * turn_spd));
    std::cout << me.state.X.rel << std::endl;
  // cam_node->pitch(Ogre::Degree(dt * -me.state.Y.rel * pitch_spd));
}


void Camera_c::releaseMouse(){
	//teclaPulsada = false;
    entidad->setRoy(0);
}