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
	void creaPan(int x, int y, int z, std::string idRender);
	void creaOgreEnemyMele(int x, int y, int z, std::string idRender);
	void creaNpcMisiones(int x, int y, int z, int misionT1,int expM1, int misionT2,int expM2, std::string idRender);
	void creaOgroTorreta(int x, int y, int z, std::string idRender);
	//variables vienen de escenas.h
	Entidad* ent1; // Player
	GameManager_c* gm;
	EscenasManager* escenasManager;
};
#endif