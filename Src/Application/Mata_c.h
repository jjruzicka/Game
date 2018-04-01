#ifndef MATA_C_H
#define MATA_C_H
#include "Component.h"
#include "Entidad.h"

class Mata_c : public Component
{
public:
	Mata_c(Entidad* e, Entidad* e2);
	~Mata_c();
	void Update();
private:
	Entidad* entidad;
	Entidad* entidad2;
};
#endif
