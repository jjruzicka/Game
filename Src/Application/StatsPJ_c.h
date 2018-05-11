#pragma once
#ifndef STATSPJ_C_H
#define STATSPJ_C_H
#include "StatsEntJuego_c.h"
class StatsPJ_c : public StatsEntJuego_c
{
public:
	StatsPJ_c(int vida, int defensa, int damage, int expNivelTotal);
	~StatsPJ_c();
	void Update();
	void sumaExp(int valor){
		if (valor < 0)
			valor = -valor;
		exp += valor;
	}
private:
	int exp;
	int expNivelTotal;
	int nivel;
};

#endif