#ifndef MOVE_C_H
#define MOVE_C_H
#include "Component.h"
#include "Entidad.h"
class Move_c : public Component
{
public:
	Move_c(Entidad* e);
	~Move_c();
	void Update();
private:
	Entidad* entidad;
};
#endif
