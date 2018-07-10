#ifndef PLAYERCONTROLLER_C_H
#define PLAYERCONTROLLER_C_H
#include "Entidad.h"
#include <OgreRenderWindow.h>
#include "RigidBody_c.h"
#include "Render_c.h"
#include "Juego.h"
#include "StatsPJ_c.h"
#include "InputManager.h"
class PlayerController_c : public Component,  OIS::KeyListener
{
public:
	PlayerController_c(Entidad* ent, Juego* escena, StatsPJ_c* estadisticas);
	PlayerController_c(){};
	void Update();
	~PlayerController_c();
	void chocasCon(int i, Entidad* ent);//0 para cuando no es nada, 1 npc
	int getCdCuracion(){
		return cdCuracion;
	}
	int getContCuracion(){
		return contCura;
	}
	void setCdCuracion(int i){
		cdCuracion = i;
	}
private:
	bool keyPressed(const OIS::KeyEvent& keyP);
	bool keyReleased(const OIS::KeyEvent& keyP);
	/*bool mouseMoved(const OIS::MouseEvent& me);
	bool mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id);*/
	InputManager * inputManager;
	Entidad* entidad;
	bool mas, istimetoStop;
	Juego* escena;
	StatsPJ_c* estadisticas;
	Ogre::SceneNode* node;
	RigidBody_c* rb;
	int chocoCon;
	Entidad* entColision;
	Render_c* rc;
	int cdAtack;
	int contAtack;

	int cdCuracion;
	int contCura;
};
#endif
