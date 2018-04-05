#ifndef OBJETO_H
#define OBJETO_H
#include "Entidad.h"
class Objeto : Entidad
{
public:
    Objeto(std::string id);
    ~Objeto();
    std::string getID(){ return identificador; }
private:
    std::string identificador;
};
#endif
