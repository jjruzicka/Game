#include "EstadosManager.h"
#include "Menu.h"
#include "Juego.h"

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

void EstadosManager::changeEstado(std::string tipo, std::string path){
	popEstado();
	Escenas * escena;
	if (tipo == "Menu")
		escena = new Menu();
	if (tipo == "Nivel")
		escena = new Juego(path);
	pushEstado(escena);
}
