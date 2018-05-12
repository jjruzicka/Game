#pragma once
#include "Component.h"
#include <OgreRenderWindow.h>
#include "Entidad.h"
#include "Render_c.h"
#include "RigidBody_c.h"

class MovimientoProyectil_c :
	public Component
{
public:
	MovimientoProyectil_c(Entidad* ent);
	~MovimientoProyectil_c();
	void Update();

private:
	Entidad* entidad;
	Render_c * rc;
	RigidBody_c * rb;
	bool first;
	Ogre::SceneNode* node;
	Ogre::Vector3 posicionLocal;
	Ogre::Vector3 poscionGlobal;
	const int DISTACIA_MAX = 100;
	const int VELOCIDAD = 8;
};

