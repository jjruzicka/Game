#include "CameraMove_c.h"
#include <iostream>
#include <math.h>
const float PI = 3.141592653f;
CameraMove_c::CameraMove_c(Entidad* eCam, Entidad* eJug, Ogre::SceneNode* camNode, InputComponent * input)
	: entidadCamara(eCam), entidadJugador(eJug), cam_node(camNode), inputcomp_(input){
	spd = 0.2;
	inputcomp_->addMouseListener(this, "raton2");
	entidadCamara->setPox(cam_node->getPosition().x);
	entidadCamara->setPoy(cam_node->getPosition().y);
	entidadCamara->setPoz(cam_node->getPosition().z);
	distMax = 25;
	offset = Ogre::Vector3((entidadJugador->getPox() - entidadCamara->getPox()),
		(entidadJugador->getPoy() - entidadCamara->getPoy()),
		(entidadJugador->getPoz() - entidadCamara->getPoz()));


	angulo = -90;
	cam_node->setFixedYawAxis(true);
}
CameraMove_c::~CameraMove_c()
{
	inputcomp_->removeKeyListener(this);
	inputcomp_->removeMouseListener(this);
}

void CameraMove_c::Update(){
	calculaOffset();
	float distancia = sqrtf(pow(offset.x, 2) + pow(offset.z, 2));
	if (distancia > distMax){
		if (entidadCamara->getPoz() > entidadJugador->getPoz() + distMax){
			entidadCamara->setPoz(entidadJugador->getPoz() + distMax);
		}

		else if (entidadCamara->getPoz() < entidadJugador->getPoz() - distMax){
			entidadCamara->setPoz(entidadJugador->getPoz() - distMax);
		}
		if (entidadCamara->getPox() > entidadJugador->getPox() + distMax){
			entidadCamara->setPox(entidadJugador->getPox() + distMax);
		}

		else if (entidadCamara->getPox() < entidadJugador->getPox() - distMax){
			entidadCamara->setPox(entidadJugador->getPox() - distMax);
		}
	}

	cam_node->setPosition(entidadCamara->getPox(), entidadCamara->getPoy(), entidadCamara->getPoz());

	cam_node->lookAt(Ogre::Vector3(entidadJugador->getPox(), entidadJugador->getPoy()+ 5, entidadJugador->getPoz()), Ogre::Node::TS_WORLD);

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

	switch (id)
	{
	case OIS::MB_Left:
		break;
	default:
		break;
	}

	return true;
}

bool CameraMove_c::mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id)
{
	switch (id)
	{
	case OIS::MB_Right:
		break;
	default:
		break;
	}
	return true;
}