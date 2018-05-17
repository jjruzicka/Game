#include "MovimientoEnemigo_c.h"


MovimientoEnemigo_c::MovimientoEnemigo_c(Entidad* ent)
{
	chocoCon = 0;
	entidad = ent;
	rb = new RigidBody_c();
}


MovimientoEnemigo_c::~MovimientoEnemigo_c()
{
}

void MovimientoEnemigo_c::chocasCon(int i, Entidad* ent){//0 para cuando no es nada, 1 npc
	chocoCon = i;
	entColision = ent;
}

void MovimientoEnemigo_c::Update(){
	entidad->GetComponent(rb)->actualizarPos(entidad->getPox(), entidad->getPoy(), entidad->getPoz());
}