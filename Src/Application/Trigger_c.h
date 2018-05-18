#pragma once
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include "Component.h"
#include "Entidad.h"
class Trigger_c : public Component
{
public:
	Trigger_c(Entidad* _ent, Entidad* _entEne, btDynamicsWorld* _bulletWorld,
        float _profundo, float _ancho, float _alto);
	Trigger_c(){}
    ~Trigger_c();
    void Update();
    btCollisionObject * getTrigger(){
        return trigger;
    }
    void actualizarPos(float x, float y, float z);
	Entidad* getFather(){
		return entPadre;
	}
	//void activaPadre();
private:
	Entidad* ent;
	Entidad* entPadre;
    btDynamicsWorld* bulletWorld;
    float alto, ancho, profundo;
    btTransform pTransform;
    btCollisionShape* shape;
    btDefaultMotionState* motionState;
    btCollisionObject * trigger;
};

