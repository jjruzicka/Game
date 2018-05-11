#include "GameManager_c.h"
#include "StatsPJ_c.h"

GameManager_c::GameManager_c(Entidad* personaje)
{
	this->personaje = personaje;
	misionActiva = nullptr;
}


GameManager_c::~GameManager_c()
{
}

void GameManager_c::Update(){
	//POR VER SI EL GM ACTUALIZA TODO O POR EL CONTRARIO CADA UNO SE ACTUALIZA A SI MISMO
}
void GameManager_c::killADDMision(std::string nombre){//bichos llaman a esto
	if (misionActiva != nullptr){
		if (misionActiva->getTarget() == nombre){
			misionActiva->addCont();
			std::cout << misionActiva->getCont() <<"/" <<misionActiva->getTotal() << "\n";
			if (misionActiva->isComplete()){
				//estadisticas->sumaExp(50);
				StatsPJ_c* stats = new StatsPJ_c();
				personaje->GetComponent(stats)->sumaExp(misionActiva->getExp());
				misionActiva->getEntidad()->DestroyComponent(misionActiva);
				misionActiva = nullptr;
				std::cout << "Mision complete\n";
				//comunicarme para borrar dicha mision del npc. Hacer el delete de la mision en el npc
				//Poner por el GUI MISION COMPLETE
			}
		}
	}
}
bool GameManager_c::dameMision(Mision_c* mision){
	if (misionActiva != nullptr){
		std::cout << "Completo el cupo de misiones \n";
		return false;
	}
	else{
		misionActiva = mision;
		std::cout << misionActiva->getTarget() << ": " << misionActiva->getCont() << "/" << misionActiva->getTotal() << "\n";
		return true;
	}
}

