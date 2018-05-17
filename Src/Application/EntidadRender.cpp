#include "EntidadRender.h"
#include <typeinfo>
#include <string>
#include "Render_c.h"
EntidadRender::EntidadRender(std::string id, std::string idRender, Ogre::SceneManager* scnMgr) : Entidad(id)
{
	this->idRender = idRender;
	Render_c* render = new Render_c(scnMgr->getRootSceneNode()->createChildSceneNode(idRender), this, "Sinbad", idRender);
	AddComponent(render);
}


EntidadRender::~EntidadRender()
{
	for (int i = 0; i < componentes.size(); i++){
		delete componentes[i];
	}
}