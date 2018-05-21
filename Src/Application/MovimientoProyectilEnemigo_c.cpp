#include "MovimientoProyectilEnemigo_c.h"


MovimientoProyectilEnemigo_c::MovimientoProyectilEnemigo_c(Entidad* ent, Juego * esc, Ogre::SceneNode * tn)
{
	entidad = ent;
	escena = esc;
	targetNode = tn;
	rc = new Render_c();
	rb = new RigidBody_c();
	first = true;
	duration = 0;
}


MovimientoProyectilEnemigo_c::~MovimientoProyectilEnemigo_c()
{
	delete rc;
	delete rb;
}

void MovimientoProyectilEnemigo_c::Update(){
	if (first){
		node = entidad->GetComponent(rc)->getNode();
		quat = Ogre::Vector3(0, 0, 1).getRotationTo(targetNode->getPosition() - node->getPosition());
		start = std::clock(); // get current time
	}

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	if (duration > 4){ // Segundos que pasan para que se destruya el proyectil solo
		escena->killAdd(entidad);
	}
	//setRotation(Vector3(0, 0, 1).getRotationTo(posicionBomba - posSinbadBomba))
	node->setOrientation(quat);

	cglobal = Ogre::Vector3(entidad->getPox(), entidad->getPoy(), entidad->getPoz());
	clocal = node->convertWorldToLocalPosition(cglobal);
	if (first){
		clocal.z += 20;
		first = false;
	}
	else
		clocal.z += 1;

	cglobal = node->convertLocalToWorldPosition(clocal);
	entidad->GetComponent(rb)->actualizarPos(cglobal.x, cglobal.y, cglobal.z);
}
