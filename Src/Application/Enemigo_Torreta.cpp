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

	// añadimos componente fisico
	rb = new RigidBody_c(this, bulletWorld, largo, ancho, alto, MASA);
	this->AddComponent(rb);

	// añadimos componente render
	render = new Render_c(node, this, "Sinbad", id);
	this->AddComponent(render);
	
	// añadimos componente disparo
	dp = new DisparoTorreta_c(this);
	this->AddComponent(dp);
}


Enemigo_Torreta::~Enemigo_Torreta()
{
}
