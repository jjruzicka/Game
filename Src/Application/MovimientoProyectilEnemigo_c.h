#pragma once
#include "Component.h"
#include <OgreRenderWindow.h>
#include "Entidad.h"
#include "Render_c.h"
#include "RigidBody_c.h"
#include <cstdio>
#include <ctime>
#include "Juego.h"
class MovimientoProyectilEnemigo_c :
	public Component
{
public:
	MovimientoProyectilEnemigo_c(Entidad* ent, Juego * esc, Ogre::SceneNode * tn);
	~MovimientoProyectilEnemigo_c();
	void Update();
private:
	Entidad* entidad;
	Juego * escena;
	Render_c * rc;
	RigidBody_c * rb;
	bool first;
	Ogre::SceneNode* node;
	Ogre::SceneNode* targetNode;
	Ogre::Vector3 cglobal;
	Ogre::Vector3 clocal;

	std::clock_t start;
	double duration;
};
