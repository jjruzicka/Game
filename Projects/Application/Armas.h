#ifndef ARMAS_C_H
#define ARMAS_C_H
#include "Component.h"
#include "Entidad.h"
#include <iostream>
class Armas : public Component
{
public:
	Armas(Entidad* e, int def);
	~Armas();
	int getAtaque(){ return ataque; }
	void setAtaque(int atk){ ataque = atk; }
private:
	int ataque;
};
#endif

