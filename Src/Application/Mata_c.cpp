#include "Mata_c.h"
#include <iostream>

Mata_c::Mata_c(Entidad* e, Entidad* e2)
{
	entidad = e;
	entidad2 = e2;
}


Mata_c::~Mata_c()
{
}

void Mata_c::Update(){
	std::cout << "La posición del otro es esta:" << entidad2->getPos().x << "\n";
}
