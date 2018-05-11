#include "StatsEntJuego_c.h"


StatsEntJuego_c::StatsEntJuego_c(int vida, int defensa, int damage, Escenas* escena, Entidad* ent) : StatsEntJuego_c(vida, defensa,damage)
{
	this->ent = ent;
	this->escena = escena;
}
void StatsEntJuego_c::muerte(){
	escena->killAdd(ent);
}
StatsEntJuego_c::StatsEntJuego_c(int vida, int defensa, int damage){
	this->vida = vida + defensa/2;
	this->damage = damage;
	this->defensa = defensa;
}
void StatsEntJuego_c::restaVida(int valor){

	if (valor < 0)
		valor = -valor;
	vida -= valor;
	if (vida <= 0)
		muerte();
}
StatsEntJuego_c::~StatsEntJuego_c()
{
}
