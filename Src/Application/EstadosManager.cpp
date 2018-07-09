#include "EstadosManager.h"


EstadosManager::EstadosManager()
{
}


EstadosManager::~EstadosManager()
{
}

void EstadosManager::pushEstado(Escenas * escena){
	pila.push(escena);
}

void EstadosManager::popEstado(){
	Escenas * aux = pila.top();
	pila.pop();
	delete aux;
}

Escenas * EstadosManager::topEstado(){
	return pila.top();
}

void EstadosManager::changeEstado(Escenas * escena){
	popEstado();
	pushEstado(escena);
}
