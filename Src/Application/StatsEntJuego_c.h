#pragma once
#ifndef STATSENTJUEGO_C_H
#define STATSENTJUEGO_C_H
#include "Component.h"
class StatsEntJuego_c : public Component
{
public:
	StatsEntJuego_c(int vida, int defensa, int damage);
	~StatsEntJuego_c();
	void Update(){};
	void restaVida(int valor){
		if (valor < 0)
			valor = -valor;
		vida -= valor;
	}
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
	int vida;
	int defensa;
	int damage;
};

#endif