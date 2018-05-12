#include "PlayerController_c.h"
#include <iostream>
#include "RigidBody_c.h"
#include "Render_c.h"
#include "Proyectil.h"
PlayerController_c::PlayerController_c(Entidad * ent, Escenas* esc, InputComponent * input)
{
	inputcomp_ = input;
	entidad = ent;
	escena = esc;
	inputcomp_->addKeyListener(this, "teclado");
	inputcomp_->addMouseListener(this, "raton");
	auxX = auxY = auxZ = 0;
	mas = istimetoStop = false;
	contadorProyectiles = 1;

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
					  node = entidad->GetComponent(rc)->getNode();
					  mas = true;
					  istimetoStop = true;
	}
		break;

	case OIS::KC_DOWN:
	case OIS::KC_S:
	{
					  node = entidad->GetComponent(rc)->getNode();
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
	{
		std::cout << "Dispara" << std::endl;
		node = entidad->GetComponent(rc)->getNode();
		// pasamos la posicion un poco adelantada para que el proyectil no se cree dentro del personaje
		Ogre::Vector3 pGlobal(entidad->getPox(), entidad->getPoy(), entidad->getPoz());
		Ogre::Vector3 pLocal = node->convertWorldToLocalPosition(pGlobal);
		pLocal.z += 20;
		pGlobal = node->convertLocalToWorldPosition(pLocal);

		Proyectil * proyectil = new Proyectil(escena->getSceneManger()->getRootSceneNode()->createChildSceneNode("Proyectil" + std::to_string(contadorProyectiles)),
			escena->getBulletWorld(), contadorProyectiles, pGlobal.x, pGlobal.y, pGlobal.z,
			entidad->getOrientationX(), entidad->getOrientationY(), entidad->getOrientationZ(),
			5, 5, 5);
		escena->addEntidad(proyectil);
		contadorProyectiles++;
	}
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
			Ogre::Vector3 cglobal(entidad->getPox(), entidad->getPoy(), entidad->getPoz());
			Ogre::Vector3 clocal = node->convertWorldToLocalPosition(cglobal);
			if (mas){
				clocal.z += 1;
			}
			else if (!mas){
				clocal.z -= 1;
			}
			cglobal = node->convertLocalToWorldPosition(clocal);
			entidad->GetComponent(rb)->actualizarPos(cglobal.x, cglobal.y, cglobal.z);
	}
}

PlayerController_c::~PlayerController_c()
{
	inputcomp_->removeKeyListener(this);
	inputcomp_->removeMouseListener(this);

	delete rb;
	delete rc;
}