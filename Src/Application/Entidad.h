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
struct PosF{
	float x;
	float y;
	float z;
};

class Entidad
{
public:
	Entidad();
	Entidad(std::string id);
	~Entidad();
	void Update();
	void AddComponent(Component * component);
	int numComponent(){
		return componentes.size();
	}

	void DestroyComponent(Component* c){
		int i = 0;
		std::cout << componentes.size() << "-> ";
		while (i < componentes.size()){
			if (typeid(*componentes[i]) == typeid(*c)){
				Component* aux = componentes[i];
				componentes[i] = componentes[componentes.size() - 1];
				componentes[componentes.size() - 1] = aux;
				componentes.pop_back();
				delete aux;
				return;
			}
			i++;
		}
		std::cout << componentes.size() << "\n";
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

	float getPox(){
		return posicion.x;
	}
	float getPoy(){
		return posicion.y;
	}
	float getPoz(){
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


	void setPox(float x){
		posicion.x = x;
	}
	void setPoy(float y){
		posicion.y = y;
	}
	void setPoz(float z){
		posicion.z = z;
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


	float getOrientationX(){
		return orientacion.x;
	}

	float getOrientationY(){
		return orientacion.y;
	}

	float getOrientationZ(){
		return orientacion.z;
	}

	void setOrientationX(float x){
		orientacion.x = x;
	}

	void setOrientationY(float y){
		orientacion.y = y;
	}

	void setOrientationZ(float z){
		orientacion.z = z;
	}

    std::string getID(){
        return i;
    }
    void setID(std::string id){
        i = id;
    }

protected:
	std::vector<Component*> componentes;

	PosF posicion;
	Pos rotation;
	PosF orientacion;
	int angRot;
    std::string i = " ";
};
#endif
