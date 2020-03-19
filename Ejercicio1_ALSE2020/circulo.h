#ifndef CIRCULO_H
#define CIRCULO_H
#include "geometrica.h"

class Circulo: public Geometrica
{
public:

    Circulo(float r, float x, float y); //constructor para asignar datos
    float Area(); //Encontrar Area
    float Perimetro(); //Encontrar Perimetro
    void setRadio(float r){_r = r;}
    float getRadio(){return _r;}
    ~Circulo();

private:
    float _r;
    Circulo();
};

#endif // CIRCULO_H
