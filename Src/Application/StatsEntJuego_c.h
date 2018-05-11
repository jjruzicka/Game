#pragma once
#ifndef STATSENTJUEGO_C_H
#define STATSENTJUEGO_C_H
#include "Component.h"
#include <iostream>
#include "Escenas.h"
class StatsEntJuego_c : public Component
{
public:
	StatsEntJuego_c(int vida, int defensa, int damage, Escenas* escena, Entidad* ent);
	StatsEntJuego_c(int vida, int defensa, int damage);
	StatsEntJuego_c(){};
	~StatsEntJuego_c();
	void Update(){};
	void muerte();
	void restaVida(int valor);
	int getVida(){
		return vida;
	}
	int getDefensa(){
		return defensa;
	}
	int getDamage(){
		return damage;
	}
protected:
	Escenas* escena;
	Entidad* ent;
	int vida;
	int defensa;
	int damage;
};

#endif