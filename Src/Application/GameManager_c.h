#ifndef GAMEMANAGER_C_H
#define GAMEMANAGER_C_H
#include <string>
#include "Mision_c.h"
#include "Entidad.h"
#include "EstadosManager.h"
class GameManager_c : public Component
{
public:
	GameManager_c(Entidad* Personaje);
	~GameManager_c();
	void Update();
	bool dameMision(Mision_c* mision);
	void killADDMision(std::string nombre);
	bool getMisionIsActive(){
		return misionActiva != nullptr;
	}
	std::string getObjetive(){
		return misionActiva->getTarget();
	}
	int getObjetiveNum(){
		return misionActiva->getTotal();
	}
	int getObjetiveCOnt(){
		return misionActiva->getCont();
	}
	int getObjetiveExp(){
		return misionActiva->getExp();
	}
	void setMisionesTotales(int mt){
		misionesTotales = mt;
	}
private:
	Entidad* personaje;
	Mision_c* misionActiva;
	EstadosManager * estadosManager;
	int misionesCompletadas, misionesTotales;
};

#endif