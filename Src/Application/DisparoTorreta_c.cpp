#include "DisparoTorreta_c.h"
#include "Proyectil_Enemigo.h"
DisparoTorreta_c::DisparoTorreta_c(Entidad * ent, Juego * esc)
{

	entidad = ent;
	escena = esc;

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

	if (cooldown > 4){ // Segundos que tarda en disparar 
		std::cout << "Disparo enemigo" << std::endl;
		//Ogre::SceneNode * node;
		btDynamicsWorld * bulletWorld = escena->getBulletWorld();
		Proyectil_Enemigo * proyectilEnemigo = new Proyectil_Enemigo("proyectilEnemigo" + std::to_string(contadorProyectiles), escena,
			escena->getSceneManger()->getRootSceneNode()->createChildSceneNode("ProyectilEnemigo" + std::to_string(contadorProyectiles)),
			escena->getBulletWorld(), entidad->getPox() , entidad->getPoy(), entidad->getPoz(), 5, 5, 5);
		escena->addEntidad(proyectilEnemigo);
		contadorProyectiles++;
		getTime = true;
	}
}
