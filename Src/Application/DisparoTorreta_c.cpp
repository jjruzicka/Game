#include "DisparoTorreta_c.h"
#include "Proyectil_Enemigo.h"
DisparoTorreta_c::DisparoTorreta_c(Entidad * ent, Juego * esc, Entidad * jugador)
{

	entidad = ent;
	escena = esc;
	this->jugador = jugador;
	cooldown = 0;
	getTime = true;
	contadorProyectiles = 1;
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

	if (cooldown > 4 && areaComprueba()){ // Segundos que tarda en disparar 
		btDynamicsWorld * bulletWorld = escena->getBulletWorld();
		Entidad* proyectilEnemigo = new Proyectil_Enemigo("proyectilEnemigo", "proyectilEnemigo" + std::to_string(contadorProyectiles), escena,
			escena->getSceneManger(),
			escena->getBulletWorld(), entidad->getPox() , entidad->getPoy(), entidad->getPoz(), 5, 5, 5);
		escena->addEntidad(proyectilEnemigo);
		contadorProyectiles++;
		getTime = true;
	}
}
bool DisparoTorreta_c::areaComprueba(){
	
	if (entidad->getPox() - jugador->getPox() < 150 && entidad->getPox() - jugador->getPox() > -150 && entidad->getPoz() - jugador->getPoz() < 150 && entidad->getPoz() - jugador->getPoz() > -150){
		return true;
	}
	else
		return false;
}

