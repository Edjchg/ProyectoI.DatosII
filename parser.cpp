//
// Created by Edgar Chaves on 27/3/18.
//

#include "parser.h"
#include <fstream>
#include <iostream>
#include "ListaSimple.h"
#include "checker.h"
#include "json.hpp"
#include <list>

using namespace std;

string file = "/Users/edgarchaves/Desktop/C!.txt";

ListaSimple <string> listaLineas;


list<string> listaLineasCopia;
list<string> list1;
bool imprimire = false;
bool logE = true;

string parser::contarReferencias(string referencia, string bloque) {
    string palabra;
    int cont = -1;
    string resultado;
    for (int posicion = 0; posicion <= bloque.length(); posicion++) {
        if (bloque[posicion] == '{' or bloque[posicion] == ';' or bloque[posicion] == '\n' or bloque[posicion] == ' ') {
            palabra = palabra;
            if(palabra == referencia){
                cont += 1;
                palabra = "";
            } else {
                palabra = "";
            }
        } else {
            palabra += bloque[posicion];
        }
    }
    return to_string(cont);
}


/**
 * @brief Lee y verifica que los corchetes estén correctos.
 * @param expresion
 */
json parser::readfile(string expresion) {


    json total;
    cout << expresion << endl;

    string bloque;

    bool corcheteAbierto = FALSE;
    bool corcheteCerrado = FALSE;

    bool corchetesPequenosA = FALSE;
    bool corchetesPequenosC = FALSE;

    int corchetesGrandes = 0;

    int bloqueTexto = 1;
    int contador = 1;

    char lista[3];
    char ListaGrande[50];




    for (int posicion = 0; posicion <= expresion.length(); posicion++) {


        /*
         * Parte del parser que lee específicamente al inicio de la caja de texto.
         */


            if (expresion[posicion] == '{' and corcheteAbierto == FALSE and corcheteCerrado == FALSE and
                corchetesGrandes == 0) {


                corcheteAbierto = TRUE;
                corchetesGrandes++;

            } else if (expresion[posicion] == '{' and corcheteAbierto == TRUE and corchetesGrandes == 1
                       and corchetesPequenosA == FALSE) {

                corchetesPequenosA = TRUE;


            } else if (expresion[posicion] == '}' and corcheteAbierto == TRUE and
                       corchetesGrandes < 2 and corcheteCerrado == FALSE and corchetesPequenosA == TRUE and corchetesPequenosC == FALSE) {


                corchetesPequenosC = TRUE ;

            } else if (expresion[posicion] == '{' and corcheteAbierto == TRUE and corchetesPequenosA == TRUE) {
                logE = false;
                cout << "Sintax error, '}' is missing." << endl;
                break;

            } else if (expresion[posicion] == '}' and corcheteAbierto == TRUE and corcheteCerrado == FALSE
                        and corchetesPequenosA == FALSE) {
                logE = false;
                cout << "Sintax error, '{' is missing." << endl;
                break;



            } else if (expresion[posicion] == '}' and corcheteAbierto == TRUE and corchetesPequenosA == TRUE
                       and corchetesPequenosC == TRUE) {
                logE = true;
                corcheteCerrado    = FALSE;
                corcheteAbierto    = FALSE;
                corchetesPequenosA = FALSE;
                corchetesPequenosC = FALSE;

            }
            if (expresion[posicion] != '{' & expresion[posicion] != '}' & expresion[posicion] != '\n') {
                if (expresion[posicion] == ';') {
                    bloque += expresion[posicion];
                    //total.push_back(subReadFile(expresion));
                    //subReadFile(bloque);
                    bloque = "";
                } else {
                    bloque += expresion[posicion];
                }
            }
           // bloque += expresion[posicion];
        }
        total.push_back(subReadFile(expresion));
        return total;

/*

        if (expresion[posicion] == ' ' & NumeroPalabra == 1){

            if (palabra == "Class") {
                cout << "espere" << endl;

            }else{
                tipo = palabra;
                palabra = "";
                NumeroPalabra ++;
            }




        }else if(NumeroPalabra == 2 & expresion[posicion ] == ' ' ) {
            etiqueta = palabra;
            palabra = "";
            NumeroPalabra++;
        }else if(expresion[posicion] == '=') {

            posicion++;


        }else if (NumeroPalabra == 3 & expresion[posicion] == ';'){
            if (expresion[posicion] == '='){
                posicion++;
            }
            valor = palabra;
            palabra = "";
        }

        if (expresion[posicion+1] == '\n'){
            palabra = "\n";
            NumeroPalabra = 1;
            palabra = "";
            //expresion[posicion]+"\n" ;
            cout<<"Linea Completada"<<endl;

        }


        palabra += expresion[posicion];
    }


    cout<<"Tipo: "+ tipo<<endl;
    cout<<"Etiqueta: "+etiqueta<<endl;
    cout<<"Valor: "+valor<<endl;

*/


/*

    int MAXLINE = 256;
    ifstream infile;
    infile.open(file);

    string oneline;

    string line;


    while(infile){
        getline (infile,oneline);
        string  tipo;
        string  etiqueta;
        string  valor;
        string palabra;
        int     referencia;

        int veces;


        for (int posicion = 0; posicion < sizeof(oneline); posicion++){
            if (oneline[posicion] != ' '|| oneline[posicion] != '+' || oneline[posicion]!= ' =' ||  oneline[posicion] != ' *'
                    and veces == 1){
                palabra += oneline[posicion];
            }else {
                veces += 1;
                if(veces == 1){

                }else if (veces == 2){

                }else if (veces == 3){

                }

                cout<<palabra<<endl;
                palabra = ' ';

            }

        }


        cout<<oneline<< endl;

    }
    infile.close();
*/
}

