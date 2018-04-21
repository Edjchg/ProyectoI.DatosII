//
// Created by Edgar Chaves on 27/3/18.
//

#ifndef PROYECTO1_PARSER_H
#define PROYECTO1_PARSER_H

#include <string.h>
#include <string>
#include "json.hpp"
#include <list>
using namespace std;
class parser {
public:

    nlohmann::basic_json<> readfile(string);
    nlohmann::basic_json<> subReadFile(string);
    bool logError();
    bool miniParserCA(string);
    bool miniParserCC(string);
    bool imprimir();
    list<string> imprimirLista();
    string contarReferencias(string referencia, string bloque);




};


#endif //PROYECTO1_PARSER_H
