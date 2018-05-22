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
	MovimientoProyectil_c(Entidad* ent, Juego * esc, Entidad * ori);
	MovimientoProyectil_c(){};
	~MovimientoProyectil_c();
	void Update();
	void activate(bool b){
		active = b;
	}
	void Reset();
private:
	Entidad* entidad;
	Juego * escena;
	Entidad * origin;
	Render_c * rc;
	RigidBody_c * rb;
	bool first;
	Ogre::SceneNode* node;

	Ogre::Vector3 cglobal;
	Ogre::Vector3 clocal;

	std::clock_t start;
	double duration;

	bool active;
};
#endif

