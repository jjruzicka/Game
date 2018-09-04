#include "GameManager_c.h"
#include "StatsPJ_c.h"

StatsPJ_c* stats;

GameManager_c::GameManager_c(Entidad* personaje, Juego * game)
{
	this->personaje = personaje;
	this->escena = game;
	this->misionActiva = nullptr;
	stats = new StatsPJ_c();
	//estadosManager = EstadosManager::getInstancia();
	misionesCompletadas = misionesTotales = 0;
}


GameManager_c::~GameManager_c()
{
}

void GameManager_c::Update(){

}
bool GameManager_c::killADDMision(std::string nombre){
	if (misionActiva != nullptr){
		if (misionActiva->getTarget() == nombre){
			misionActiva->addCont();
			std::cout << misionActiva->getCont() <<"/" <<misionActiva->getTotal() << "\n";
			if (misionActiva->isComplete()){
				personaje->GetComponent(stats)->sumaExp(misionActiva->getExp());
				misionActiva->getEntidad()->DestroyComponent(misionActiva);
				misionActiva = nullptr;
				std::cout << "Mision complete\n";
				//Poner por el GUI MISION COMPLETE
				misionesCompletadas++;
				if (misionesCompletadas == misionesTotales){
					//estadosManager->changeEstado("Menu", "");
					escena->muerteJugador();
					return true; // Si se ha terminado el nivel 
				}
			}
		}
	}
	return false;
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

