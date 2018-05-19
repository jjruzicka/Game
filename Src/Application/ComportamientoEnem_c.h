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

class ComportamientoEnem_c : public Component
{
public:
	ComportamientoEnem_c(Entidad* ent);
	ComportamientoEnem_c(){}
	~ComportamientoEnem_c();
	void actua(Entidad* entidadHeroe);
	void Update();
private:
	Entidad* entidad;
	int chocoCon;
	Entidad* entColision;
	RigidBody_c* rb;
	Ogre::SceneNode* node;
	float calculaDistancia(Entidad* entidadHeroe);

	//reloj
	std::clock_t start;
	double cooldown;
	bool getTime;
};
#endif
