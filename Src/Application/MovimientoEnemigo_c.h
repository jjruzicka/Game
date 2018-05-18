#pragma once
#ifndef MOVIMIENTO_ENEMIGO_C_H
#define MOVIMIENTO_ENEMIGO_C_H
#include "Entidad.h"
#include "RigidBody_c.h"
#include <OgreRenderWindow.h>
#include "Render_c.h"

class MovimientoEnemigo_c : public Component
{
public:
	MovimientoEnemigo_c(Entidad* ent);
	MovimientoEnemigo_c(){}
	~MovimientoEnemigo_c();
	//void chocasCon(int i, Entidad* ent);//0 para cuando no es nada, 1 npc
	void mueve(Entidad* entidadHeroe);
	void Update();
private:
	Entidad* entidad;
	int chocoCon;
	Entidad* entColision;
	RigidBody_c* rb;
	Ogre::SceneNode* node;
};
#endif
