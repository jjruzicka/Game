#ifndef JUEGO_H
#define JUEGO_H
#include "GameManager_c.h"
#include "EscenasManager.h"
class Juego : public Escenas
{
public:
	Juego(EscenasManager* escenasManager);
	virtual ~Juego();
	virtual bool run();
	virtual bool initBullet();
	void activaMision(Entidad* npc);
	void atacar(Entidad* npc);
	void killAdd(Entidad* obj);
	void muerteJugador();

	Entidad * getPlayer(){
		return ent1;
	}
private:
	//variables vienen de escenas.h
	Entidad* ent1; // Player
	GameManager_c* gm;
	EscenasManager* escenasManager;
};
#endif