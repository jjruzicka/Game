#pragma once
#include "Entidad.h"
class Proyectil :
	public Entidad
{
public:
	Proyectil(float posGlx, float posGly, float posGlz, float posLox, float posLoy, float posLoz, float oriX, float oriY, float oriZ);
	~Proyectil();
	void setPosicionLocal(PosF pos){
		posicionLocal.x = pos.x;
		posicionLocal.y = pos.y;
		posicionLocal.z = pos.z;
	}
	PosF getPosicionLocal(){
		return posicionLocal;
	}

private:
	PosF posicionLocal;
	const int DISTACIA_MAX = 100;
};

