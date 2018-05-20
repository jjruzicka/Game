#include "Enemigo_Torreta.h"


Enemigo_Torreta::Enemigo_Torreta(std::string id, Juego * esc, Ogre::SceneNode* n, btDynamicsWorld * bw , float posGlx, float posGly, float posGlz, float alt, float anch, float larg) : Entidad(id)
{
	// escena del juego
	escena = esc;

	// nodo de ogre
	node = n;

	// bullet world
	bulletWorld = bw;

	// posicion global
	posicion.x = posGlx;
	posicion.y = posGly;
	posicion.z = posGlz;

	largo = larg;
	ancho = anch;
	alto = alt;

	// a�adimos componente fisico
	rb = new RigidBody_c(this, bulletWorld, largo, ancho, alto, MASA);
	this->AddComponent(rb);

	// a�adimos componente render
	render = new Render_c(node, this, "Sinbad", id);
	this->AddComponent(render);
	
	// a�adimos componente disparo
	dt = new DisparoTorreta_c(this, escena);
	this->AddComponent(dt);
}


Enemigo_Torreta::~Enemigo_Torreta()
{
	delete rb;
	delete render;
	delete dt;
}