#include "Game.h"
#include "Menu.h"

EstadosManager * EstadosManager::instancia = nullptr;
MotorGrafico * MotorGrafico::instancia = nullptr;
Game::Game()
{
	estadosManager = EstadosManager::getInstancia();
	Escenas * estadoInicial = new Menu();
	estadosManager->pushEstado(estadoInicial);

	motorGrafico = MotorGrafico::getInstancia();

	exit = false;
	cont = 0;
}


Game::~Game()
{
}

void Game::run(){

	clock_t lastTicks = clock();
	clock_t elapsedTicks = 0;
	double deltaTime = 0;

	while (!motorGrafico->getWindow()->isClosed() && !exit){
		std::cout << cont << std::endl;
		deltaTime = ((double)elapsedTicks) / 1000.f/*CLOCKS_PER_SEC*/;
		lastTicks = clock();
		if (elapsedTicks >= 0.5){
			//inputcomp_->capture();
			elapsedTicks = 0;
		}

		estadosManager->topEstado()->run();

		// render ogre
		Ogre::WindowEventUtilities::messagePump();
		if (!motorGrafico->getRoot()->renderOneFrame()) exit = true;

		elapsedTicks = clock() - lastTicks;
	}
}
