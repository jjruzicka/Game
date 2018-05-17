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
}

void MovimientoProyectilEnemigo_c::Update(){
	//setRotation(Vector3(0, 0, 1).getRotationTo(posicionBomba - posSinbadBomba))
}
