#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

template<class T>
class punto{
public:
    T x, y;
    punto(T x = 0, T y = 0):x(x), y(y){}
};

template<class T>
class nodo{
public:
    punto<T> mPunto;
    nodo<T> *SE;
    nodo<T> *NE;
    nodo<T> *NW;
    nodo<T> *SW;
    nodo(punto<T> p){
        SE = nullptr;
        NE = nullptr;
        NW = nullptr;
        SW = nullptr;
        mPunto = p;
    }
};

template<class T>
class quadPointTree{
public:
    vector<punto<T>> vectorinResultados;
    nodo<T> *raiz;
    nodo<T> **ptrQ;
    
    quadPointTree(){    raiz = nullptr; }
    
    bool contiene(punto<T>puntoInicial, punto<T>puntoFinal, punto<T> mPunto){
        if((((puntoInicial.x <= mPunto.x && mPunto.x <= puntoFinal.x)  ||  (puntoInicial.x >= mPunto.x && mPunto.x >= puntoFinal.x) ) &&    ((puntoInicial.y <= mPunto.y && mPunto.y <= puntoFinal.y)  ||  (puntoInicial.y >= mPunto.y && mPunto.y >= puntoFinal.y) ) ))
            return true;
        return false;
    }
    void calcularUbicacion(punto<T> puntoA, punto<T> puntoB, nodo<T>**&q ){ //puntoB es el quiero insertar
        if(puntoB.x < puntoA.x && puntoB.y> puntoA.y)           q = &(*q)->NW;
        else if(puntoB.x < puntoA.x && puntoB.y< puntoA.y)      q = &(*q)->SW;
        else if(puntoB.x > puntoA.x && puntoB.y> puntoA.y)      q = &(*q)->NE;
        else                                                    q = &(*q)->SE; //(puntoB.x > puntoA.x && puntoB.y < puntoA.y)
    }
    
    void insertar(punto<T> p){
        if(raiz==nullptr){
            ptrQ    = &raiz;
            raiz = new nodo<T>(p);
            return;
        }
        if((*ptrQ)==nullptr){  // calculare q hasta que sea null y recien creara un nodo //q se inserta al final
            (*ptrQ) = new nodo<T>(p);
            ptrQ = &raiz;
            return;
        }
        else{ // para mover q a su ubicacion y calcular donde estara (NE,NW,SE,SW)
            calcularUbicacion( (*ptrQ)->mPunto,p , ptrQ);
            insertar(p);
            return;
        }
    }
    
    bool busquedaPunto(punto<T> puntoB){
        if( (*ptrQ) ){
            if( (*ptrQ)->mPunto.x == puntoB.x && (*ptrQ)->mPunto.y == puntoB.y ){
                cout<<"Punto encontrado : "<<(*ptrQ)->mPunto.x<<","<<(*ptrQ)->mPunto.y<<endl<<endl;
                return true;
            }
            else{
                calcularUbicacion( (*ptrQ)->mPunto, puntoB, ptrQ);
                busquedaPunto(puntoB);
            }
        }
        return true;
    }
    
    void busquedaRecursivaRango(nodo<T>* &p,    punto<T> puntoIni, punto<T> puntoFin){
        if(p==nullptr) return;
        else{
            if( contiene(puntoIni, puntoFin, (p)->mPunto) )       vectorinResultados.push_back( (p)->mPunto);
        }
        busquedaRecursivaRango((p)->SE, puntoIni, puntoFin);
        busquedaRecursivaRango((p)->NE, puntoIni, puntoFin);
        busquedaRecursivaRango((p)->SW, puntoIni, puntoFin);
        busquedaRecursivaRango((p)->NW, puntoIni, puntoFin);
        
    }
    
    void busquedaRango(punto<T> puntoIni, punto<T> puntoFin)    {
        nodo<T> **p = &raiz;
        busquedaRecursivaRango(*p, puntoIni, puntoFin );
    }
    
    void imprimirBusquedaPorRango(){
        cout<<"Busqueda por Rango"<<endl;
        for(int i=0;i<vectorinResultados.size();i++)    cout<<"("<<vectorinResultados[i].x<<","<<vectorinResultados[i].y<<")"<<endl;
    }
};

int contador=0;
vector<punto<long> > nuevos;

void llenarArchivo(){
    std::vector<int> v;
    ofstream fs("/Users/shadowm/Documents/puntosQuadPointTree.txt");
    srand(time(NULL));
    int i = 0;
    while(i < 10500){
        int num = rand() % 100500 + (-50250);
        string n = std::to_string(num);
        fs << n << '\t';
        i++;
    }
   	fs.close();
}
int convertir_letra_numero(char* a){
    istringstream buffer(a);
    int value;
    buffer >> value;
    return value;
}


void leerArchivo(string direccion){
    vector<int> tem;
    ifstream fe(direccion);
    char cadena[5];
    while(!fe.eof()) {
        fe >> cadena;
        tem.push_back(convertir_letra_numero(cadena));
   	}
   	fe.close();
   	for(int i = 0; i < tem.size(); i+=2){
        punto<long> p1(tem[i],tem[i+1]);
        nuevos.push_back(p1);
        contador++;
    }
}

int main(){
    quadPointTree<double> arbolito;
    arbolito.insertar(punto<double>(5,7));
    arbolito.insertar(punto<double>(6,8));
    arbolito.insertar(punto<double>(9,10));
    arbolito.insertar(punto<double>(1,3));
    arbolito.insertar(punto<double>(2,4));
    
    arbolito.busquedaPunto( punto<double> (5,7) );
    arbolito.busquedaRango( punto<double>(-23,-23),punto<double>(23,23) ); // pendiente positiva
//    arbolito.busquedaRango( punto<double>(-3,23),punto<double>(23,-23) ); // pendiente negativa
    arbolito.imprimirBusquedaPorRango();
    
    
//descomentar para llenar un texto, leerlo y buscar puntos;
    
////    llenarArchivo();
//    leerArchivo("/Users/shadowm/Documents/puntosQuadPointTree.txt");
//
//    quadPointTree<long> arbolito;
//    for (int i=0;i<contador;i++){
//        arbolito.insertar(punto<long>(nuevos[i].x, nuevos[i].y));
//    }
//    arbolito.busquedaPunto(punto<long>(-27096,-27877));
//    
////    arbolito.busquedaRango(punto<long>(-27096,-27877), punto<long>(0,0)); // pendiente positiva
//    arbolito.busquedaRango(punto<long>(-20000,30000), punto<long>(20000,-30000)); // pendiente negativa
//    arbolito.imprimirBusquedaPorRango();
    return 0;
}

