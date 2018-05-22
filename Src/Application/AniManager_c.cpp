#include "AniManager_c.h"
#include "Render_c.h"

AniManager_c::AniManager_c(Entidad* ent)
{
	animacionActivada = false;
	entidad = ent;
	Render_c* rnd = new Render_c();
	entidadOgre = entidad->GetComponent(rnd)->getEntity();

}


AniManager_c::~AniManager_c()
{
}

void AniManager_c::Update(){
	if (animacionActivada){
		animState->addTime(0.1);
		animState2->addTime(0.1);
	}
}
void AniManager_c::playAnim(){
	if (!animacionActivada){
		animacionActivada = true;
		animState = entidadOgre->getAnimationState("RunTop");
		animState->setLoop(true);
		animState->setEnabled(true);

		animState2 = entidadOgre->getAnimationState("RunBase");//RunTop
		animState2->setLoop(true);
		animState2->setEnabled(true);
	}
}
void AniManager_c::stopAnim(){
	animacionActivada = false;
	animState->setEnabled(false);
	animState2->setEnabled(false);
}