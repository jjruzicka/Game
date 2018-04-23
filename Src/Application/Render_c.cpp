#include "Render_c.h"
#include <iostream>

Render_c::Render_c(Ogre::SceneNode*src, Entidad* ent, std::string nombre)
{
	this->ent = ent;
	this->node = src;
	std::string mesh = nombre + ".mesh";
	entOgre = node->getCreator()->createEntity(nombre, mesh);
	node->setPosition(ent->getPox(), ent->getPoy(), ent->getPoz());
	node->attachObject(entOgre);
	anguloRot = Ogre::Quaternion(Ogre::Degree(0),Ogre::Vector3::UNIT_Y);
}

void Render_c::Update(){
	/*
	Ogre::Vector3 originalDirectionVector(1,1,0);
	Ogre::Quaternion rotation(Ogre::Degree(180), Ogre::Vector3::UNIT_X); //or whatever you rotate your node by
	Ogre::Vector3 newDirectionVector = rotation * originalDirectionVector; //here's your new rotated vector.
	*/

	if (ent->getRoy() != 0){
		
		anguloRot = Ogre::Quaternion(Ogre::Degree(ent->getAngRot()), Ogre::Vector3::UNIT_Y);
		node->rotate(anguloRot);
	}

	node->setPosition(ent->getPox(), ent->getPoy(), ent->getPoz());
	
	
}

//posicion+orientacion
//orientacion (cos(q) , 0 , sen (q))
Render_c::~Render_c()
{
}