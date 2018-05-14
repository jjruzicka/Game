#pragma once
#include "Escenas.h"
#include "GameManager_c.h"
class Juego : public Escenas
{
public:
	Juego();
	virtual ~Juego();
	virtual bool run();
	virtual bool initBullet();
	void activaMision(Entidad* npc);
	void atacar(Entidad* npc);
	void killAdd(Entidad* obj);
private:
	//variables vienen de escenas.h
	GameManager_c* gm;
};