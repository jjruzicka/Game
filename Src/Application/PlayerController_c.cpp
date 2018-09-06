#include "PlayerController_c.h"
#include <iostream>

RigidBody_c* gt;


PlayerController_c::PlayerController_c(Entidad * ent, Juego* esc, StatsPJ_c* estadisticas)
{
	inputManager = InputManager::getInstancia();
	inputManager->addKeyListener(this, "tecladoP");
	//inputcomp_ = input;
	entidad = ent;
	escena = esc;
	mas = istimetoStop = false;
	chocoCon = 0;
	gt = new RigidBody_c();
	rc = new Render_c();
	this->escena = escena;
	this->estadisticas = estadisticas;
	this->cdAtack = 50;
	contAtack = cdAtack;
	rb = entidad->GetComponent(gt);
	node = entidad->GetComponent(rc)->getNode();

	cdCuracion = 2000;
	contCura = 1000;

	cooldown = 0;
	getTime = false;

	// Animacion
	anim = new Animacion_c();
	anim = entidad->GetComponent(anim);
	anim->playAnim("IdleTop", "IdleBase");
	anim->setFoward();
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
		anim->playAnim("RunTop", "RunBase");
		anim->setFoward();
		mas = true;
		istimetoStop = true;
	}
	break;

	case OIS::KC_DOWN:
	case OIS::KC_S:
	{
		anim->playAnim("RunTop", "RunBase");
		anim->setBackwards();
		mas = false;
		istimetoStop = true;
	}
	break;

	case OIS::KC_LEFT:
	case OIS::KC_A:
		entidad->setRoy(1);
		entidad->setAngRot(3);
		break;

	case OIS::KC_RIGHT:
	case OIS::KC_D:
		entidad->setRoy(1);
		entidad->setAngRot(-3);
		break;

	case OIS::KC_PGDOWN:
	case OIS::KC_E:
		anim->playAnimTop1Time("SliceHorizontal");
		anim->setFoward();
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
	case OIS::KC_ESCAPE:
		escena->muerteJugador();
		break;
	case OIS::KC_UP:
	case OIS::KC_W:
		anim->playAnim("IdleTop", "IdleBase");
		anim->setFoward();
		istimetoStop = false;
		break;
	case OIS::KC_DOWN:
	case OIS::KC_S:
		anim->playAnim("IdleTop", "IdleBase");
		anim->setFoward();
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
		anim->playAnim("IdleTop", "IdleBase");
		anim->setFoward();
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
		if (contCura >= cdCuracion){
			contCura = 0;
			estadisticas->Curacion(estadisticas->getVidaMax() / 3);
		}
		istimetoStop = false;
		break;
	default:
		break;
	}

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

	if (getTime){
		start = std::clock();
		getTime = false;
	}

	cooldown = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	if (cooldown > 1){
		getTime = true;
		chocoCon = 0;
	}
	
	contCura++;
	contAtack++;
}

void PlayerController_c::chocasCon(int i, Entidad* ent){//0 para cuando no es nada, 1 npc
	chocoCon = i;
	entColision = ent;
	getTime = true;
}

PlayerController_c::~PlayerController_c()
{
	inputManager->removeKeyListener(this);

}
