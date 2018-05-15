#include "MovimientoProyectil_c.h"


MovimientoProyectil_c::MovimientoProyectil_c(Entidad* ent, Juego * esc)
{
	escena = esc;
	entidad = ent;
	rc = new Render_c();
	rb = new RigidBody_c();
	first = true;
	duration = 0;
}


MovimientoProyectil_c::~MovimientoProyectil_c()
{
	delete rc;
	delete rb;
}

void MovimientoProyectil_c::Update(){
	if (first){
		node = entidad->GetComponent(rc)->getNode();
		start = std::clock(); // get current time
	}
	
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	if (duration > 3){ // number of seconds it take to destroy the proyectile
		std::cout << "Proyectile destroyed";
		escena->killAdd(entidad);
	}
	cglobal = Ogre::Vector3(entidad->getPox(), entidad->getPoy(), entidad->getPoz());
	clocal = node->convertWorldToLocalPosition(cglobal);
	if (first){
		clocal.z += 20;
		first = false;
	}
	else 
		clocal.z += 3;

	cglobal = node->convertLocalToWorldPosition(clocal);
	entidad->GetComponent(rb)->actualizarPos(cglobal.x, cglobal.y, cglobal.z);
}