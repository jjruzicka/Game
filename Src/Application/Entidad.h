#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <vector>

#include "Component.h"

struct Pos{
	int x;
	int y;
	int z;
};


class Entidad
{
public:
	Entidad();
	~Entidad();
	void Update();
	void AddComponent(Component * component);

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
	
};

#endif
