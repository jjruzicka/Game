#pragma once
#include "EntidadRender.h"
#include "Juego.h"
#include <OgreRenderWindow.h>
#include "Render_c.h"
#include "RigidBody_c.h"
#include "DisparoTorreta_c.h"
class Enemigo_Torreta :
	public EntidadRender
{
public:
	Enemigo_Torreta(std::string id, std::string idRender, Juego * esc, Ogre::SceneManager* n, btDynamicsWorld * bw, float posGlx, float posGly, float posGlz, float alt, float anch, float larg);
	~Enemigo_Torreta();

private:
	Juego * escena;
	Entidad* jugador;
	btDynamicsWorld * bulletWorld;
	RigidBody_c * rb;
	Render_c * render;
	DisparoTorreta_c * dt;
	float largo;
	float ancho;
	float alto;
	const btScalar MASA = 1;
};

