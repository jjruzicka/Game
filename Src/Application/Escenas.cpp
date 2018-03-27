#include "Escenas.h"
#include <iostream>
#include "Entidad.h"
#include "GameManager_c.h"
#include "Hola_c.h"
#include "Nice_c.h"
#include "Mision_c.h"
Escenas::Escenas()
{
	Entidad* ent = new Entidad();
	
	entidades.push_back(ent);
	Mision_c* mision = new Mision_c(ent, 0, "pollo");
	Component* vida = new Hola_c(ent);
	Component* nice = new Nice_c(ent);
	

	entidades[0]->AddComponent(nice);
	entidades[0]->AddComponent(vida);
	entidades[0]->AddComponent(mision);
	Hola_c* a = new Hola_c(ent);
	Hola_c* b;
	ent->Update();
	ent->GetComponent(a)->Update();

	b = ent->GetComponent(a);

	std::cout << b->vida << "\n";

}


Escenas::~Escenas()
{
	for (int i = 0; i < entidades.size();i++)
		delete entidades[i];
}
