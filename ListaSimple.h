//
// Created by Edgar Chaves on 27/3/18.
//

#ifndef PROYECTO1_LISTASIMPLE_H
#define PROYECTO1_LISTASIMPLE_H

#include <iostream>
#include <jmorecfg.h>


#include "NodoSimple.h"

using namespace std;

template <typename TIPONODO>

class ListaSimple {
public:
    ListaSimple();
    ~ListaSimple();
    void instertarFrente(const TIPONODO &);
    void insertarFinal(const TIPONODO &);
    bool eliminarFrente();
    bool eliminarFinal();
    bool eliminarPosicion(const TIPONODO &);
    bool estaVacia()const;
    void imprimir () const;
    void insertarPosicion( const TIPONODO &, const TIPONODO &);
    void editarPosicion(const TIPONODO &, const TIPONODO &);

private:
    NodoSimple <TIPONODO> *primeroPtr;
    NodoSimple <TIPONODO> *ultimoPtr;
    NodoSimple <TIPONODO> *obtenerNuevoNodo(const TIPONODO &);

};
//Constructor
template <typename TIPONODO >
ListaSimple <TIPONODO> ::ListaSimple() : primeroPtr(0), ultimoPtr(0) {}


//Destructor
template <typename TIPONODO >
ListaSimple<TIPONODO>::~ListaSimple() {

    if (!estaVacia()){
        cout<< "Destruyendo Nodos ... \n";

        NodoSimple <TIPONODO> *actualPtr = primeroPtr;
        NodoSimple <TIPONODO> *tempPtr;

        while (actualPtr != 0){
            tempPtr = actualPtr;
            cout << tempPtr -> valor << "\n";
            actualPtr = actualPtr -> siguientePtr;
            delete tempPtr;
        }


    }
}
/*
 * Método que inserta un NodoSimple al inicio de la ListaSimple.
 */
template <typename TIPONODO>
void ListaSimple<TIPONODO>::instertarFrente(const TIPONODO &valor) {

    NodoSimple<TIPONODO> *nuevoPtr = obtenerNuevoNodo( valor );
    if (estaVacia()){
        primeroPtr = ultimoPtr = nuevoPtr;

    } else{
        nuevoPtr->siguientePtr= primeroPtr;
        primeroPtr = nuevoPtr;

    }
}

/*
 * Método que inserta un NodoSimple al final de la ListaSimple.
 */
template <typename TIPONODO>
void ListaSimple<TIPONODO>::insertarFinal(const TIPONODO &valor) {
    NodoSimple<TIPONODO> *nuevoPtr = obtenerNuevoNodo( valor );
    if (estaVacia()){
        primeroPtr = ultimoPtr = nuevoPtr;


    }else{

        ultimoPtr->siguientePtr= nuevoPtr;
        ultimoPtr = nuevoPtr;

    }
}
/*
 * Método que inserta un NodoSimple en la posición deseada en la ListaSimple.
 */
template <typename TIPONODO>
void ListaSimple<TIPONODO>::insertarPosicion(const TIPONODO & posicion, const TIPONODO & valor ) {
    cout<< "Dentro de insertar" << endl;

    NodoSimple<TIPONODO> *nuevoNodoPtr = obtenerNuevoNodo( valor );
    NodoSimple<TIPONODO> *tempPtr = primeroPtr;
    NodoSimple<TIPONODO> *temp2Ptr = primeroPtr->siguientePtr;

    if (estaVacia()){
        primeroPtr = ultimoPtr = nuevoNodoPtr;
    }else{
        int contador = 1;
        if(posicion == 1){
            nuevoNodoPtr->siguientePtr = primeroPtr;
            primeroPtr = nuevoNodoPtr;
        }
        while (temp2Ptr != nullptr){
            if(contador+1 == posicion and tempPtr->siguientePtr != nullptr and temp2Ptr->siguientePtr!= nullptr){
                nuevoNodoPtr->siguientePtr = temp2Ptr;
                tempPtr->siguientePtr = nuevoNodoPtr;

                contador++;

            }else{
                tempPtr = tempPtr->siguientePtr;
                temp2Ptr = temp2Ptr->siguientePtr;
                contador ++;
            }
        }


    }
}

