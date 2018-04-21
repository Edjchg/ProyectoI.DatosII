//
// Created by tony on 21/04/18.
//

#ifndef SERVIDOR_PARSERCHANGE_H
#define SERVIDOR_PARSERCHANGE_H

#include "json.hpp"
#include "ListaSimple.h"

using json = nlohmann::json;

class parserChange {
public:
    ListaSimple<std::string> convertToObject(json );
    ListaSimple<string> StringToJson(string);

    json toJson(string objetoJson);
};


#endif //SERVIDOR_PARSERCHANGE_H
