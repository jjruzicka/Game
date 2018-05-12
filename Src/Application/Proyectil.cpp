#include "Proyectil.h"


Proyectil::Proyectil(Ogre::SceneNode* n, btDiscreteDynamicsWorld * bw, int _id, float posGlx, float posGly, float posGlz, float posLox, float posLoy, float posLoz, float oriX, float oriY, float oriZ, float larg, float anch, float alt) : Entidad()
{	
	// nodo de ogre
	node = n;

	// id unico de la bala
	id = _id;

	// bullet world
	bulletWorld = bw;

	// posicion global
	posicion.x = posGlx;
	posicion.y = posGly;
	posicion.z = posGlz;

	// posicion local
	posicionLocal.x = posLox;
	posicionLocal.y = posLoy;
	posicionLocal.z = posLoz;

	// orientacion
	orientacion.x = oriX;
	orientacion.y = oriY;
	orientacion.z = oriZ;

	largo = larg;
	ancho = anch;
	alto = alt;

	// añadimos componente render
	render = new Render_c(node, this, "Sinbad", "Proyectil" + std::to_string(id));
	this->AddComponent(render);
	// añadmos componente fisico
	rb = new RigidBody_c(this, physicType::kinematico, bulletWorld, largo, ancho, alto, MASA);
	this->AddComponent(rb); 
	// añadimos componente del moviento
	Ogre::Vector3 pLocal(posicionLocal.x, posicionLocal.y, posicionLocal.z);
	movimiento = new MovimientoProyectil_c(this, pLocal);
	this->AddComponent(movimiento);


}


Proyectil::~Proyectil()
{
}


