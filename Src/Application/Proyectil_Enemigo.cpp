#include "Proyectil_Enemigo.h"


Proyectil_Enemigo::Proyectil_Enemigo(std::string id, Juego* esc, Ogre::SceneNode* n, btDynamicsWorld * bw, float posGlx, float posGly, float posGlz, float larg, float anch, float alt) : Entidad(id)
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

	// añadmos componente fisico
	rb = new RigidBody_c(this, bulletWorld, largo, ancho, alto, MASA);
	this->AddComponent(rb);

	// añadimos componente render
	render = new Render_c(node, this, "Sinbad", id);
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
