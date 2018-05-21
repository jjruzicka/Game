#ifndef GAMEMANAGER_C_H
#define GAMEMANAGER_C_H
#include <string>
#include "Mision_c.h"
#include "Entidad.h"
class GameManager_c : public Component
{
public:
	GameManager_c(Entidad* Personaje);
	~GameManager_c();
	void Update();
	bool complete;
	bool dameMision(Mision_c* mision);
	void killADDMision(std::string nombre);
private:
	Entidad* personaje;
	Mision_c* misionActiva;
};

#endif