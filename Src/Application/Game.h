#pragma once
#include "EstadosManager.h"
#include "MotorGrafico.h"
class Game
{
public:
	Game();
	virtual ~Game();
	void run();

private:

	EstadosManager * estadosManager;
	MotorGrafico * motorGrafico;

	bool exit;
	int cont;
};

