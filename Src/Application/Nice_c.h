#ifndef NICE_C_H
#define NICE_C_H
#include "Entidad.h"
#include "Component.h"
class Nice_c : public Component
{
public:
	Nice_c(Entidad* ent);
	~Nice_c();
	void Update();
private:
	Entidad* entidad;
};
#endif
