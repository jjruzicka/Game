#include "CameraMove_c.h"
CameraMove_c::CameraMove_c(Entidad* eCam, Entidad* eJug, Ogre::SceneNode* camNode, InputComponent * input)
	: entidadCamara(eCam), entidadJugador(eJug), cam_node(camNode), inputcomp_(input){
	spd = 10;
	inputcomp_->addKeyListener(this, "teclado");
	inputcomp_->addMouseListener(this, "raton");
	distMax = 10;
	//turn_spd = 12;
	//pitch_spd = 4;
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
	cam_node->lookAt(Ogre::Vector3(entidadJugador->getPox(), entidadJugador->getPoy(), entidadJugador->getPoz()), Ogre::Node::TS_WORLD);
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
		//entidad->setPox(1);
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
		/*mCamNode->yaw(Ogre::Degree(-mRotate * me.state.X.rel), Ogre::Node::TS_WORLD);
		mCamNode->pitch(Ogre::Degree(-mRotate * me.state.Y.rel), Ogre::Node::TS_LOCAL);*/

		float horizontal = me.state.X.rel * spd;
		//target.transform.Rotate(0, horizontal, 0);


		float desiredAngle = entidadJugador->getRoy();
		//float desiredAngle = target.transform.eulerAngles.y;
		//entidadCamara->setPoz
		//Quaternion rotation = Quaternion.Euler(0, desiredAngle, 0);
		//transform.position = target.transform.position - (rotation * offset);

		//transform.LookAt(target.transform);
	}

	return true;
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
	return true;
}