#include "Inventario_c.h"
#include <iostream>


Inventario_c::Inventario_c(Entidad* ent)
{
	entidad = ent;
	contPlantas = 1;
	contPociones = 1;
	contColeccionables = 1;
}


Inventario_c::~Inventario_c()
{

}

void Inventario_c::Update(){

}

/*void Inventario_c::addObject(Component *c){
	inventario2.insert({ e->getID(), c });
}*/
void Inventario_c::addObject(Entidad *e) {

	if (inventario.count(e->getID()) == 0)
		inventario.insert({ e->getID(),1 });
	else
	{
		auto it = inventario.find(e->getID());
		if (it != inventario.end()) {
			if (e->getID() == "planta") {
				contPlantas++;
				it->second = contPlantas;
			}
			else if (e->getID() == "pocion") {
				contPociones++;
				it->second = contPociones;
			}
			else {
				contColeccionables++;
				it->second = contColeccionables;
			}
		}
	}

}

void Inventario_c::removeObject(Entidad *e){
	//if (inventario.count(e->getID())==1)
	auto it = inventario.find(e->getID());
	if (it->second == 1)
		inventario.erase(e->getID());
	else
	{
		
		if (it != inventario.end()) {
			if (e->getID() == "planta") {
				contPlantas--;
				it->second = contPlantas;
			}
			else if (e->getID() == "pocion") {
				contPociones--;
				it->second = contPociones;
			}
			else {
				contColeccionables--;
				it->second = contColeccionables;
			}
		}
	}
}

void Inventario_c::seeObjects(){
	for (auto it = inventario.begin(); it != inventario.end(); ++it)
	{
		std::cout << it->first << "      "<< it->second << "\n";
	}
	std::cout << contPlantas << "  " << contPociones << "  " << contColeccionables << "\n";
}