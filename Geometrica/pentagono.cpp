#include "pentagono.h"
#include <math.h>

Pentagono::Pentagono()
{

}

Pentagono::Pentagono(float l, float x, float y){
    _l = l;
    setCoordX(x);
    setCoordY(y);
}

float Pentagono::Perimetro(){
    float P;
    P = 5 * _l;
    return P;
}

float Pentagono::Area(){
    float A;
    A = 1.72 * _l * _l;
    return A;
}

Pentagono::~Pentagono(){

}
