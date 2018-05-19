#pragma once
#include "Component.h"
#include "Entidad.h"
#include <cstdio>
#include <ctime>
#include <iostream>
#include "Juego.h"

class DisparoTorreta_c :
	public Component
{
public:
	DisparoTorreta_c(Entidad* ent, Juego * esc);
	virtual ~DisparoTorreta_c();
	void Update();

private:
	Entidad * entidad;
	Juego * escena;
	std::clock_t start;
	double cooldown;
	bool getTime;
	int contadorProyectiles;
};

