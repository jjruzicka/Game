#include "PatrullarNPC.h"
#include <iostream>

#include "RigidBody_c.h"
#include "Render_c.h"

PatrullarNPC::PatrullarNPC(int x, Entidad * ent, Juego* esc)
{
	this->mov = x;
	this->contMov = 0;
	entidad = ent;
	escena = esc;
	mas = false;
	chocoCon = 0;
	rb = new RigidBody_c();
	rc = new Render_c();
	node = entidad->GetComponent(rc)->getNode();
	this->escena = escena;
}

void PatrullarNPC::Update(){
	if (chocoCon != 1){
		Ogre::Vector3 cglobal(entidad->getPox(), entidad->getPoy(), entidad->getPoz());
		Ogre::Vector3 clocal = node->convertWorldToLocalPosition(cglobal);
		if (mas){
			clocal.z += 1;
			contMov++;
		}
		else if (!mas){
			clocal.z -= 1;
			contMov--;
		}
		cglobal = node->convertLocalToWorldPosition(clocal);
		entidad->GetComponent(rb)->actualizarPos(cglobal.x, cglobal.y, cglobal.z);

		if (mas && contMov >= mov)
			mas = false;
		else if (!mas && contMov <= -mov)
			mas = true;
	}
}

void PatrullarNPC::chocasCon(int i, Entidad* ent){//0 para cuando no es nada, 1 npc
	chocoCon = i;
	entColision = ent;
}

PatrullarNPC::~PatrullarNPC()
{
	delete rb;
	delete rc;
}
