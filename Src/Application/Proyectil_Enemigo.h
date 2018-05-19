#pragma once
#include "Entidad.h"
#include "MovimientoProyectilEnemigo_c.h"
#include <OgreRenderWindow.h>
#include "Render_c.h"
#include "RigidBody_c.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "Juego.h"
class Proyectil_Enemigo :
	public Entidad
{
public:
	Proyectil_Enemigo(std::string id, Juego * esc, Ogre::SceneNode* n, btDynamicsWorld * bw, float posGlx, float posGly, float posGlz, float alt, float anch, float larg);
	~Proyectil_Enemigo();

private:
	Juego * escena;
	Ogre::SceneNode * node;
	btDynamicsWorld * bulletWorld;
	Render_c * render;
	RigidBody_c * rb;
	MovimientoProyectilEnemigo_c * movimiento;
	float largo;
	float ancho;
	float alto;
	const btScalar MASA = 1; // para que vaya recto
};

