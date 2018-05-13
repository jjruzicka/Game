#include "Proyectil.h"


Proyectil::Proyectil(Ogre::SceneNode* n, btDiscreteDynamicsWorld * bw, int _id, float posGlx, float posGly, float posGlz, Ogre::Quaternion orientacion, float larg, float anch, float alt) : Entidad()
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

	// rotacion
	node->setOrientation(orientacion);

	std::cout << "bala: " << orientacion.x << orientacion.y << orientacion.z << std::endl;
	largo = larg;
	ancho = anch;
	alto = alt;

	// añadmos componente fisico
	rb = new RigidBody_c(this, physicType::kinematico, bulletWorld, largo, ancho, alto, MASA);
	this->AddComponent(rb); 

	// añadimos componente del moviento
	//Ogre::Vector3 pLocal(posicionLocal.x, posicionLocal.y, posicionLocal.z);
	movimiento = new MovimientoProyectil_c(this);
	this->AddComponent(movimiento);

	// añadimos componente render
	render = new Render_c(node, this, "Sinbad", "Proyectil" + std::to_string(id));
	this->AddComponent(render);


}


Proyectil::~Proyectil()
{
}


