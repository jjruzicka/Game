#pragma once
#include "Component.h"
#include "Entidad.h"
#include <OgreRenderWindow.h>
#include "RigidBody_c.h"
#include "Render_c.h"
#include "Juego.h"
class PatrullarNPC : public Component
{
public:
	PatrullarNPC(int x, Entidad* ent, Juego* escena);
	PatrullarNPC(){};
	void Update();
	~PatrullarNPC();
	void chocasCon(int i, Entidad* ent);//0 para cuando no es nada, 1 npc
private:
	Entidad* entidad;
	bool mas;
	RigidBody_c* rb;
	Render_c * rc;
	Juego* escena;
	Ogre::SceneNode* node;
	int contadorProyectiles;
	int chocoCon;
	int mov;
	int contMov;
	Entidad* entColision;
};

