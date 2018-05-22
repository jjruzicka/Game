#include "PlayerController_c.h"
#include <iostream>
#include "Proyectil.h"
#include "AniManager_c.h"

RigidBody_c* gt;


PlayerController_c::PlayerController_c(Entidad * ent, InputComponent * input, Juego* esc, StatsPJ_c* estadisticas)
{
	inputcomp_ = input;
	entidad = ent;
	escena = esc;
	inputcomp_->addKeyListener(this, "teclado");
	inputcomp_->addMouseListener(this, "raton");
	mas = istimetoStop = false;
	contadorProyectiles = 1;
	chocoCon = 0;
	gt = new RigidBody_c();
	rc = new Render_c();
	this->escena = escena;
	this->estadisticas = estadisticas;
	this->cdAtack = 50;
	contAtack = cdAtack;
	rb = entidad->GetComponent(gt);
	node = entidad->GetComponent(rc)->getNode();
	this->cdDisparo = 80;
	contDisparo = cdDisparo;
}

bool PlayerController_c::keyPressed(const OIS::KeyEvent& keyP)
{
	AniManager_c* anim = new AniManager_c();
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
		mas = true;
		istimetoStop = true;
		entidad->GetComponent(anim)->playAnim();
	}
	break;

	case OIS::KC_DOWN:
	case OIS::KC_S:
	{
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
	AniManager_c* anim = new AniManager_c();
	switch (keyP.key)
	{
	case OIS::KC_UP:
	case OIS::KC_W:
		istimetoStop = false;
		entidad->GetComponent(anim)->stopAnim();
		break;
	case OIS::KC_DOWN:
	case OIS::KC_S:
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
		if (chocoCon != 0){
			if (chocoCon == 1 && entColision != nullptr){//eres un npc y me das las misiones
				escena->activaMision(entColision);
			}
			else if (chocoCon == 2 && entColision != nullptr){
				if (contAtack >= cdAtack){
					contAtack = 0;
					escena->atacar(entColision);
					entColision = nullptr;
				}
			}
			else if (chocoCon == 3 && entColision != nullptr){
				escena->killAdd(entColision);
				entColision = nullptr;
			}
		}
		istimetoStop = false;
		break;

	case OIS::KC_PGUP:
	case OIS::KC_Q:
		estadisticas->restaVida(1);
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
		if (contDisparo >= cdDisparo){
			contDisparo = 0;
			// pasamos la posicion un poco adelantada para que el proyectil no se cree dentro del personaje
			Ogre::Vector3 pGlobal(entidad->getPox(), entidad->getPoy(), entidad->getPoz());
			Ogre::Vector3 pLocal = node->convertWorldToLocalPosition(pGlobal);
			pLocal.z += 20;
			pGlobal = node->convertLocalToWorldPosition(pLocal);
			Proyectil * proyectil = new Proyectil("proyectilPlayer", "proyectilPlayer" + std::to_string(contadorProyectiles), escena,
				escena->getSceneManger()->getRootSceneNode()->createChildSceneNode("Proyectil" + std::to_string(contadorProyectiles)),
				escena->getBulletWorld(), pGlobal.x, pGlobal.y, pGlobal.z,
				node->getOrientation(), 5, 5, 5);
			escena->addEntidad(proyectil);
			contadorProyectiles++;
		}
		break;
	}
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
		rb->actualizarPos(cglobal.x, cglobal.y, cglobal.z);
	}
	contAtack++;
	contDisparo++;
}

void PlayerController_c::chocasCon(int i, Entidad* ent){//0 para cuando no es nada, 1 npc
	chocoCon = i;
	entColision = ent;
}

PlayerController_c::~PlayerController_c()
{
	inputcomp_->removeKeyListener(this);
	inputcomp_->removeMouseListener(this);

	delete rb;
}
