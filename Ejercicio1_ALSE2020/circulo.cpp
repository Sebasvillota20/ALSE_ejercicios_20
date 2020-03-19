#include "circulo.h"
#include <math.h>

Circulo::Circulo()
{

}

Circulo::Circulo(float r, float x, float y) {
    _r = r;
    setCoordX(x);
    setCoordY(y);
}

float Circulo::Perimetro(){
    float P;
    P = 2 * M_PI * _r;
    return P;
}

float Circulo::Area(){
    float A;
    A = _r * _r * M_PI;
    return A;
}

Circulo::~Circulo(){

}
