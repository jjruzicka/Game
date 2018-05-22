#ifndef PATRULLARNPC_H
#define PATRULLARNPC_H
#include "Component.h"
#include "Entidad.h"
#include <OgreRenderWindow.h>
#include "RigidBody_c.h"
#include "Render_c.h"
#include "Juego.h"
class PatrullarNPC : public Component
{
public:
	PatrullarNPC(int x, Entidad* ent);
	PatrullarNPC(){};
	void Update();
	~PatrullarNPC();
	void chocasCon(int i);//0 para cuando no es nada, 1 player
private:
	Entidad* entidad;
	RigidBody_c* rb;
	Ogre::SceneNode* node;
	Render_c* rc;
	int chocoCon;
	int mov;
	int contMov;
};
#endif
