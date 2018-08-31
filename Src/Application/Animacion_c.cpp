#include "Animacion_c.h"


Animacion_c::Animacion_c(Entidad* ent)
{
	motorGrafico = MotorGrafico::getInstancia();
	animacionActivada = false;
	entidad = ent;
	rnd = new Render_c();
	entidadOgre = entidad->GetComponent(rnd)->getEntity();
}


Animacion_c::~Animacion_c()
{
	//motorGrafico->getSceMgr()->destroyAllAnimationStates();
	//delete rnd;
}

void Animacion_c::Update(){
	if (animacionActivada){
		animState->addTime(0.05 * direction);
		animState2->addTime(0.05 * direction);
	}
}
void Animacion_c::playAnim(std::string animTop, std::string animBot){
	stopAnim();
	animacionActivada = true;
	animState = entidadOgre->getAnimationState(animTop);
	animState->setLoop(true);
	animState->setEnabled(true);

	animState2 = entidadOgre->getAnimationState(animBot);
	animState2->setLoop(true);
	animState2->setEnabled(true);
}
void Animacion_c::stopAnim(){
	if (animacionActivada){
		animacionActivada = false;
		animState->setEnabled(false);
		animState2->setEnabled(false);
	}
}
void Animacion_c::playAnimTop1Time(std::string animTop){
	if (animacionActivada)	animState->setEnabled(false);
	animState = entidadOgre->getAnimationState(animTop);
	animState->setLoop(false);
	animState->setTimePosition(0);
	animState->setEnabled(true);

}