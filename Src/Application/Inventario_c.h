#ifndef INVENTARIO_C_H
#define INVENTARIO_C_H
#include "Component.h"
#include "Entidad.h"
#include <unordered_map>
#include <string>
#include "Objeto.h"


class Inventario_c : public Component
{
public:
	Inventario_c(Entidad* e);
	~Inventario_c();
	void Update();

	void addObject(Objeto * e);
	void removeObject(Objeto * e);
	void seeObjects();

private:
	int contPlantas;
	int contColeccionables;
	int contPociones;
	Entidad* entidad;
	std::unordered_map<std::string,int> inventario;


};
#endif
