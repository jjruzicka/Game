#pragma once
#include "Component.h"
#include "Entidad.h"
#include <string>
#include <Ogre.h>

class Render_c : public Component
{
public:
	Render_c(Ogre::SceneNode*node, Entidad* ent, std::string nombre);
	~Render_c();
virtual	void Update();
private:
	Ogre::SceneNode* node;
	Entidad* ent;
	Ogre::Entity* entOgre;
};

