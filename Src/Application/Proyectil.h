#pragma once
#include "Entidad.h"
#include "Escenas.h"
#include "MovimientoProyectil_c.h"
#include <OgreRenderWindow.h>
#include "Render_c.h"
#include "RigidBody_c.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

class Proyectil :
	public Entidad
{
public:
	Proyectil(Ogre::SceneNode* n, btDiscreteDynamicsWorld * bw, int id, float posGlx, float posGly, float posGlz, Ogre::Quaternion orientacion, float alt, float anch, float larg);
	~Proyectil();

private:
	const int DISTACIA_MAX = 100;
	Ogre::SceneNode * node;
	btDiscreteDynamicsWorld * bulletWorld;
	Render_c * render;
	RigidBody_c * rb;
	MovimientoProyectil_c * movimiento;

	int id;
	float largo;
	float ancho;
	float alto;
	const btScalar MASA = 0; // para que vaya recto
};

