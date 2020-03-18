#ifndef CUADRADO_H
#define CUADRADO_H
#include "geometrica.h"


class Cuadrado: public Geometrica
{
public:

    Cuadrado(float l, float x, float y); //constructor para asignar datos
    float Area();
    float Perimetro();
    void setLado(float l){_l = l;}
    float getLado(){return _l;}
    ~Cuadrado();

private:
    float _l;
    Cuadrado();
};

#endif // CUADRADO_H
