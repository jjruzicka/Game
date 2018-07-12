#include "Animacion_c.h"


Animacion_c::Animacion_c(Entidad* ent)
{
	animacionActivada = false;
	entidad = ent;
	rnd = new Render_c();
	entidadOgre = entidad->GetComponent(rnd)->getEntity();
}


Animacion_c::~Animacion_c()
{
	delete rnd;
}

void Animacion_c::Update(){
	if (animacionActivada){
		animState->addTime(0.05 * direction);
		animState2->addTime(0.05 * direction);
	}
}
void Animacion_c::playAnim(std::string animTop, std::string animBot){
	if (!animacionActivada){
		animacionActivada = true;
		animState = entidadOgre->getAnimationState(animTop);
		animState->setLoop(true);
		animState->setEnabled(true);

		animState2 = entidadOgre->getAnimationState(animBot);
		animState2->setLoop(true);
		animState2->setEnabled(true);
	}
}
void Animacion_c::stopAnim(){
	animacionActivada = false;
	animState->setEnabled(false);
	animState2->setEnabled(false);
}