#include "cuadrado.h"
#include <math.h>

Cuadrado::Cuadrado()
{

}

Cuadrado::Cuadrado(float l, float x, float y) {
    _l = l;
    setCoordX(x);
    setCoordY(y);
}


float Cuadrado::Area(){
   float A;
   A = _l * _l;
   return A;
}

float Cuadrado::Perimetro(){
   float P;
   P = 4 * _l;
    return P;
}

Cuadrado::~Cuadrado(){

}
