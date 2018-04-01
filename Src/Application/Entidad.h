#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <vector>

#include "Component.h"
#include <iostream>

struct Pos{
	int x;
	int y;
	int z;
};

//enum Objetos{NADA, ESPADA};
class Entidad
{
public:
	Entidad(std::string id);
	~Entidad();
	void Update();
	void AddComponent(Component * component);
	Pos getPos(){
		return posicion;
	}
	void setPos(int x, int y, int z){
		Pos newPosicion;
		newPosicion.x = x;
		newPosicion.y = y;
		newPosicion.z = z;
		posicion = newPosicion;
	}
	std::string getID(){
		return identificador;
	}

	template <class T>
	T*  GetComponent(T* a){
		int i = 0;
		while (i < componentes.size()){
			if (typeid(*componentes[i]) == typeid(*a)){
				return dynamic_cast<T*>(componentes[i]);
			}
			i++;
		}
		return nullptr;
	}

private:
	std::vector<Component*> componentes;

	Pos posicion;
	Pos rotation;
	std::string identificador;
	
};

#endif
