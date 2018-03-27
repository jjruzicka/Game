#ifndef GAMEMANAGER_C
#define GAMEMANAGER_C
#include <string>
#include "Component.h"
#include "Mision_c.h"
#include "Entidad.h"
class GameManager_c : public Component
{
public:
	GameManager_c(Entidad* GUI, Entidad* Personaje);
	~GameManager_c();
	void Update();
	bool dameMision(Mision_c* mision);
	void killADDMision(std::string nombre);
private:
	Entidad* GUImision;//gui de la mision activa
	Entidad* personaje;
	Mision_c* misionActiva;
};

#endif