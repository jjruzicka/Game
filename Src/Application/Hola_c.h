#ifndef HOLA_C_H
#define HOLA_C_H
#include "Component.h"
#include "Entidad.h"
class Hola_c : public Component
{
public:
	Hola_c(Entidad* ent);
	~Hola_c();
	void Update();
	int vida;
private:
	
	Entidad* entidad;
};

#endif