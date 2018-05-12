#include "MovimientoProyectil_c.h"


MovimientoProyectil_c::MovimientoProyectil_c(Entidad* ent)
{
	entidad = ent;
	rc = new Render_c();
	rb = new RigidBody_c();
	first = true;
}


MovimientoProyectil_c::~MovimientoProyectil_c()
{
}

void MovimientoProyectil_c::Update(){
	if (first)
		node = entidad->GetComponent(rc)->getNode();
	
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