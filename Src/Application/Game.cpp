#include "Game.h"
#include "Menu.h"
#include "Juego.h"
EstadosManager * EstadosManager::instancia = nullptr;
MotorGrafico * MotorGrafico::instancia = nullptr;
MotorFisico * MotorFisico::instancia = nullptr;
InputManager * InputManager::instancia = nullptr;
Game::Game()
{
	estadosManager = EstadosManager::getInstancia();
	Escenas * estadoInicial = new Menu();
	estadosManager->pushEstado(estadoInicial);

	motorGrafico = MotorGrafico::getInstancia();
	motorFisico = MotorFisico::getInstancia();

	inputManager = InputManager::getInstancia();

	exit = false;
}


Game::~Game()
{
}

void Game::run(){

	clock_t lastTicks = clock();
	clock_t elapsedTicks = 0;
	double deltaTime = 0;

	while (!motorGrafico->getWindow()->isClosed() && !exit){
		deltaTime = ((double)elapsedTicks) / 1000.f/*CLOCKS_PER_SEC*/;
		lastTicks = clock();
		if (elapsedTicks >= 0.5){
			inputManager->capture();
			elapsedTicks = 0;
		}

		estadosManager->topEstado()->run();

		// render ogre
		Ogre::WindowEventUtilities::messagePump();
		if (!motorGrafico->getRoot()->renderOneFrame()) exit = true;

		elapsedTicks = clock() - lastTicks;
	}
}
