#include "Escenas.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace Ogre;
enum QueryFlags {
	MY_QUERY_IGNORE = 1 << 1,
	MY_QUERY_INTERACT = 1 << 0
};
Escenas::Escenas()
{

}

Escenas::~Escenas()
{
	for (int i = 0; i < entidades.size(); i++)
		delete entidades[i];
	inputcomp_->removeKeyListener(inputcomp_);
	inputcomp_->removeMouseListener(inputcomp_);

	scnMgr->getRootSceneNode()->removeAndDestroyAllChildren();
}

