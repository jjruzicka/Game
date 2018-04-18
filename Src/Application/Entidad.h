#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <vector>

#include "Component.h"

struct Pos{
	int x;
	int y;
	int z;
	int xGlob;
	int yGlob;
	int zGlob;
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

	int getGPox(){
		return posicion.xGlob;
	}
	int getGPoy(){
		return posicion.yGlob;
	}
	int getGPoz(){
		return posicion.zGlob;
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

    float getVRot(){
        return velRotacion;
    }

    void setVRot(float v){
        velRotacion=v;
    }


	void setPox(int x){
		//posicion.xGlob += x;
		posicion.x = x;
	}
	void setPoy(int y){
		//posicion.yGlob += y;
		posicion.y=y;
	}
	void setPoz(int z){
		//posicion.zGlob += z;
		 posicion.z=z;
	}
    void setRox(int x){
        //posicion.xGlob += x;
        rotation.x = x;
    }
    void setRoy(int y){
        //posicion.yGlob += y;
        rotation.y = y;
    }
    void setRoz(int z){
        //posicion.zGlob += z;
        rotation.z = z;
    }

	void setGpos(int xPos, int yPos, int zPos){
		posicion.xGlob += xPos;
		posicion.yGlob += yPos;
		posicion.zGlob += zPos;
	}

private:
	std::vector<Component*> componentes;

	Pos posicion;
	Pos rotation;
    float velRotacion;
};

#endif
