#include "Hola_c.h"
#include <iostream>

Hola_c::Hola_c(Entidad* ent)
{
	entidad = ent;
	vida = 0;
}


Hola_c::~Hola_c()
{

}

void Hola_c::Update(){
	vida++;
	std::cout << "Mi vida es "<< vida << "\n";
}