/*
 * Método que elimina un NodoSimple al inicio de la ListaSimple.
 */

template <typename TIPONODO>
bool ListaSimple<TIPONODO>::eliminarFrente() {
    if(estaVacia()){
        return false;

    }else{
        NodoSimple <TIPONODO> *tempPtr = primeroPtr;
        if(primeroPtr == ultimoPtr){
            primeroPtr = ultimoPtr = 0;

        }else{
            primeroPtr = primeroPtr->siguientePtr;
            //valor = tempPtr->datos;
            delete tempPtr;
            return true;

        }
    }
}

/*
 * Método que elimina un NodoSimple en la posición deseada de la ListaSimple.
 */
template <typename TIPONODO>
bool ListaSimple<TIPONODO>::eliminarPosicion(const TIPONODO &valor) {
    if (estaVacia()){
        return false;
    }else{
        NodoSimple<TIPONODO> *tempPtr = primeroPtr;

        if (valor == 1){
            primeroPtr = primeroPtr->siguientePtr;
        }
        int contador = 1;
        while (tempPtr != nullptr){
            if(contador+1 == valor and tempPtr->siguientePtr!= nullptr){
                tempPtr->siguientePtr = tempPtr->siguientePtr->siguientePtr;
                contador ++;



            }else{
                contador++;
                tempPtr = tempPtr->siguientePtr;

            }

        }
        //delete tempPtr;

        return true;
    }
}
/*
 * Método que elimina un NodoSimple al final de la ListaSimple.
 */

template <typename TIPONODO>
bool ListaSimple<TIPONODO>::eliminarFinal() {
    if (estaVacia()){
        return false;
    }else{

        NodoSimple<TIPONODO> *tempPtr = ultimoPtr;

        if(primeroPtr==ultimoPtr){
            primeroPtr = ultimoPtr = 0;

        }else{
            NodoSimple <TIPONODO> *actualPtr= primeroPtr;
            while (actualPtr->siguientePtr != ultimoPtr) {
                actualPtr = actualPtr->siguientePtr;
            }


            ultimoPtr = actualPtr;
            actualPtr->siguientePtr= 0;

        }
        //valor = tempPtr->datos;
        delete tempPtr;
        return true;

    }
}

/*
 * Método que revisa con boolean si la lista está vacía revisando el estado del primer nodo.
 */
template <typename TIPONODO>
bool ListaSimple<TIPONODO>::estaVacia() const {
    return primeroPtr == 0;

}

template <typename TIPONODO>
NodoSimple<TIPONODO> *ListaSimple<TIPONODO>::obtenerNuevoNodo(const TIPONODO &valor) {
    return new NodoSimple<TIPONODO>(valor);

}
/*
 * Método que edita un NodoSimple en la posición deseada en la ListaSimple.
 */
template <typename TIPONODO>
void ListaSimple<TIPONODO>::editarPosicion (const TIPONODO & posicion, const TIPONODO &valor) {

    NodoSimple <TIPONODO> *tempPtr = primeroPtr;

    int contador = 1;

    while (tempPtr != nullptr){

        if (contador+1 == posicion){
            tempPtr->siguientePtr->setDatos(valor);
            contador ++;
            tempPtr = tempPtr->siguientePtr;

        }else{

            contador ++;
            tempPtr = tempPtr->siguientePtr;

        }

    }
}
/*
 * Método que recorre la ListaSimple para poder imprimir cada nodo.
 */
template <typename TIPONODO>
void ListaSimple <TIPONODO>::imprimir() const {
    NodoSimple<TIPONODO> *tempPtr = primeroPtr;

    while (tempPtr != nullptr){
        cout << tempPtr->valor << " ";
        tempPtr = tempPtr->siguientePtr;

    }
}



#endif //PROYECTO1_LISTASIMPLE_H
