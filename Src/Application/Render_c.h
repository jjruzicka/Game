#ifndef RENDER_C_H
#define RENDER_C_H
#include "Component.h"
#include "Entidad.h"
#include <string>
#include <Ogre.h>

class Render_c : public Component
{
public:
	Render_c(Ogre::SceneNode*node, Entidad* ent, std::string nombreMalla, std::string nombreEntidad);
	Render_c(){}
	~Render_c();
	Ogre::SceneNode* getNode(){
		return node;
	}
	virtual	void Update();
private:
	Ogre::SceneNode* node;
	Entidad* ent;
	Ogre::Entity* entOgre;
	Ogre::Quaternion anguloRot;
	float anguloRotent;
};
#endif
