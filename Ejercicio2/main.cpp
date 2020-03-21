#include <QCoreApplication>
#include "triangulo.h"
#include "cuadrado.h"
#include "pentagono.h"
#include "circulo.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum Fig {
  circ,
  cuadr,
  rectan,
  pentag,
  triang
};

int main(int argc, char *argv[])
{
vector <string> a;
    if(argc != 2){
        std::cout << "El programa se usa así:" << std::endl;
        std::cout << "polynom path_to_file" << std::endl;
        std::cout << "Se debe indicar la ruta al archivo a leer" << std::endl;
        return 1;
    }

    string path;
    path = argv[1];
    ifstream archivo;
    archivo.open(path);
    std::cout << "Se abrirá el archivo: " << path << std::endl;

if(archivo.is_open()){
    // Aquí va el codigo que se va a hacer para leer el archivo
    while(!archivo.eof()){
        getline(archivo, path);
        a.push_back(path.c_str());
    }
}
archivo.close();

//a.push_back("cu 2 lado 0 xc 0 xy");
//a.push_back("cu 1 lado 0 xc 1 xy");
//a.push_back("p 3 lado 0 xc 2 xy");
//a.push_back("t 4.5 base 2.5 altura 1 xc 1 xy");
//a.push_back("p 2.5 lado 2 xc 3 xy");
//a.push_back("ci 22.2 radio 1 xc 2 xy");
//a.push_back("ci 3 radio 2 xc 0 xy");

string ci="";
string term;
size_t posM, posm, posT1, posT2, found;
posT1 = posT2 = 0;
string::size_type sz;
Geometrica* g=0;
vector<Geometrica*> Data;

 for(int i=0; i<a.size(); i++){
     ci=a.at(i);
     size_t one = ci.find("ci");
     size_t two = ci.find("t");
     size_t three = ci.find("p");
     size_t four = ci.find("cu");

     if( one != string::npos){

         posM = ci.find("ci", posT1 + 1 );
         posm = ci.find("radio", posT1 + 1);
         if( posM != string::npos && posm != string::npos )
             posT2 = min( posM, posm );
         else if( posM == string::npos )
             posT2 = posm;
         else
             posT2 = posM;
        // cout << posM << "  "<<posm <<"  " <<posT1 << "  " <<posT2;
         term = ci.substr( posT1+3, (posT2-1)-(posT1+2) );
         //cout <<endl << term <<endl;
         float r = std::stof (term,&sz);
         //cout << r;
         g = new Circulo(r, 0, 0);
         Data.push_back( g );
         posm= posM = posT2= posT1=0,sz=0,r=0;
     }
     if( two != string::npos)
     {
         posM = ci.find("t", posT1 + 1 );
         posm = ci.find("base", posT1 + 1);
         if( posM != string::npos && posm != string::npos )
             posT2 = min( posM, posm );
         else if( posM == string::npos )
             posT2 = posm;
         else
             posT2 = posM;
         //cout << posM << "  "<<posm <<"  " <<posT1 << "  " <<posT2;
             term = ci.substr( posT1+2, (posT2-1)-(posT1+1) );
         //cout <<endl << term <<endl;
         float b = std::stof (term,&sz);
         posm = posM = posT2 = posT1 = 0;


         posM = ci.find("base", posT1 + 1 );
         posm = ci.find("altura", posT1 + 1);
         if( posM != string::npos && posm != string::npos )
             posT2 = min( posM, posm );
         else if( posM == string::npos )
             posT2 = posm;
         else
             posT2 = posM;
         //cout << posM << "  "<<posm <<"  " <<posT1 << "  " <<posT2 <<endl;
             term = ci.substr( posM+5, (posm-1)-(posM+4) );
         //cout <<endl << term <<endl;
         float h = std::stof (term,&sz);
         //cout << r;
         g = new Triangulo(b,h,0,0);
         Data.push_back( g );

     }
     if( three != string::npos)
     {

         posM = ci.find("p", posT1 + 1 );
         posm = ci.find("lado", posT1 + 1);
         if( posM != string::npos && posm != string::npos )
             posT2 = min( posM, posm );
         else if( posM == string::npos )
             posT2 = posm;
         else
             posT2 = posM;
         //cout << posM << "  "<<posm <<"  " <<posT1 << "  " <<posT2;
             term = ci.substr( posT1+2, (posT2-1)-(posT1+1) );
         //cout <<endl << term <<endl;
         posm= posM = posT2= posT1=0;
         float l = std::stof (term,&sz);
         //cout << r;
         g = new Pentagono(l,0,0);
         Data.push_back( g );
     }
     if( four != string::npos)
     {

         posM = ci.find("cu", posT1 + 1 );
         posm = ci.find("lado", posT1 + 1);
         if( posM != string::npos && posm != string::npos )
             posT2 = min( posM, posm );
         else if( posM == string::npos )
             posT2 = posm;
         else
             posT2 = posM;
         //cout << posM << "  "<<posm <<"  " <<posT1 << "  " <<posT2;
             term = ci.substr( posT1+3, (posT2-1)-(posT1+2) );
         //cout <<endl << term <<endl;
         posm= posM = posT2= posT1=0;
         float l = std::stof (term,&sz);
         //cout << r;
         g = new Cuadrado(l,0,0);
         Data.push_back( g );
     }
 }

 for (int i = 0; i < Data.size(); i++){
     cout << "Figura(" << i << "): "<< "Perímetro: " << Data.at(i)->Perimetro() << " y área: " << Data.at(i)->Area() << endl;
 }

 for (int i = 0; i < Data.size(); i++){
     delete Data.at(i);
 }
 return 0;

}
