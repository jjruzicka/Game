#pragma once
#ifndef ANIMANAGER_C_H
#define ANIMANAGER_C_H
#include "Component.h"
#include "Entidad.h"
#include <string>
#include <Ogre.h>

class AniManager_c : public Component
{
public:
	AniManager_c(Entidad* ent);
	AniManager_c(){};
	~AniManager_c();
	void Update();
	void playAnim();
	void stopAnim();
protected:
	Ogre::Entity* entidadOgre;
	Entidad* entidad;
	Ogre::AnimationState* animState;
	Ogre::AnimationState* animState2;
	bool animacionActivada;
};
#endif

