#include <iostream>
#include <queue>
#include <ctype.h>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main(int argc,char *argv[]){

   queue<float> colac,colae,cola,csuma,num;

   int c=0,i=0,con=0;
   float suma=0.,d=0.,d1=0.,term=0.,ti=0.,error;

   ifstream (archivo);
   string path;
   path=argv[1];
   archivo.open(path);

   if(archivo.is_open()){
       while(!archivo.eof()){
            getline(archivo,path);
            if(c==1){
                num.push(atof(path.c_str()));
                con=con +1;
            }
            if(c==0){
                int n = path.length();
                char ch[n + 1];
                strcpy(ch, path.c_str());
                //cout<<n<<endl;
                if(ch[0]=='-'){
                    i=i+1;
                }
                while(i<(n)){
                    if(n==1&&ch[i]=='x'){
                        colac.push(1);
                        colae.push(1);
                        i=n+1;
                    }
                    if(n==1&&ch[i]!='x'){
                        d=ch[i]-'0';
                        cola.push(d);
                        i=n+1;
                    }
                    //x
                    if(ch[i]=='x'&&(ch[i+1]=='+'|ch[i+1]=='-'|ch[i-1]=='+'|ch[i-1]=='-')){
                        if(ch[i-1]=='-'){
                            colac.push(-1);
                            colae.push(1);
                        }else {
                            colac.push(1);
                            colae.push(1);
                        }
                        i=i+2;
                        //cout<<"1"<<endl;
                    }//x^2
                    if(ch[i]=='x'&&ch[i+1]=='^'){
                        if(ch[i-1]=='-'){
                            d=ch[i+2]-'0';
                            colac.push(-1);
                            colae.push(d);
                        }else {
                            d=ch[i+2]-'0';
                            colac.push(1);
                            colae.push(d);
                        }
                        i=i+4;
                        //cout<<"2"<<endl;
                    }//2x
                    if(ch[i]!='x'&&ch[i+1]=='x'&&(ch[i+2]=='+'|ch[i+2]=='-'|ch[i+2]==' ')){
                        if(ch[i-1]=='-'){
                            d=ch[i]-'0';
                            colac.push(-d);
                            colae.push(1);
                        }else {
                            d=ch[i]-'0';
                            colac.push(d);
                            colae.push(1);
                        }
                        i=i+3;
                        //cout<<"3"<<endl;
                    }//2x^2
                    if(ch[i]!='x'&&ch[i+2]=='^'){
                        if(ch[i-1]=='-'){
                            d=ch[i]-'0';
                            d1=ch[i+3]-'0';
                            colac.push(-d);
                            colae.push(1);
                        }else {
                            d=ch[i]-'0';
                            d1=ch[i+3]-'0';
                            colac.push(d);
                            colae.push(d1);
                        }
                        i=i+5;
                        //cout<<"4"<<endl;
                    }//2
                    if(ch[i]!='x'&&(ch[i+1]=='+'|ch[i+1]=='-'|ch[i-1]=='+'|ch[i-1]=='-')){
                        if(ch[i-1]==0){
                            d=ch[i]-'0';

                            cola.push(-d);
                        }else {
                            d=ch[i]-'0';
                            ti=ti+d;
                        }
                        i=i+2;
                        //cout<<"5"<<endl;
                    }


                }

                c=1;
            }

        }
    }
    archivo.close();

    queue<float> colacr,colaer,numr;
    while(!num.empty()){
        suma=0;
        term=0;
        while(!colac.empty()){
            term=pow(num.front(),colae.front());
            suma=suma+term*colac.front()+ti;
            colaer.push(colae.front());
            colae.pop();
            colacr.push(colac.front());
            colac.pop();
        }
        while(!colacr.empty()){
            colae.push(colaer.front());
            colaer.pop();
            colac.push(colacr.front());
            colacr.pop();
        }

        numr.push(num.front());
        num.pop();
        csuma.push(suma);
    }
    suma=0;
    while(!numr.empty()){
        cout<<"con X igual a: "<<numr.front()<<"el polinomio vale: "<<csuma.front()<<endl;
        suma=suma+csuma.front();
        error=csuma.front();
        csuma.pop();
        numr.pop();
    }
    cout<<"el promedio de los valores del polinomio es de: "<<(suma-error)/(con-1)<<endl;

return 0;
}

