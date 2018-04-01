#include "Entidad.h"
#include <typeinfo>
#include <string>
Entidad::Entidad(std::string id)
{
	posicion = { 0, 0, 0 };
	rotation = { 0, 0, 0 };
	identificador = id;
}


Entidad::~Entidad()
{
	for (int i = 0; i < componentes.size(); i++){
		delete componentes[i];
	}
}

void Entidad::AddComponent(Component * component){
	componentes.push_back(component);
}

void Entidad::Update(){
	for (int i = 0; i < componentes.size(); i++)
		componentes[i]->Update();
}