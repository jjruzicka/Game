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
	DisparoTorreta_c(Entidad* ent, Juego * esc, Entidad * jugador);
	virtual ~DisparoTorreta_c();
	void Update();

private:
	bool areaComprueba();
	Entidad * entidad;
	Entidad * jugador;
	Juego * escena;
	std::clock_t start;
	double cooldown;
	bool getTime;
	int contadorProyectiles;
};

