#include "Proyectil_Enemigo.h"
#include "StatsEntJuego_c.h"

Proyectil_Enemigo::Proyectil_Enemigo(std::string id, std::string idRender, Juego* esc, Ogre::SceneManager* n, btDynamicsWorld * bw, float posGlx, float posGly, float posGlz, float larg, float anch, float alt) : EntidadRender(id)
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
	//StatsEntJuego para controlar el daño al pj
	StatsEntJuego_c* st = new StatsEntJuego_c(1,0,1);
	this->AddComponent(st);
	// añadmos componente fisico
	rb = new RigidBody_c(this, bulletWorld, largo, ancho, alto, MASA);
	this->AddComponent(rb);

	// añadimos componente render
	render = new Render_c(n->getRootSceneNode()->createChildSceneNode(idRender), this, "Sinbad", idRender);
	this->AddComponent(render);

	// añadimos componente del moviento
	movimiento = new MovimientoProyectilEnemigo_c(this, escena, escena->getPlayer()->GetComponent(render)->getNode());
	this->AddComponent(movimiento);
}


Proyectil_Enemigo::~Proyectil_Enemigo()
{
	delete rb;
	delete render;
	delete movimiento;
}
