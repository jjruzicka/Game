#ifndef MISION_C
#define MISION_C
#include <string>
#include "Component.h"

class Mision_c : public Component
{
public:
	Mision_c(int total, std::string target);
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

private:

	int cont;//contador de los objetivos
	int total;//objetivos totales
	std::string target;//objetivo al que buscar, matar, etc
};

#endif