#ifndef GEOMETRICA_H
#define GEOMETRICA_H


class Geometrica
{
public:
    virtual float Area();
    virtual float Perimetro();
    void setCoordX(float x){_cx = x;}
    float getCoordX(){return _cx;}
    void setCoordY(float y){_cy = y;}
    float getCoordY(){return _cy;}
    Geometrica();
    ~Geometrica();

private:

       float _cx;
       float _cy;
       float _angulo;
};

#endif // GEOMETRICA_H
