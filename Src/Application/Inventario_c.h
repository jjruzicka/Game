#ifndef INVENTARIO_C_H
#define INVENTARIO_C_H
#include "Component.h"
#include "Entidad.h"
#include <iostream>
#include <unordered_map>
#include <string>


class Inventario_c : public Component
{
public:
	Inventario_c(Entidad* e);
	~Inventario_c();
	void Update();

	void addObject(Entidad * e);
	void removeObject(Entidad * e);
	void seeObjects();

private:
	int contPlantas;
	int contColeccionables;
	int contPociones;
	Entidad* entidad;
	std::unordered_map<std::string,int> inventario;
	std::unordered_map<std::string, Component*> inventario2;


};
#endif
