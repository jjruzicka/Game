#include "Enemigo_Torreta.h"
#include "StatsEntJuego_c.h"

Enemigo_Torreta::Enemigo_Torreta(std::string id, std::string idRender, Juego * esc, Ogre::SceneManager* n, btDynamicsWorld * bw, float posGlx, float posGly, float posGlz, float alt, float anch, float larg) : EntidadRender(id)
{
	// escena del juego
	escena = esc;

	// bullet world
	bulletWorld = bw;
	this->idRender = idRender;
	// posicion global
	posicion.x = posGlx;
	posicion.y = posGly;
	posicion.z = posGlz;

	largo = larg;
	ancho = anch;
	alto = alt;
	jugador = esc->getPlayer();
	// añadimos componente fisico
	rb = new RigidBody_c(this, bulletWorld, largo, ancho, alto, MASA);
	this->AddComponent(rb);

	// añadimos componente render
	render = new Render_c(n->getRootSceneNode()->createChildSceneNode(idRender), this, "Sinbad", idRender);
	this->AddComponent(render);
	
	// añadimos las estadisticas
	StatsEntJuego_c* st = new StatsEntJuego_c(5,2,1);
	this->AddComponent(st);
	// añadimos componente disparo
	dt = new DisparoTorreta_c(this, escena,jugador);
	this->AddComponent(dt);
}


Enemigo_Torreta::~Enemigo_Torreta()
{
	delete rb;
	delete render;
	delete dt;
}
