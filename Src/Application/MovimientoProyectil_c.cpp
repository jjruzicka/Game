#include "MovimientoProyectil_c.h"
#include <iostream>

MovimientoProyectil_c::MovimientoProyectil_c(Entidad* ent, Juego * esc, Entidad * ori)
{
	escena = esc;
	entidad = ent;
	origin = ori;
	rc = new Render_c();
	rb = new RigidBody_c();
	first = true;
	duration = 0;
	active = false;
}


MovimientoProyectil_c::~MovimientoProyectil_c()
{
	delete rc;
	delete rb;
}

void MovimientoProyectil_c::Update(){
	if (active){
		if (first){
			std::cout << "entra" << std::endl;
			entidad->setPox(escena->getPlayer()->getPox());
			entidad->setPoy(escena->getPlayer()->getPoy());
			entidad->setPoz(escena->getPlayer()->getPoz());
			node = entidad->GetComponent(rc)->getNode();
			node->setOrientation(escena->getPlayer()->GetComponent(rc)->getNode()->getOrientation());
			start = std::clock(); // get current time
		}
		std::cout << first << std::endl;

		cglobal = Ogre::Vector3(entidad->getPox(), entidad->getPoy(), entidad->getPoz());
		clocal = node->convertWorldToLocalPosition(cglobal);
		if (first){
			clocal.z += 20;
			first = false;
		}
		else
			clocal.z += 3;
		std::cout << cglobal.x << " " << cglobal.y << " " << cglobal.z << std::endl;
		cglobal = node->convertLocalToWorldPosition(clocal);
		entidad->GetComponent(rb)->actualizarPos(cglobal.x, cglobal.y, cglobal.z);
		
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		if (duration > 2){ // number of seconds it take to destroy the proyectile
			Reset();
		}
	}
}

void MovimientoProyectil_c::Reset(){
	entidad->setPox(15000);
	entidad->setPoy(5);
	entidad->setPoz(15000);
	entidad->GetComponent(rb)->actualizarPos(15000, 5, 15000);
	active = false;
	first = true;
	duration = 0;
}
