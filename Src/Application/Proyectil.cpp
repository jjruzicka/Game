#include "Proyectil.h"


Proyectil::Proyectil(std::string id, std::string idRender, Juego* esc, Ogre::SceneNode* n, btDynamicsWorld * bw, float posGlx, float posGly, float posGlz, Ogre::Quaternion orientacion, float larg, float anch, float alt) : EntidadRender(id)
{
	// escena del juego
	escena = esc;

	// nodo de ogre
	node = n;
	this->idRender = idRender;
	// bullet world
	bulletWorld = bw;

	// posicion global
	posicion.x = posGlx;
	posicion.y = posGly;
	posicion.z = posGlz;


	// rotacion
	node->setOrientation(orientacion);

	largo = larg;
	ancho = anch;
	alto = alt;

	// añadmos componente fisico
	rb = new RigidBody_c(this,  bulletWorld, largo, ancho, alto, MASA);
	this->AddComponent(rb); 

	// añadimos componente del moviento
	movimiento = new MovimientoProyectil_c(this, escena);
	this->AddComponent(movimiento);

	// añadimos componente render
	render = new Render_c(node, this, "Sinbad", idRender);
	this->AddComponent(render);
}


Proyectil::~Proyectil()
{
	delete rb;
	delete movimiento;
	delete render;
}


