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

	int getPox(){
		return posicion.x;
	}
	int getPoy(){
		return posicion.y;
	}
	int getPoz(){
		return posicion.z;
	}

	int getRox(){
		return rotation.x;
	}
	int getRoy(){
		return rotation.y;
	}
	int getRoz(){
		return rotation.z;
	}


	void setPox(int x){
		posicion.x = x;
	}
	void setPoy(int y){
		posicion.y=y;
	}
	void setPoz(int z){
		 posicion.z=z;
	}
	void setRox(int x){
		rotation.x = x;
	}
	void setRoy(int y){
		rotation.y = y;
	}
	void setRoz(int z){
		rotation.z = z;
	}
	int getAngRot(){
		return angRot;
	}
	void setAngRot(int z){
		angRot = z;
	}


	int getOrientationX(){
		return orientacion.x;
	}

	int getOrientationY(){
		return orientacion.y;
	}

	int getOrientationZ(){
		return orientacion.z;
	}

	void setOrientationX(int x){
		orientacion.x = x;
	}

	void setOrientationY(int y){
		orientacion.y = y;
	}

	void setOrientationZ(int z){
		orientacion.z = z;
	}
private:
	std::vector<Component*> componentes;

	Pos posicion;
	Pos rotation;
	Pos orientacion;
	int angRot;
};

#endif
