#pragma once
#include "EntidadRender.h"
#include "MovimientoProyectilEnemigo_c.h"
#include <OgreRenderWindow.h>
#include "Render_c.h"
#include "RigidBody_c.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "Juego.h"
class Proyectil_Enemigo :
	public EntidadRender
{
public:
	Proyectil_Enemigo(std::string id, std::string idRender, Juego* esc, Ogre::SceneManager* n, btDynamicsWorld * bw, float posGlx, float posGly, float posGlz, float alt, float anch, float larg);
	~Proyectil_Enemigo();

private:
	Juego * escena;
	btDynamicsWorld * bulletWorld;
	Render_c * render;
	RigidBody_c * rb;
	MovimientoProyectilEnemigo_c * movimiento;
	float largo;
	float ancho;
	float alto;
	const btScalar MASA = 1; // para que vaya recto
};

