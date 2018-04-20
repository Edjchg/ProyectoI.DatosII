//
// Created by Edgar Chaves on 27/3/18.
//

#ifndef PROYECTO1_PARSER_H
#define PROYECTO1_PARSER_H

#include <string.h>
#include <string>
using namespace std;
class parser {
public:

    nlohmann::basic_json<> readfile(string);
    nlohmann::basic_json<> subReadFile(string);
    bool logError();
    bool miniParserCA(string);
    bool miniParserCC(string);



};


#endif //PROYECTO1_PARSER_H
