//
// Created by Edgar Chaves on 27/3/18.
//

#ifndef PROYECTO1_LISTASIMPLE_H
#define PROYECTO1_LISTASIMPLE_H

#include <iostream>
#include <jmorecfg.h>


#include "NodoSimple.h"
#include <list>

#include "json.hpp"

using nlohmann::json;
using namespace std;



template <typename TIPONODO>

class ListaSimple {
public:
    ListaSimple();
    ~ListaSimple();
    void instertarFrente(const TIPONODO &, const TIPONODO &, const TIPONODO &, const TIPONODO & ,const TIPONODO &, const TIPONODO &);
    void insertarFinal(const TIPONODO &,const TIPONODO &,const TIPONODO &,const TIPONODO &,const TIPONODO &, const TIPONODO & );
    bool eliminarFrente();
    bool eliminarFinal();
    bool eliminarPosicion(const TIPONODO &);
    bool estaVacia()const;
    void imprimir () const;
    void insertarPosicion( const TIPONODO &, const TIPONODO &);
    void editarPosicion(const TIPONODO &, const TIPONODO &);
    json ToJson();
    list<string> comparar(list<string> list);

private:
    NodoSimple <TIPONODO> *primeroPtr;
    NodoSimple <TIPONODO> *ultimoPtr;
    NodoSimple <TIPONODO> *obtenerNuevoNodo(const TIPONODO &,const TIPONODO &,const TIPONODO &,const TIPONODO &,const TIPONODO &, const TIPONODO &);

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


/**
 * Método que inserta un NodoSimple al inicio de la ListaSimple.
 * @tparam TIPONODO
 * @param tipo
 * @param etiqueta
 * @param valor
 * @param referencia
 * @param espacio
 */
template <typename TIPONODO>
void ListaSimple<TIPONODO>::instertarFrente(const TIPONODO &tipo,const TIPONODO &etiqueta, const TIPONODO &valor,
                                            const TIPONODO &referencia, const TIPONODO &espacio, const TIPONODO &memoria) {

    NodoSimple<TIPONODO> *nuevoPtr = obtenerNuevoNodo( tipo ,etiqueta, valor, referencia, espacio, memoria );
    if (estaVacia()){
        primeroPtr = ultimoPtr = nuevoPtr;

    } else{
        nuevoPtr->siguientePtr= primeroPtr;
        primeroPtr = nuevoPtr;

    }
}

/**
 * @brief Método que inserta un NodoSimple al final de la ListaSimple.
 * @tparam TIPONODO
 * @param tipo
 * @param etiqueta
 * @param valor
 * @param referencia
 * @param espacio
 */


template <typename TIPONODO>

void ListaSimple<TIPONODO>::insertarFinal(const TIPONODO &tipo, const TIPONODO &etiqueta, const TIPONODO &valor,
                                          const TIPONODO &referencia, const TIPONODO &espacio, const TIPONODO &memoria ) {
    NodoSimple<TIPONODO> *nuevoPtr = obtenerNuevoNodo(tipo,etiqueta, valor,referencia,espacio, memoria );
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

/*
template <typename TIPONODO>
void ListaSimple<TIPONODO>::insertarPosicion(const TIPONODO & posicion, const TIPONODO &valor ) {
    cout<< "Dentro de insertar" << endl;

    NodoSimple<TIPONODO> *nuevoNodoPtr = obtenerNuevoNodo( tipo, etiqueta,valor, referencia, espacio );
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
*/

/**
 * @brief Método que elimina un NodoSimple al inicio de la ListaSimple.
 * @tparam TIPONODO
 * @return
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
 *
 */

/**
 * @brief Método que elimina un NodoSimple en la posición deseada de la ListaSimple.
 * @tparam TIPONODO
 * @param valor
 * @return
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


/**
 * @brief Método que elimina un NodoSimple al final de la ListaSimple.
 * @tparam TIPONODO
 * @return
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


/**
 * @brief Método que revisa con boolean si la lista está vacía revisando el estado del primer nodo.
 * @tparam TIPONODO
 * @return
 */
template <typename TIPONODO>
bool ListaSimple<TIPONODO>::estaVacia() const {
    return primeroPtr == 0;

}

/**
 *
 * @tparam TIPONODO
 * @param tipo
 * @param etiqueta
 * @param valor
 * @param referencia
 * @param espacio
 * @return
 */

template <typename TIPONODO>
NodoSimple<TIPONODO> *ListaSimple<TIPONODO>::obtenerNuevoNodo(const TIPONODO &tipo,const TIPONODO &etiqueta,
                                                              const TIPONODO &valor,const TIPONODO &referencia,const TIPONODO &espacio, const TIPONODO &memoria) {
    return new NodoSimple<TIPONODO>(tipo, etiqueta,valor, referencia, espacio, memoria);

}


/**
 * @brief Método que edita un NodoSimple en la posición deseada en la ListaSimple.
 * @tparam TIPONODO
 * @param posicion
 * @param valor
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

/**
 * @brief Método que recorre la ListaSimple para poder imprimir cada nodo.
 * @tparam TIPONODO
 */
template <typename TIPONODO>
void ListaSimple <TIPONODO>::imprimir() const {
    NodoSimple<TIPONODO> *tempPtr = primeroPtr;

    while (tempPtr != nullptr){
        cout << tempPtr->valor << endl;
        cout << tempPtr->valor << " ";
        cout << tempPtr->etiqueta << " ";
        cout << tempPtr->tipo << " ";
        tempPtr = tempPtr->siguientePtr;

    }
}
template <typename TIPONODO>
list<string> ListaSimple <TIPONODO>::comparar (list<string> lista) {
    if (estaVacia()){
        return lista;
    }else{
        NodoSimple <TIPONODO> *tempPtr = primeroPtr;
      while (tempPtr != nullptr){
          list<string>::iterator it = lista.begin();
          while ( it != lista.end() ) {
              if (*it != tempPtr->etiqueta) {
                  it++;
              } else {
                  list<string>::iterator ite = it;
                  lista.insert(it, tempPtr->valor);
                  it++;
                  lista.erase(ite);
              }
          }

          tempPtr = tempPtr->siguientePtr;



      }
    }
    return lista;
}

template <typename TIPONODO>
json ListaSimple <TIPONODO>::ToJson(){
    string tipo,etiqueta,valor;


        struct nodo {
            std::string tipo;
            std::string etiqueta;
            std::string valor ;
            std::string referencias;
            std::string espacio;
        };



    NodoSimple<TIPONODO> *temptr = primeroPtr;
    json tipoJ;
    json etiquetaJ;
    json valorJ;

    json lista;
    json total;



    while (temptr != nullptr){
        tipo = temptr->tipo;
        etiqueta = temptr->etiqueta;
        valor = temptr->valor;



        lista["tipo"] = temptr->obtenerTipo();
        lista["etiqueta"] = temptr->obtenerEtiqueta();
        lista["valor"] = temptr->obtenerDatos();
        lista["cantidadReferencias"] = temptr->obtenerCantidadReferencias();
        lista["espacioEnMemoria"] = temptr->obtenerEspacioMemoria();
        lista["numeroEnMemoria"] = temptr->obtenerNumeroEnMemoria();

        //json array_not_object = json::array({lista});



        total.push_back(lista);



        temptr = temptr->siguientePtr;


    }


    //cout<<total<<endl;
    return total;
}


#endif //PROYECTO1_LISTASIMPLE_H
