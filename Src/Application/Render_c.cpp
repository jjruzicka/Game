#include "Render_c.h"
#include <iostream>

Render_c::Render_c(Ogre::SceneNode*src, Entidad* ent, std::string nombreMalla, std::string nombreEntidad)
{
	this->ent = ent;
	this->node = src;
	std::string mesh = nombreMalla + ".mesh";
	entOgre = node->getCreator()->createEntity(nombreEntidad, mesh);
	node->setPosition(ent->getPox(), ent->getPoy(), ent->getPoz());
	node->attachObject(entOgre);
	anguloRot = Ogre::Quaternion(Ogre::Degree(0),Ogre::Vector3::UNIT_Y);
}

void Render_c::Update(){
	if (ent->getRoy() != 0){
		anguloRotent += ent->getAngRot();//QUIZA SON RAD LO MAS SEGURO
		anguloRot = Ogre::Quaternion(Ogre::Degree(ent->getAngRot()), Ogre::Vector3::UNIT_Y);
		//std::cout << node->getOrientation() << '\n';
		node->rotate(anguloRot);
		ent->setOrientationX(sin(anguloRotent));
		ent->setOrientationZ(cos(anguloRotent));
	}
	node->setPosition(ent->getPox(), ent->getPoy(), ent->getPoz());
}
Render_c::~Render_c()
{
	node->detachObject(ent->getID());
}