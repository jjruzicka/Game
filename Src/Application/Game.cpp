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
}


Game::~Game()
{
}

void Game::run(){
	while (true){
		estadosManager->topEstado()->run();
	}
}
