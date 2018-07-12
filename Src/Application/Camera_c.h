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
	~Camera_c();
	void Update(){};

	Ogre::Camera* getCamera(){
		return cam;
	}
	Ogre::SceneNode* getCamNode(){
		return camNode;
	}
	Ogre::Viewport* getViwePort(){
		return vp;
	}
private:

	MotorGrafico * motorGrafico;

	Entidad * entidad;

	//OGRE
	Ogre::Camera* cam; 
	Ogre::SceneNode* camNode; 
	Ogre::Viewport* vp;
};

