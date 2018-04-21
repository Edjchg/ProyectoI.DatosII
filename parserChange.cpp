//
// Created by tony on 21/04/18.
//


#include "parserChange.h"
#include "json.hpp"
#include "ListaSimple.h"
using json = nlohmann::json;

ListaSimple<string> listaSimple;
/**
 * Convierte el json a objeto linea.
 * @param objeto
 */
ListaSimple<string> parserChange::convertToObject(json objeto){



    struct nodo {
        std::string tipo;
        std::string etiqueta;
        std::string valor ;
        std::string cantidadReferencias;
        std::string espacioEnMemoria;
        std::string numeroEnMemoria;
    };
    for (int posicion = 0; posicion < sizeof(objeto); posicion++){
        listaSimple.insertarFinal(objeto["tipo"].get<std::string>(),objeto["etiqueta"].get<std::string>(),
                                  objeto["valor"].get<std::string>(),objeto["cantidadReferencias"],objeto["espacioEnMemoria"].get<std::string>(),
                                  objeto["numeroEnMemoria"].get<std::string>());
        objeto = NULL;
    }

    return listaSimple;
}

json parserChange::toJson(string objetoJson) {
    auto j2 = R"(objetoJson)"_json;


    return j2;

}
