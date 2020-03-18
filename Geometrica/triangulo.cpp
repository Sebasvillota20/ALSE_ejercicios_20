#include "triangulo.h"
#include <math.h>

Triangulo::Triangulo()
{

}

Triangulo::Triangulo(float b, float h, float x, float y){
    _b = b;
    _h = h;
    setCoordX(x);
    setCoordY(y);
}

float Triangulo::Area(){
    float A;
    A = _b * _h /2;
    return A;
}

float Triangulo::Perimetro(){
    float P;
    P = 3 * _b;
    return P;
}

Triangulo::~Triangulo(){

}