/**
 * @brief Lee bloques de texto de la caja de texto.
 * @param bloque
 */

json parser::subReadFile(string bloque) {
    cout<<"------Este es el bloque-------"<<endl;
    cout <<bloque<<endl;




    string palabra,tipo,valor,etiqueta;

    int contador = 1;
    int NumeroPalabra = 1;



    for(int posicion = 0; posicion <= bloque.length(); posicion++){

        if (bloque[posicion] == ' ' && NumeroPalabra == 1){

            if (palabra == "Class") {
                tipo = palabra;


            }else if (palabra == "print" or palabra == "printfl") {
                contador ++;
                string prints;
                if (bloque[posicion + 1] == '(' or bloque[posicion + 1] == ')') {
                    if (bloque[posicion + 2] == '"') {
                        for (int posicion2 = posicion + 2; posicion2 <= bloque.length(); posicion2++) {
                            if (bloque[posicion2 + 1] == ';') {
                                //prints.erase(prints.length() - 1);
                                list1.push_back(prints);
                                break;
                            } else {
                                prints += bloque[posicion2];
                            }
                        }
                    } else {
                        for (int posicion2 = posicion + 2; posicion2 <= bloque.length(); posicion2++) {
                            if (bloque[posicion2 + 1] == ';') {
                                list1.push_back(prints);
                                break;
                            } else {
                                prints += bloque[posicion2];
                            }
                        }
                    }
                }
            } else {
                tipo = palabra;
                palabra = "";
                NumeroPalabra ++;
            }




        }else if(NumeroPalabra == 2 && bloque[posicion ] == ' ' ) {
            etiqueta = palabra;
            palabra = "";
            NumeroPalabra++;
        }else if(bloque [posicion] ==
                 '=') {

            posicion++;


        }else if (NumeroPalabra == 3 && bloque[posicion] == ';'){
            if (bloque[posicion] == '='){
                posicion++;
            }
            valor = palabra;
            palabra = "";
        }



        if (bloque[posicion] == ';'){
            if (tipo == "int" or tipo == "float") {
                string referencias = contarReferencias(etiqueta, bloque);
                listaLineas.insertarFinal(tipo, etiqueta, valor, referencias , "4", "");
                tipo = "";

            }else if(tipo == "char") {
                string referencias = contarReferencias(etiqueta, bloque);
                listaLineas.insertarFinal(tipo, etiqueta, valor, referencias, "1", "");
                tipo = "";
            }else if (tipo == "double" or tipo == "long") {
                string referencias = contarReferencias(etiqueta, bloque);
                listaLineas.insertarFinal(tipo, etiqueta, valor, referencias, "8", "");
                tipo = "";
            }
            cout << "tipo: " + tipo <<endl;
            cout << "etiqueta: " + etiqueta << endl;
            cout << "valor: " + valor << endl;
            palabra = "\n";
            NumeroPalabra = 1;
            palabra = "";
            cout <<"----------Lista De Lineas Matcho, Joder!---------"<<endl;
            listaLineas.imprimir();

            cout<<"Linea Completada"<<endl;

        }



        if (bloque[posicion] == '{' or bloque[posicion] == ';' or bloque[posicion] == '\n' or bloque[posicion] == ' ') {
            palabra = palabra;
        } else {
            palabra += bloque[posicion];
        }

    }
    listaLineasCopia = listaLineas.comparar(list1);
    imprimire = true;
    return listaLineas.ToJson();


}

bool parser::logError() {
    return logE;
}

bool parser::imprimir(){
    if (imprimire){
        return true;
    } else {
        return false;
    }
}

list<string> parser::imprimirLista() {
    if (imprimir()) {
        return listaLineasCopia;
    }
}


bool parser::miniParserCA(string expresion) {

    cout << expresion << endl;

    string bloque;

    bool corcheteAbierto = FALSE;
    bool corcheteCerrado = FALSE;


    for (int posicion = 0; posicion <= sizeof(expresion); posicion++) {
        if (expresion[posicion] == '{') {
            return TRUE;
        }
    }
    return FALSE;
}

bool parser::miniParserCC(string expresion) {

    cout << expresion << endl;

    string bloque;

    bool corcheteAbierto = FALSE;;


    for (int posicion = 0; posicion <= sizeof(expresion); posicion++) {
        if (expresion[posicion] == '{') {
            corcheteAbierto = TRUE;
            return corcheteAbierto;
        }
    }
    return FALSE;
}



