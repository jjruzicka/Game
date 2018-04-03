#include "Render_c.h"


Render_c::Render_c(Ogre::SceneNode*src, Entidad* ent, std::string nombre)
{
	this->ent = ent;
	this->node = src;
	
	entOgre = node->getCreator()->createEntity("ogrehead", "ogrehead.mesh");
	node->translate(ent->getPox(), ent->getPoy(), ent->getPoz());
	
	node->attachObject(entOgre);
	
}

void Render_c::Update(){

}
Render_c::~Render_c()
{
}
