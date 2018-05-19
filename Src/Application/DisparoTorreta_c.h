#pragma once
#include "Component.h"
#include "Entidad.h"
#include <cstdio>
#include <ctime>
#include <iostream>

class DisparoTorreta_c :
	public Component
{
public:
	DisparoTorreta_c(Entidad* ent);
	virtual ~DisparoTorreta_c();
	void Update();

private:
	Entidad * entidad;

	std::clock_t start;
	double cooldown;
	bool getTime;
};

