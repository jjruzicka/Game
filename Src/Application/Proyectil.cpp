#include "Proyectil.h"


Proyectil::Proyectil(std::string id, Juego* esc, Ogre::SceneNode* n, btDiscreteDynamicsWorld * bw, int bId, float posGlx, float posGly, float posGlz, Ogre::Quaternion orientacion, float larg, float anch, float alt) : Entidad(id)
{	
	// escena del juego
	escena = esc;

	// nodo de ogre
	node = n;

	// id unico de la bala
	bulletId = bId;

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
	movimiento = new MovimientoProyectil_c(this, escena);
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


