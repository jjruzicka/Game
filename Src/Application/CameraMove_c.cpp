#include "CameraMove_c.h"
#include <iostream>
#include <math.h>
const float PI = 3.141592653f;
CameraMove_c::CameraMove_c(Entidad* eCam, Entidad* eJug, Ogre::SceneNode* camNode, InputComponent * input)
	: entidadCamara(eCam), entidadJugador(eJug), cam_node(camNode), inputcomp_(input){
	spd = 0.2;
	follow_spd = 2;
	inputcomp_->addKeyListener(this, "teclado2");
	inputcomp_->addMouseListener(this, "raton2");
	entidadCamara->setPox(cam_node->getPosition().x);
	entidadCamara->setPoy(cam_node->getPosition().y);
	entidadCamara->setPoz(cam_node->getPosition().z);
	distMin = 20;
	offset = Ogre::Vector3((entidadJugador->getPox() - entidadCamara->getPox()),
		(entidadJugador->getPoy() - entidadCamara->getPoy()),
		(entidadJugador->getPoz() - entidadCamara->getPoz()));
		// offset = target.transform.position - transform.position;
	//turn_spd = 12;
	//pitch_spd = 4;
	angulo = -90;
	cam_node->setFixedYawAxis(true);
}
CameraMove_c::~CameraMove_c()
{
	inputcomp_->removeKeyListener(this);
	inputcomp_->removeMouseListener(this);
}

/*void CameraMove_c::updateKey(float dt, const OIS::KeyEvent& keyP){

}
void CameraMove_c::updateMouse(float dt, const OIS::MouseEvent& me){
	cam_node->yaw(Ogre::Degree(dt * -me.state.X.rel * turn_spd));
	cam_node->pitch(Ogre::Degree(dt * -me.state.Y.rel * pitch_spd));
}*/

void CameraMove_c::Update(){
	if (entidadCamara->getPox() > entidadJugador->getPox() + distMin)
	{
		entidadCamara->setPox(entidadCamara->getPox() - follow_spd);
	}
	else if (entidadCamara->getPox() < entidadJugador->getPox() - distMin){
		entidadCamara->setPox(entidadCamara->getPox() + follow_spd);
	}

	if (entidadCamara->getPoz() > entidadJugador->getPoz() + distMin)
	{
		entidadCamara->setPoz(entidadCamara->getPoz() - follow_spd);
	}
	else if (entidadCamara->getPoz() < entidadJugador->getPoz() - distMin){
		entidadCamara->setPoz(entidadCamara->getPoz() + follow_spd);
	}

	cam_node->setPosition(entidadCamara->getPox(), entidadCamara->getPoy(), entidadCamara->getPoz());

	//cam_node->lookAt(Ogre::Vector3(entidadJugador->getPox(), entidadJugador->getPoy(), entidadJugador->getPoz()), Ogre::Node::TS_WORLD);

}

bool CameraMove_c::keyPressed(const OIS::KeyEvent& keyP)
{
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
		break;

	case OIS::KC_DOWN:
	case OIS::KC_S:
		/*mDirection.z = mMove;*/
		break;

	case OIS::KC_LEFT:
	case OIS::KC_A:
		/*mDirection.x = -mMove;*/
		break;

	case OIS::KC_RIGHT:
	case OIS::KC_D:
		/*mDirection.x = mMove;*/
		break;

	case OIS::KC_PGDOWN:
	case OIS::KC_E:
		/*mDirection.y = -mMove;*/
		break;

	case OIS::KC_PGUP:
	case OIS::KC_Q:
		/*mDirection.y = mMove;*/
		break;

	default:
		break;
	}

	return true;
}



bool CameraMove_c::keyReleased(const OIS::KeyEvent& keyP){
	switch (keyP.key)
	{
	case OIS::KC_UP:
	case OIS::KC_W:
		//entidad->setPox(0);
		break;

	case OIS::KC_DOWN:
	case OIS::KC_S:
		/*mDirection.z = 0;*/
		break;

	case OIS::KC_LEFT:
	case OIS::KC_A:
		/*mDirection.x = 0;*/
		break;

	case OIS::KC_RIGHT:
	case OIS::KC_D:
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

bool CameraMove_c::mouseMoved(const OIS::MouseEvent& me)
{
	if (me.state.buttonDown(OIS::MB_Right))
	{

		Ogre::Quaternion quat = cam_node->getOrientation();
		Ogre::Degree gradosExtra = Ogre::Degree(quat.getYaw());
		angulo = (-gradosExtra.valueDegrees() + 90);

		float horizontal = me.state.X.rel *spd;
		angulo += horizontal;

		if (angulo >= 360)
			angulo -= 300;
		if (angulo <= -360)
			angulo += 360;

		float t = angulo * PI / 180;
		float x, y;
		calculaOffset();
		float distancia = sqrtf(pow(offset.x, 2) + pow(offset.z, 2));
		x = distancia* cosf(t) + entidadJugador->getPox();
		y = distancia* sinf(t) + entidadJugador->getPoz();

		entidadCamara->setPox(x);
		entidadCamara->setPoz(y);
		
		//cam_node->roll(Ogre::Degree(-horizontal / 2.25), Ogre::Node::TS_LOCAL);
	}

	return true;
}

void CameraMove_c::calculaOffset(){
	offset = Ogre::Vector3((entidadJugador->getPox() - entidadCamara->getPox()),
		(entidadJugador->getPoy() - entidadCamara->getPoy()),
		(entidadJugador->getPoz() - entidadCamara->getPoz()));
}

bool CameraMove_c::mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id)
{
	/*Ogre::Light* light = mSceneMgr->getLight("Light1");*/

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

bool CameraMove_c::mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id)
{
	/*switch (id)
	{
	case OIS::MB_Right:
		angulo = 0;
		break;
	default:
		break;
	}*/
	return true;
}