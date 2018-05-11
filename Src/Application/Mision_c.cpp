#include "Mision_c.h"


Mision_c::Mision_c(int total, std::string target,int exp, Entidad* ent)
{
	this->total = total;
	cont = 0;
	this->target = target;
	this->ent = ent;
	this->exp = exp;
}


Mision_c::~Mision_c()
{
}
