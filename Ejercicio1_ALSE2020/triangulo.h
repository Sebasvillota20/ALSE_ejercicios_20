#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "geometrica.h"

class Triangulo: public Geometrica
{
public:

    Triangulo(float b, float h, float x, float y); //constructor para asignar datos
    float Area();
    float Perimetro();
    void setBase(float b){_b = b;}
    float getBase(){return _b;}
    void setAltura(float h){_h = h;}
    float getAltura(){return _h;}
    ~Triangulo();

private:
    float _b;
    float _h;
    Triangulo();
};

#endif // TRIANGULO_H
