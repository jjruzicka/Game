#include "Estados.h"


Estados::Estados(Escenas* scn) : escen(scn)
{
	
	
}
void Estados::update(){
	if (entidades.size() != 0){
		for (int i = 0; i < entidades.size(); i++)
			entidades[i]->Update();
	}

}


Ogre::Camera* Estados::getCamera(){
	return escen->cam;
}

Ogre::Viewport* Estados::getVp(){
	return escen->vp;
}

InputComponent* Estados::getInput(){
	return escen->inputcomp_;
}

Estados::~Estados()
{
	
	
}
