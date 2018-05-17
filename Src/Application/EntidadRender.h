#ifndef ENTIDADRENDER_H
#define ENTIDADRENDER_H
#include <vector>
#include "Entidad.h"
#include "Component.h"
#include <Ogre.h>
#include <iostream>

class EntidadRender : public Entidad
{
public:
	EntidadRender(std::string id, std::string idRender, Ogre::SceneManager* scnMgr);
	EntidadRender(std::string id) : Entidad(id){}
	~EntidadRender();

	std::string getIdRender(){
		return idRender;
	}

	void setIdRender(std::string i){
		this->idRender = i;
	}

protected:
	std::string idRender;
};
#endif
