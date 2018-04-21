//
// Created by Edgar Chaves on 19/4/18.
//

#include "prueba.h"

using namespace std;

void prueba::prueba1(){
    NodoSimple <string> *primeroPtr;

    ListaSimple <string> listaSimple;
    listaSimple.insertarFinal("a","f","c","f","g", "");
    listaSimple.insertarFinal("a","f","c","f","g", "");
    cout<<"---------Lista Json----------"<<endl;
    cout<<listaSimple.ToJson()<<endl;



}