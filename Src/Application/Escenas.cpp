#include "Escenas.h"
#include <iostream>
#include "Entidad.h"
#include "Hola_c.h"
#include "Nice_c.h"
#include "Move_c.h"
#include "Mata_c.h"
#include "Inventario_c.h"

Escenas::Escenas()
{
	Entidad* ent = new Entidad("Juanjo");
	Entidad* ent2 = new Entidad("Manue");
	Entidad * planta1 = new Entidad("planta");
	Entidad * planta2 = new Entidad("planta");
	Entidad * pocion = new Entidad("pocion");
	Entidad * pocion2 = new Entidad("pocion");
	Entidad * po = new Entidad("pkdsjsdon");
	Entidad * po2 = new Entidad("pok<ejhfJHn");
	Entidad * po3 = new Entidad("pkdsjsdon");
	Entidad * po4 = new Entidad("pkdsjsdon");
	Entidad * po5 = new Entidad("pok<ejhfJHn");


	entidades.push_back(ent);
	entidades.push_back(ent2);
	//entidades.push_back(espaditadegita);

	Component* vida = new Hola_c(ent);
	Component* nice = new Nice_c(ent);
	Component* move = new Move_c(ent);
	Component* mata = new Mata_c(ent2, ent);
	Component* inventario = new Inventario_c(ent);
	

	entidades[0]->AddComponent(nice);
	entidades[0]->AddComponent(vida);
	entidades[0]->AddComponent(move);
	entidades[0]->AddComponent(inventario);

	entidades[1]->AddComponent(mata);


	Hola_c* a = new Hola_c(ent);
	Move_c* oscar = new Move_c(ent);
	Mata_c* oscar2 = new Mata_c(ent2,ent);
	Inventario_c* oscar3 = new Inventario_c(ent);
	Move_c* aux;
	Mata_c* aux2;
	Inventario_c* aux3;
	Hola_c* b;
	for (int i = 0; i < entidades.size(); ++i){
		entidades[i]->Update();
	}
	
	//ent->Update();
	aux = ent->GetComponent(oscar);
	aux2 = ent2->GetComponent(oscar2);
	aux3 = ent->GetComponent(oscar3);

	if (aux3 != nullptr){
		aux3->addObject(planta1);
		aux3->addObject(planta2);
		aux3->addObject(pocion);
		aux3->addObject(pocion2);
		aux3->addObject(po);
		aux3->addObject(po2);
		aux3->addObject(po3);
		aux3->addObject(po4);
		aux3->addObject(po5);
	}


	//ent->GetComponent(a)->Update();

	if (aux2 != nullptr)
		aux2->Update();
	if (aux != nullptr)
		aux->Update();
	b = ent->GetComponent(a);

	if (aux2 != nullptr)
		aux2->Update();

	if (aux3 != nullptr)
		aux3->seeObjects();

	if (aux3 != nullptr){
		aux3->removeObject(planta1);
		
	}
	if (aux3 != nullptr)
		aux3->seeObjects();
	//std::cout << ent->getPos().x << "\n";
	//std::cout << b->vida << "\n";

	
}


Escenas::~Escenas()
{
	for (int i = 0; i < entidades.size();i++)
		delete entidades[i];
}
