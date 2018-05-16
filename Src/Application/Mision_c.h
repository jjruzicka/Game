#ifndef MISION_C_H
#define MISION_C_H
#include <string>
#include "Component.h"
#include "Entidad.h"
class Mision_c : public Component
{
public:
	Mision_c(int total, std::string target,int exp, Entidad* ent);
	Mision_c(){};
	void Update(){};
	~Mision_c();

	int getTotal(){
		return total;
	}

	int getCont(){
		return cont;
	}

	int addCont(){
		cont += 1;
		return cont;
	}

	int addCont(int a){
		cont += a;
		return cont;
	}

	std::string getTarget(){
		return target;
	}

	bool isComplete(){
		return cont >= total;
	}

	Entidad* getEntidad(){
		return ent;
	}
	int getExp(){
		return exp;
	}
private:
	Entidad* ent;
	int exp;
	int cont;//contador de los objetivos
	int total;//objetivos totales
	std::string target;//objetivo al que buscar, matar, etc
};

#endif