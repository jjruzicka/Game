#ifndef ARMADURA_C_H
#define ARMADURA_C_H
#include "Component.h"
#include "Entidad.h"
#include <iostream>
class Armadura : public Component
{
public:
	Armadura(Entidad* e, int def);
	~Armadura();
	int getDefensa(){ return defensa; }
	void setDefensa(int def){ defensa = def; }
private:
	int defensa;
};
#endif
