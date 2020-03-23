#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <list>
#include <math.h>
#include "Polinomio.h"
#include "Termino.h"

using namespace std;

int main(int argc,char *argv[]){

    list<float> var;
    list<float>::iterator pos1;
    int t=0,i=1;
    float res;
    Polinomio term;

    ifstream archivo;
    string path;
    path=argv[1];
    archivo.open(path);

    if(archivo.is_open()){
        while(!archivo.eof()){
            getline(archivo, path);
            if(t==0){
                term= path;
                t++;
            }
            else{
                var.push_back( atof( path.c_str() ) );
            }
        }
    }

    archivo.close();
    pos1 = var.begin();
    Termino* temp;

    for( i ; i < var.size() ; i++ ){
        temp= term._polCabeza;
        while ( temp != NULL ){
            res = res + ( ( temp->getC() ) * ( pow( *pos1 , temp->getP() ) ) );
            temp = temp->getSiguiente();
        }
        cout<<"Polinomio evaluado en incognita #"<< i << ": " << res << endl;
        pos1 ++;
        res=0.;
    }

}
