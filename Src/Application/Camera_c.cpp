#include "Camera_c.h"

enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};

Camera_c::Camera_c(Entidad * ent)
{
	motorGrafico = MotorGrafico::getInstancia();
	entidad = ent;

	// creamos el nodo
	camNode = motorGrafico->getSceMgr()->getRootSceneNode()->createChildSceneNode();

	// create the camera
	cam = motorGrafico->getSceMgr()->createCamera("CamJuego");
	cam->setNearClipDistance(0.1); //esto antes era 1
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	cam->setQueryFlags(MY_QUERY_IGNORE);

	// unimos a la ventana de juego
	vp = motorGrafico->getWindow()->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(150, 150, 150));
}


Camera_c::~Camera_c()
{
	motorGrafico->getSceMgr()->destroyCamera("CamJuego");
	motorGrafico->getSceMgr()->getRootSceneNode()->removeAndDestroyChild(camNode);
	//delete camNode;
	motorGrafico->getWindow()->removeAllViewports();
}

