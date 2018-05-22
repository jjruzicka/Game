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
	MovimientoProyectilEnemigo_c(Entidad* ent, Entidad * ori, Juego * esc);
	MovimientoProyectilEnemigo_c(){};
	~MovimientoProyectilEnemigo_c();
	void Update();
	void Reset();
private:
	Entidad* entidad;
	Entidad* origin;
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
	Ogre::Quaternion quat;
};

