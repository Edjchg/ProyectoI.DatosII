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

    NodoSimple (const TIPONODO &,const TIPONODO &,const TIPONODO &,const TIPONODO &,const TIPONODO &, const TIPONODO &);
    TIPONODO obtenerDatos()                               const;
    TIPONODO obtenerTipo()                                const;
    TIPONODO obtenerEspacioMemoria()                      const;
    TIPONODO obtenerCantidadReferencias()                 const;
    TIPONODO obtenerEtiqueta()                            const;
    TIPONODO obtenerNumeroEnMemoria()                     const;
    TIPONODO setDatos(const TIPONODO &);
    TIPONODO setTipo(const TIPONODO &);
    TIPONODO setEspacio(const TIPONODO &);
    TIPONODO setCantidadReferencias(const TIPONODO &);
    TIPONODO setEtiqueta(const TIPONODO &);
    TIPONODO setNumeroEnMemoria(const TIPONODO &);



    TIPONODO tipo;
    TIPONODO etiqueta;
    TIPONODO valor;
    TIPONODO cantidadReferencias;
    TIPONODO espacioEnMemoria;
    TIPONODO numeroEnMemoria;



    NodoSimple <TIPONODO> *siguientePtr;
};
template <typename TIPONODO>

NodoSimple<TIPONODO>::NodoSimple(const TIPONODO &tipo,const TIPONODO &etiqueta,const TIPONODO &valor,const TIPONODO &referencia,const TIPONODO &espacio, const TIPONODO & memoria):
        tipo(tipo), etiqueta(etiqueta),valor(valor),cantidadReferencias(referencia), espacioEnMemoria(espacio),numeroEnMemoria(memoria),  siguientePtr(0)
{

}

template <typename TIPONODO> TIPONODO NodoSimple<TIPONODO> ::obtenerDatos() const{
    return valor;

}

template <typename TIPONODO> TIPONODO NodoSimple<TIPONODO> :: obtenerTipo()                const {
    return tipo;
}

template <typename TIPONODO> TIPONODO NodoSimple <TIPONODO> ::obtenerEspacioMemoria()      const {
    return espacioEnMemoria;
}
template <typename TIPONODO> TIPONODO NodoSimple <TIPONODO> ::obtenerCantidadReferencias() const {
    return cantidadReferencias;
}

template <typename TIPONODO> TIPONODO NodoSimple <TIPONODO> ::obtenerEtiqueta() const {
    return etiqueta;
}

template <typename TIPONODO> TIPONODO NodoSimple<TIPONODO> :: obtenerNumeroEnMemoria() const {
    return numeroEnMemoria;
}


template <typename TIPONODO> TIPONODO NodoSimple<TIPONODO> ::setDatos(const TIPONODO & valor1) {
    valor = valor1;
}

template <typename TIPONODO> TIPONODO NodoSimple<TIPONODO> :: setTipo(const TIPONODO & tipo1){
    tipo = tipo1;
}

template <typename TIPONODO> TIPONODO NodoSimple<TIPONODO> ::setEspacio(const TIPONODO & espacio) {
    espacioEnMemoria = espacio;
}
template <typename TIPONODO> TIPONODO NodoSimple<TIPONODO> ::setCantidadReferencias(const TIPONODO & referencias) {
    cantidadReferencias = referencias;
}
template <typename TIPONODO> TIPONODO NodoSimple<TIPONODO> ::setEtiqueta(const TIPONODO & etiqueta1) {
    etiqueta = etiqueta1;
}

template <typename TIPONODO> TIPONODO NodoSimple<TIPONODO> :: setNumeroEnMemoria(const TIPONODO & numeroEnMemoria1){
    numeroEnMemoria = numeroEnMemoria1;
}

#endif //PROYECTO1_NODOSIMPLE_H
