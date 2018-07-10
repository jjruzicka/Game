#ifndef ESTADOSMANAGER
#define ESTADOSMANAGER
#include "Escenas.h"
#include <stack>

class EstadosManager
{
public:
	static EstadosManager * getInstancia(){
		if (instancia == nullptr)
			instancia = new EstadosManager();
		return instancia;
	}
	void pushEstado(Escenas * escena);
	void changeEstado(Escenas * escena);
	Escenas * topEstado();
private:
	static EstadosManager * instancia;
	EstadosManager();
	virtual ~EstadosManager();

	void popEstado();

	std::stack<Escenas*> pila;
};
#endif

