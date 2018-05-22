#include "Proyectil.h"


Proyectil::Proyectil(std::string id, Juego* esc, Ogre::SceneNode* n, btDynamicsWorld * bw,  float posGlx, float posGly, float posGlz, Ogre::Quaternion orientacion, float larg, float anch, float alt) : Entidad(id)
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

	// rotacion
	node->setOrientation(orientacion);

	largo = larg;
	ancho = anch;
	alto = alt;

	// añadmos componente fisico
	rb = new RigidBody_c(this,  bulletWorld, largo, ancho, alto, MASA);
	this->AddComponent(rb); 

	// añadimos componente del moviento
	movimiento = new MovimientoProyectil_c(this, escena, this);
	this->AddComponent(movimiento);

	// añadimos componente render
	render = new Render_c(node, this, "Sinbad", id);
	this->AddComponent(render);


}


Proyectil::~Proyectil()
{
	delete rb;
	delete movimiento;
	delete render;
}


