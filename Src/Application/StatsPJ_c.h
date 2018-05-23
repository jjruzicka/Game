#ifndef STATSPJ_C_H
#define STATSPJ_C_H
#include "Juego.h"
#include "Component.h"
class StatsPJ_c : public Component
{
public:
	StatsPJ_c(int vida, int defensa, int damage, int expNivelTotal, Juego* escena);
	StatsPJ_c(){};
	~StatsPJ_c();
	void Update();
	void sumaExp(int valor){
		if (valor < 0)
			valor = -valor;
		exp += valor;
	}
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
	int getNivel(){
		return nivel;
	}
	int getExpRestante(){
		return expNivelTotal - exp;
	}
private:
	int exp;
	int expNivelTotal;
	int nivel;
	int vida, defensa, damage;
	int vidaMax;
	Juego* escena;
};

#endif