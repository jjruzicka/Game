#ifndef JUEGO_H
#define JUEGO_H
#include "GameManager_c.h"
#include "GUI.h"

#include "InputManager.h"
class Juego : public Escenas
{
public:
	Juego();
	virtual ~Juego();
	virtual bool run();
	void activaMision(Entidad* npc);
	void atacar(Entidad* npc);
	void killAdd(Entidad* obj);
	void muerteJugador();
	
private:

	InputManager * inputManager;

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
};
#endif