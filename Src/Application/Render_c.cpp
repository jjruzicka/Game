#include "Render_c.h"


Render_c::Render_c(Ogre::SceneNode*src, Entidad* ent, std::string malla, std::string nombre)
{
	this->ent = ent;
	this->node = src;
	std::string mesh = malla + ".mesh";
	entOgre = node->getCreator()->createEntity(nombre, mesh);
	node->translate(ent->getPox(), ent->getPoy(), ent->getPoz());
	//ent->setGpos(ent->getPox(), ent->getPoy(), ent->getPoz());
	
	node->attachObject(entOgre);
	
}

void Render_c::Update(){
	node->translate(ent->getPox(), ent->getPoy(), ent->getPoz());
    node->rotate(Ogre::Vector3(ent->getRox(), ent->getRoy(), ent->getRoz()), Ogre::Degree(ent->getVRot()));
	ent->setGpos(ent->getPox(), ent->getPoy(), ent->getPoz());
    
}
Render_c::~Render_c()
{
}
