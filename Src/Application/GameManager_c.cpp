#include "GameManager_c.h"


GameManager_c::GameManager_c(Entidad* GUI, Entidad* personaje)
{
	this->GUImision = GUI;
	this->personaje = personaje;
	misionActiva = nullptr;
}


GameManager_c::~GameManager_c()
{
}

void GameManager_c::Update(){
	//POR VER SI EL GM ACTUALIZA TODO O POR EL CONTRARIO CADA UNO SE ACTUALIZA A SI MISMO
}
void GameManager_c::killADDMision(std::string nombre){
	if (misionActiva != nullptr){
		if (misionActiva->getTarget() == nombre){
			misionActiva->addCont();
			if (misionActiva->isComplete()){
				misionActiva = nullptr;
				//comunicarme para borrar dicha mision del npc. Hacer el delete de la mision en el npc
				//Poner por el GUI MISION COMPLETE
			}
		}
	}
}
bool GameManager_c::dameMision(Mision_c* mision){
	if (misionActiva != nullptr){


		return false;
	}
	else{
		misionActiva = mision;
		return true;
	}
}

