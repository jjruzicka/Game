#ifndef JUEGO_H
#define JUEGO_H
#include "GameManager_c.h"
#include "GUI.h"

#include "InputManager.h"
class Juego : public Escenas
{
public:
	Juego(std::string path);
	virtual ~Juego();
	virtual bool run();
	void activaMision(Entidad* npc);
	void atacar(Entidad* npc);
	void killAdd(Entidad* obj);
	void muerteJugador();
	void entidadFactory(std::string path);
	
private:

	InputManager * inputManager;

	void createArbolitos();
	void updateGUI();
	GUI* guiGame;
	int cont;
	virtual bool keyPressed(const OIS::KeyEvent& keyP);
	virtual bool keyReleased(const OIS::KeyEvent& keyP);

	GameManager_c* gm;
};
#endif