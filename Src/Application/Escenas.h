#pragma once
#include <vector>
#include "Entidad.h"
class Escenas
{
public:
	Escenas();
	~Escenas();
private:
	std::vector<Entidad*> entidades;
};

