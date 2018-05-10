#include "MovimientoProyectil_c.h"


MovimientoProyectil_c::MovimientoProyectil_c(Entidad* ent, Ogre::Vector3 pl)
{
	entidad = ent;
	posicionLocal = pl;
	rc = new Render_c();
	rb = new RigidBody_c();
	first = true;
}


MovimientoProyectil_c::~MovimientoProyectil_c()
{
}

void MovimientoProyectil_c::Update(){
	if (first){
		node = entidad->GetComponent(rc)->getNode();
		first = false;
	}

	posicionLocal.z += VELOCIDAD;
	poscionGlobal = node->convertLocalToWorldPosition(posicionLocal);
	entidad->GetComponent(rb)->actualizarPos(poscionGlobal.x, poscionGlobal.y, poscionGlobal.z);
}