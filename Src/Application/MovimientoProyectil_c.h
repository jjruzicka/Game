#ifndef MOVIMIENTOPROYECTIL_C_H
#define MOVIMIENTOPROYECTIL_C_H
#include "Component.h"
#include <OgreRenderWindow.h>
#include "Entidad.h"
#include "Render_c.h"
#include "RigidBody_c.h"
#include <cstdio>
#include <ctime>
#include "Juego.h"

class MovimientoProyectil_c :
	public Component
{
public:
	MovimientoProyectil_c(Entidad* ent, Juego * esc);
	~MovimientoProyectil_c();
	void Update();

private:
	Entidad* entidad;
	Juego * escena;
	Render_c * rc;
	RigidBody_c * rb;
	bool first;
	Ogre::SceneNode* node;

	Ogre::Vector3 cglobal;
	Ogre::Vector3 clocal;

	std::clock_t start;
	double duration;
};
#endif

