#include <QCoreApplication>
#include "circulo.h"
#include "cuadrado.h"
#include "triangulo.h"
#include "pentagono.h"
#include <vector>
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
    vector<Geometrica*> Data;
    vector<Geometrica*>:: iterator iter;
    int fig = 0;
    float r=0, l=0, b=0, h=0, x=0, y=0;
    char Acep;
    Acep= 's';
    Geometrica* g=0;

    while(true){
        cout << "Que figura quisiera calcular:" << endl << "Circulo(1), Cuadrado(2), Triangulo(3) o Pentagono(4)" << endl;
            cin >> fig;
            switch (fig) {
            case 1:
                cout << "Ingrese el radio: " << endl;
                cin >> r;
                cout << endl;
                cout << "Ingrese las coordenadas de la figura:";
                cin >> x;
                cin >> y;
                g = new Circulo(r, x, y);
                break;
            case 2:
                cout << "Ingrese el lado: " << endl;
                cin >> l;
                cout << endl;
                cout << "Ingrese las coordenadas de la figura:";
                cin >> x;
                cin >> y;
                g = new Cuadrado( l, x, y);
                break;
            case 3:
                cout << "Ingrese el base: " << endl;
                cin >> b;
                cout << "ahora la altura: ";
                cin >> h;
                cout << endl;
                cout << "Ingrese las coordenadas de la figura:";
                cin >> x;
                cin >> y;
                g = new Triangulo( b, h, x, y);
                break;
            case 4:
                cout << "ingrese el lado" << endl;
                cin >> l;
                cout << endl;
                cout << "Ingrese las coordenadas de la figura:";
                cin >> x;
                cin >> y;
                g = new Pentagono(l, x, y);
                break;
            default:
                cout << "Por favor lea bien" << endl;
                break;
            }
            Data.push_back( g );
            cout << "¿Desea ingresar mas figuras? si:(s) no:(n)";
            cin >> Acep;
    if (Acep != 's'){ break;}

    }

for( iter =begin(Data) ; iter != end(Data) ; iter++){
    cout << "Figura" << ": "<< "Perímetro: " << (*iter)->Perimetro() << " y área: " << (*iter)->Area() << endl;
}

    return 0;
}
