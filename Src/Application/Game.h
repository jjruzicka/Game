#pragma once
#include "EstadosManager.h"
#include "MotorGrafico.h"
#include "InputManager.h"
class Game
{
public:
	Game();
	virtual ~Game();
	void run();

private:

	EstadosManager * estadosManager;
	MotorGrafico * motorGrafico;
	InputManager * inputManager;

	bool exit;
	int cont;
};

