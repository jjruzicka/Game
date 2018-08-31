#pragma once
#ifndef MOVIMIENTO_ENEMIGO_C_H
#define MOVIMIENTO_ENEMIGO_C_H
#include "Entidad.h"
#include "RigidBody_c.h"
#include <OgreRenderWindow.h>
#include "Render_c.h"
#include <cstdio>
#include <ctime>
#include <iostream>
#include "Animacion_c.h"


class ComportamientoEnem_c : public Component
{
public:
	ComportamientoEnem_c(Entidad* ent);
	ComportamientoEnem_c(){}
	~ComportamientoEnem_c();
	void actua(Entidad* entidadHeroe);
	void Update();
	void setTrigger(Entidad* trigger){
		entTrigger = trigger;
	}
	Entidad* getTrigger(){
		return entTrigger;
	}

private:
	Entidad* entidad;
	Entidad* entTrigger;
	int chocoCon;
	Entidad* entColision;
	RigidBody_c* rb;
	Ogre::SceneNode* node;
	float calculaDistancia(Entidad* entidadHeroe);
	Animacion_c * anim;
	bool actuando;

	//reloj
	std::clock_t start;
	double cooldown;
	bool getTime;
};
#endif
