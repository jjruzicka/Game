#pragma once
#include "Component.h"
#include "Entidad.h"
#include "MotorGrafico.h"
class Camera_c :
	public Component
{
public:
	Camera_c(){}
	Camera_c(Entidad * ent);
	virtual ~Camera_c();
	void Update(){};
	Ogre::SceneNode* getCamNode(){
		return camNode;
	}
private:

	MotorGrafico * motorGrafico;

	Entidad * entidad;

	//OGRE
	Ogre::Camera* cam; 
	Ogre::SceneNode* camNode; 
	Ogre::Viewport* vp;
};

