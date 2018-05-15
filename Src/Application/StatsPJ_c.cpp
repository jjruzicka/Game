#include "StatsPJ_c.h"
#include <iostream>

StatsPJ_c::StatsPJ_c(int vida, int defensa, int damage, int expNivelTotal, Juego* escena){
	this->exp = 0;
	this->nivel = 1;
	this->expNivelTotal = expNivelTotal;
	this->escena = escena;
	this->vida = vida;
	this->defensa = defensa;
	this->damage = damage;
}

void StatsPJ_c::restaVida(int valor){

	if (valor < 0)
		valor = -valor;
	vida -= valor;
	if (vida <= 0)
		muerte();
}
void StatsPJ_c::muerte(){
	escena->muerteJugador();
}

StatsPJ_c::~StatsPJ_c()
{
}
void StatsPJ_c::Update(){
	if (exp >= expNivelTotal){
		nivel++;
		if (exp > expNivelTotal)
			exp -= expNivelTotal;
		else
			exp = 0;

		expNivelTotal += 5 * nivel;

		std::cout << "Level up" << "\nNivel: " << nivel << "\nExp actual: " << exp << "\nExperiencia a conseguir : " << expNivelTotal << "\n";
	}
	std::cout << vida << "\n";
	if (vida <= 0)
		muerte();
}