#include "Nice_c.h"
#include <iostream>

Nice_c::Nice_c(Entidad* ent)
{
	entidad = ent;
}


Nice_c::~Nice_c()
{
}

void Nice_c::Update(){
	std::cout << "NO ES ESTE \n";
}