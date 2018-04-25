#include "Entidad.h"
#include <typeinfo>
#include <string>
Entidad::Entidad()
{
	posicion = { 0, 0, 0 }; // coordenadas de un punto
	rotation = { 0, 0, 0 }; // vector
	orientacion = { 0, 0, 1 }; // vector
	angRot = 0;

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