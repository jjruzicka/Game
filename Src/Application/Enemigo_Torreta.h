#pragma once
#include "Entidad.h"
#include "Juego.h"
#include <OgreRenderWindow.h>
#include "Render_c.h"
#include "RigidBody_c.h"
#include "DisparoTorreta_c.h"
class Enemigo_Torreta :
	public Entidad
{
public:
	Enemigo_Torreta(std::string id, Juego * esc, Ogre::SceneNode* n, btDynamicsWorld * bw, float posGlx, float posGly, float posGlz, float alt, float anch, float larg);
	~Enemigo_Torreta();

private:
	Juego * escena;
	Ogre::SceneNode * node;
	btDynamicsWorld * bulletWorld;
	RigidBody_c * rb;
	Render_c * render;
	DisparoTorreta_c * dp;
	float largo;
	float ancho;
	float alto;
	const btScalar MASA = 1;
};

