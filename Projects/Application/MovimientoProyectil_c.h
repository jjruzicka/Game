#pragma once
#include "Component.h"
#include <OgreRenderWindow.h>
#include "Entidad.h"
#include "Render_c.h"
#include "RigidBody_c.h"
#include <cstdio>
#include <ctime>

class MovimientoProyectil_c :
	public Component
{
public:
	MovimientoProyectil_c(Entidad* ent);
	MovimientoProyectil_c(){};
	~MovimientoProyectil_c();
	void Update();

private:
	Entidad* entidad;
	Render_c * rc;
	RigidBody_c * rb;
	bool first;
	Ogre::SceneNode* node;
	Ogre::Vector3 posicionLocal;
	Ogre::Vector3 posicionGlobal;
	const int DISTACIA_MAX = 100;
	const int VELOCIDAD = 1;

	Ogre::Vector3 cglobal;
	Ogre::Vector3 clocal;

	std::clock_t start;
	double duration;
};

