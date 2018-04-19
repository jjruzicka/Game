#include "Render_c.h"


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
	if (ent->getRoy() != 0){
		anguloRot = Ogre::Quaternion(Ogre::Degree(ent->getAngRot()), Ogre::Vector3::UNIT_Y);
		node->rotate(anguloRot);
	}
	node->setPosition(ent->getPox(), ent->getPoy(), ent->getPoz());
}
Render_c::~Render_c()
{
}