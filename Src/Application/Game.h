#pragma once
#include "EstadosManager.h"
#include "MotorGrafico.h"
#include "MotorFisico.h"
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
	MotorFisico * motorFisico;
	InputManager * inputManager;

	bool exit;
	int cont;
};

