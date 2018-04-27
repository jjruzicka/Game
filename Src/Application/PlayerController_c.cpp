#include "PlayerController_c.h"
#include <iostream>
#include "RigidBody_c.h"
#include "Render_c.h"
PlayerController_c::PlayerController_c(Entidad * ent, InputComponent * input)
{
	inputcomp_ = input;
	entidad = ent;
	inputcomp_->addKeyListener(this, "teclado");
	inputcomp_->addMouseListener(this, "raton");
	auxX = auxY = auxZ = 0;
	mas = istimetoStop = false;

	rb = new RigidBody_c();
	rc = new Render_c();
}

bool PlayerController_c::keyPressed(const OIS::KeyEvent& keyP)
{

	switch (keyP.key)
	{
	case OIS::KC_ESCAPE:
		break;

	case OIS::KC_1:
		break;

	case OIS::KC_2:
		break;

	case OIS::KC_UP:
	case OIS::KC_W:
	{
					  auxZ = entidad->getPoz();
					  auxZ += entidad->getOrientationZ();
					  //entidad->setPoz(entidad->getPoz() + 10);
					  Ogre::Vector3 cglobal(entidad->getPox(), entidad->getPoy(), entidad->getPoz());
					  node = entidad->GetComponent(rc)->getNode();
					  Ogre::Vector3 clocal = node->convertWorldToLocalPosition(cglobal);
					  clocal.z += 10;
					  cglobal = node->convertLocalToWorldPosition(clocal);
					  //entidad->GetComponent(rb)->actualizarPos(entidad->getPox(), entidad->getPoy(), entidad->getPoz() + 10);
					  entidad->GetComponent(rb)->actualizarPos(cglobal.x, cglobal.y, cglobal.z);
					  auxX = entidad->getPox();
					  auxX += entidad->getOrientationX();
					  entidad->setPox(auxX);
					  mas = true;
					  istimetoStop = true;
	}
		break;

	case OIS::KC_DOWN:
	case OIS::KC_S:
	{
					  auxZ = entidad->getPoz();
					  auxZ -= entidad->getOrientationZ();
					  //entidad->setPoz(entidad->getPoz() - 10);
					  Ogre::Vector3 cglobal(entidad->getPox(), entidad->getPoy(), entidad->getPoz());
					  node = entidad->GetComponent(rc)->getNode();
					  Ogre::Vector3 clocal = node->convertWorldToLocalPosition(cglobal);
					  clocal.z -= 10;
					  cglobal = node->convertLocalToWorldPosition(clocal);
					  entidad->GetComponent(rb)->actualizarPos(cglobal.x, cglobal.y, cglobal.z);
					  //entidad->GetComponent(rb)->actualizarPos(entidad->getPox(), entidad->getPoy(), entidad->getPoz() - 10);
					  auxX = entidad->getPox();
					  auxX -= entidad->getOrientationX();
					  entidad->setPox(auxX);
					  mas = false;
					  istimetoStop = true;
	}
		break;

	case OIS::KC_LEFT:
	case OIS::KC_A:
		entidad->setRoy(1);
		entidad->setAngRot(1);
		break;

	case OIS::KC_RIGHT:
	case OIS::KC_D:
		entidad->setRoy(1);
		entidad->setAngRot(-1);
		break;

	case OIS::KC_PGDOWN:
	case OIS::KC_E:
		break;

	case OIS::KC_PGUP:
	case OIS::KC_Q:
		break;

	default:
		break;
	}

	return true;
}



bool PlayerController_c::keyReleased(const OIS::KeyEvent& keyP){
	switch (keyP.key)
	{
	case OIS::KC_UP:
	case OIS::KC_W:
		auxZ = 0;
		istimetoStop = false;
		break;

	case OIS::KC_DOWN:
	case OIS::KC_S:
		auxZ = 0;
		istimetoStop = false;
		break;

	case OIS::KC_LEFT:
	case OIS::KC_A:
		entidad->setRoy(0);
		break;

	case OIS::KC_RIGHT:
	case OIS::KC_D:
		entidad->setRoy(0);
		break;

	case OIS::KC_PGDOWN:
	case OIS::KC_E:
		auxX = 0;
		istimetoStop = false;
		break;

	case OIS::KC_PGUP:
	case OIS::KC_Q:
		auxX = 0;
		istimetoStop = false;
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

	}

	return true;
}

bool PlayerController_c::mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id)
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

bool PlayerController_c::mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id)
{
	return true;
}


void PlayerController_c::Update(){

	if (istimetoStop){
		if (mas){
			if (auxZ != 0){
				auxZ = entidad->getPoz();
				auxZ += 10 * entidad->getOrientationZ();
				entidad->setPoz(auxZ);
			}
			else{
				auxX = entidad->getPox();
				auxX += 10 * entidad->getOrientationX();
				entidad->setPox(auxX);
			}
		}
		else if (!mas){
			if (auxZ != 0){
				auxZ = entidad->getPoz();
				auxZ -= 10 * entidad->getOrientationZ();
				entidad->setPoz(auxZ);
			}
			else{
				auxX = entidad->getPox();
				auxX -= 10 * entidad->getOrientationX();
				entidad->setPox(auxX);
			}
		}
	}
}

PlayerController_c::~PlayerController_c()
{
	inputcomp_->removeKeyListener(this);
	inputcomp_->removeMouseListener(this);

	delete rb;
	delete rc;
}