#ifndef RENDER_C_H
#define RENDER_C_H
#include "Component.h"
#include "Entidad.h"
#include "MotorGrafico.h"
#include <string>
#include <Ogre.h>

class Render_c : public Component
{
public:
	Render_c(std::string nombreNodo,Entidad* ent, std::string nombreMalla, std::string nombreEntidad);
	Render_c(){}
	~Render_c();
	Ogre::SceneNode* getNode(){
		return node;
	}
	std::string getIDRender(){
		return nombreEntidad;
	}
	Ogre::Entity * getEntity(){
		return entOgre;
	}
	virtual	void Update();
private:
	MotorGrafico * motorGrafico;
	Ogre::SceneNode* node;
	Entidad* ent;
	std::string nombreEntidad;
	Ogre::Entity* entOgre;
	Ogre::Quaternion anguloRot;
	float anguloRotent;
};
#endif
