#ifndef JUEGO_H
#define JUEGO_H
#include "GameManager_c.h"
#include "EscenasManager.h"
#include "InputManager.h"
#include "GUI.h"
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
	
private:
	void createArbolitos();
	void updateGUI();
	GUI* guiGame;
	int cont;
	virtual bool keyPressed(const OIS::KeyEvent& keyP);
	virtual bool keyReleased(const OIS::KeyEvent& keyP);
	void creaPan(int x, int y, int z, std::string idRender);
	void creaOgreEnemyMele(int x, int y, int z,int vida, int damage, int armor, std::string idRender);
	void creaNpcMisiones(int x, int y, int z, int misionT1, int expM1, int misionT2, int expM2, int misionT3, int expM3, int misionT4, int expM4, int misionT5, int expM5, std::string idRender);
	//variables vienen de escenas.h
	int numArboles;
	int contArboles;
	std::vector<Entidad*> arbolitos;
	GameManager_c* gm;
	EscenasManager* escenasManager;
};
#endif