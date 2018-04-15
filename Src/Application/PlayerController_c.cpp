#include "PlayerController_c.h"
#include <iostream>
#include "Camera_c.h"

PlayerController_c::PlayerController_c(Entidad * ent, InputComponent * input, Ogre::SceneNode * camNode)
{
	inputcomp_ = input;
	entidad = ent;
	inputcomp_->addKeyListener(this, "teclado");
	inputcomp_->addMouseListener(this, "raton");
}

bool PlayerController_c::keyPressed(const OIS::KeyEvent& keyP)
{
	Camera_c * miguel = new Camera_c(entidad, camaraNode);
	switch (keyP.key)
	{
	case OIS::KC_ESCAPE:
		//mShutDown = true;
		break;

	case OIS::KC_1:
		/*mCamera->getParentSceneNode()->detachObject(mCamera);
		mCamNode = mSceneMgr->getSceneNode("CamNode1");
		mCamNode->attachObject(mCamera);*/
		break;

	case OIS::KC_2:
		/*mCamera->getParentSceneNode()->detachObject(mCamera);
		mCamNode = mSceneMgr->getSceneNode("CamNode2");
		mCamNode->attachObject(mCamera);*/
		break;

	case OIS::KC_UP:
	case OIS::KC_W:
		entidad->setPoz(1);
		entidad->GetComponent(miguel)->updateKey(0.1, keyP);
		
		break;

	case OIS::KC_DOWN:
	case OIS::KC_S:
		entidad->setPoz(-1);
		entidad->GetComponent(miguel)->updateKey(0.1, keyP);
		/*mDirection.z = mMove;*/
		break;

	case OIS::KC_LEFT:
	case OIS::KC_A:
		entidad->setPox(-1);
		entidad->GetComponent(miguel)->updateKey(0.1, keyP);
		/*mDirection.x = -mMove;*/
		break;

	case OIS::KC_RIGHT:
	case OIS::KC_D:
		entidad->setPox(1);
		entidad->GetComponent(miguel)->updateKey(0.1, keyP);
		/*mDirection.x = mMove;*/
		break;

	case OIS::KC_PGDOWN:
	case OIS::KC_E:
		/*mDirection.y = -mMove;*/
		break;

	case OIS::KC_PGUP:
	case OIS::KC_Q:
		std::cout << entidad->getPox() << ", " << entidad->getPoy() << ", " << entidad->getPoz() << "\n";
		std::cout << "Globales: " << entidad->getGPox() << ", " << entidad->getGPoy() << ", " << entidad->getGPoz() << "\n";
		/*mDirection.y = mMove;*/
		break;

	default:
		break;
	}

	return true;
}
	


bool PlayerController_c::keyReleased(const OIS::KeyEvent& keyP){
	Camera_c * miguel = new Camera_c(entidad, camaraNode);
	switch (keyP.key)
	{
	case OIS::KC_UP:
	case OIS::KC_W:
		entidad->setPoz(0);
		entidad->GetComponent(miguel)->releaseKey(keyP);
		
		break;

	case OIS::KC_DOWN:
	case OIS::KC_S:
		entidad->setPoz(0);
		/*mDirection.z = 0;*/

		break;

	case OIS::KC_LEFT:
	case OIS::KC_A:
		entidad->setPox(0);
		/*mDirection.x = 0;*/
		break;

	case OIS::KC_RIGHT:
	case OIS::KC_D:
		entidad->setPox(0);
		/*mDirection.x = 0;*/
		break;

	case OIS::KC_PGDOWN:
	case OIS::KC_E:
		/*mDirection.y = 0;*/
		break;

	case OIS::KC_PGUP:
	case OIS::KC_Q:
		/*mDirection.y = 0;*/
		break;

	default:
		break;
	}

	return true;

}

bool PlayerController_c::mouseMoved(const OIS::MouseEvent& me)
{
	if (me.state.buttonDown(OIS::MB_Right))
	{
		Camera_c * oscar = new Camera_c(entidad, camaraNode);
		entidad->GetComponent(oscar)->updateMouse(0.1, me);
		/*mCamNode->yaw(Ogre::Degree(-mRotate * me.state.X.rel), Ogre::Node::TS_WORLD);
		mCamNode->pitch(Ogre::Degree(-mRotate * me.state.Y.rel), Ogre::Node::TS_LOCAL);*/
	}

	return true;
}

bool PlayerController_c::mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id)
{
	/*Ogre::Light* light = mSceneMgr->getLight("Light1");*/
	/*cameraComp->updateMouse(1, me);
	std::cout << "//////////////////////////////////////////////////////////////////////";*/

	switch (id)
	{
	case OIS::MB_Left:
		/*light->setVisible(!light->isVisible());*/
		break;
	default:
		break;
	}

	return true;
}

bool PlayerController_c::mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id)
{
	return true;
}


void PlayerController_c::Update(){
	
	

}

PlayerController_c::~PlayerController_c()
{
	inputcomp_->removeKeyListener(this);
	inputcomp_->removeMouseListener(this);
}
