#ifndef JUEGO_H
#define JUEGO_H
#include "GameManager_c.h"
#include "EscenasManager.h"
#include "GUI.h"
#include "InputComponent.h"
#include <vector>

class Juego : public Escenas, public InputComponent
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
	void updateGUI();
	GUI* guiGame;
	bool exit;
private:
	int cont;
	//variables vienen de escenas.h
	virtual bool keyPressed(const OIS::KeyEvent& keyP);
	virtual bool keyReleased(const OIS::KeyEvent& keyP);
	GameManager_c* gm;
	std::vector<Entidad*> arbolitos;
	void createArbolitos();
	int numArboles;

	EscenasManager* escenasManager;
};
#endif