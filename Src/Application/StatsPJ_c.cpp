#include "StatsPJ_c.h"
#include <iostream>

StatsPJ_c::StatsPJ_c(int vida, int defensa, int damage, int expNivelTotal) : StatsEntJuego_c(vida, defensa, damage)
{
	this->exp = 0;
	this->nivel = 1;
	this->expNivelTotal = expNivelTotal;
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
}