#ifndef ANIMACION_C_H
#define ANIMACION_C_H
#include "Component.h"
#include "Entidad.h"
//#include <Ogre.h>
#include "Render_c.h"
#include <string.h>
class Animacion_c :	public Component
{
public:
	Animacion_c(Entidad* ent);
	Animacion_c(){};
	virtual ~Animacion_c();
	void Update();
	void playAnim(std::string animTop, std::string animBot);
	void playAnimTop1Time(std::string animTop);
	void stopAnim();
	void setFoward(){
		direction = 1;
	}
	void setBackwards(){
		direction = -1;
	}
private:
	Ogre::Entity* entidadOgre;
	Entidad* entidad;
	Ogre::AnimationState* animState;
	Ogre::AnimationState* animState2;
	bool animacionActivada;
	int direction;
	Render_c * rnd;
	MotorGrafico * motorGrafico;
};
#endif

