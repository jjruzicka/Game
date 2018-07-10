#include "EntidadRender.h"
#include <typeinfo>
#include <string>
#include "Render_c.h"
EntidadRender::EntidadRender(std::string id, std::string idRender, Ogre::SceneManager* scnMgr) : Entidad(id)
{
	this->idRender = idRender;
	Render_c* render;
	if (id == "p2")
		render = new Render_c(idRender, this, "Sinbad", idRender);
	else
		render = new Render_c(idRender, this, "WoodPallet", idRender);
	AddComponent(render);
}


EntidadRender::~EntidadRender()
{
	for (int i = 0; i < componentes.size(); i++){
		delete componentes[i];
	}
}