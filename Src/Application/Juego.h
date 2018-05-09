#pragma once
#include "Escenas.h"
class Juego : public Escenas
{
public:
	Juego();
	virtual ~Juego();
	virtual bool run();

private:
	//variables vienen de escenas.h
};