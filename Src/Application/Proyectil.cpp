#include "Proyectil.h"


Proyectil::Proyectil(float posGlx, float posGly, float posGlz, float posLox, float posLoy, float posLoz, float oriX, float oriY, float oriZ) : Entidad()
{
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
}


Proyectil::~Proyectil()
{
}


