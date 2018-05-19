#include "DisparoTorreta_c.h"


DisparoTorreta_c::DisparoTorreta_c(Entidad * ent)
{
	entidad = ent;
	cooldown = 0;
	getTime = true;
}


DisparoTorreta_c::~DisparoTorreta_c()
{
}

void DisparoTorreta_c::Update()
{
	if (getTime){
		start = std::clock(); // get current time
		getTime = false;
	}

	cooldown = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	if (cooldown > 4){ // Dispara
		std::cout << "Disparo enemigo" << std::endl;
		getTime = true;
	}
}
