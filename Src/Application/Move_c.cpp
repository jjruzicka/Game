#include "Move_c.h"
#include <iostream>

Move_c::Move_c(Entidad* e)
{
	entidad = e;
}


Move_c::~Move_c()
{
}

void Move_c::Update(){
	Pos aux;
	entidad->setPos(entidad->getPos().x + 1, entidad->getPos().y,entidad->getPos().z);
	std::cout << entidad->getPos().x << "\n";
}