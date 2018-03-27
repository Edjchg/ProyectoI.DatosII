//
// Created by Edgar Chaves on 27/3/18.
//

#ifndef PROYECTO1_NODOSIMPLE_H
#define PROYECTO1_NODOSIMPLE_H

#include "NodoSimple.h"
#include <iostream>

template < typename TIPONODO > class ListaSimple;
template < typename TIPONODO >

class NodoSimple {

    friend class ListaSimple< TIPONODO >;

public:

    NodoSimple (const TIPONODO &);
    TIPONODO obtenerDatos() const;
    TIPONODO setDatos(const TIPONODO &);


    TIPONODO datos;
    NodoSimple <TIPONODO> *siguientePtr;
};
template <typename TIPONODO>

NodoSimple<TIPONODO>::NodoSimple(const TIPONODO &info): datos(info), siguientePtr(0)
{

}

template <typename TIPONODO> TIPONODO NodoSimple<TIPONODO> ::obtenerDatos() const{
    return datos;

}

template <typename TIPONODO> TIPONODO NodoSimple<TIPONODO> ::setDatos(const TIPONODO & valor) {
    datos = valor;
}

#endif //PROYECTO1_NODOSIMPLE_H
