//
// Created by Edgar Chaves on 27/3/18.
//

#include "parser.h"
#include <fstream>
#include <iostream>
#include "ListaSimple.h"
#include "checker.h"


using namespace std;

string file = "/Users/edgarchaves/Desktop/C!.txt";



/**
 * @brief Lee y verifica que los corchetes estén correctos.
 * @param expresion
 */
void parser::readfile(string expresion) {

    cout << expresion << endl;

    string bloque;

    bool corcheteAbierto = FALSE;
    bool corcheteCerrado = FALSE;

    bool corchetesPequenosA = FALSE;
    bool corchetesPequenosC = FALSE;

    int corchetesGrandes = 0;

    int bloqueTexto = 1;


    char lista[3];
    char ListaGrande[50];




    for (int posicion = 0; posicion <= sizeof(expresion); posicion++) {


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
                cout << "Sintax error, '}' is missing." << endl;
                break;

            } else if (expresion[posicion] == '}' and corcheteAbierto == TRUE and corcheteCerrado == FALSE
                        and corchetesPequenosA == FALSE) {
                cout << "Sintax error, '{' is missing." << endl;
                break;



            } else if (expresion[posicion] == '}' and corcheteAbierto == TRUE and corchetesPequenosA == TRUE
                       and corchetesPequenosC == TRUE) {
                bloque += expresion[posicion];
                subReadFile(bloque);
                corcheteCerrado    = FALSE;
                corcheteAbierto    = FALSE;
                corchetesPequenosA = FALSE;
                corchetesPequenosC = FALSE;

            }
            bloque += expresion[posicion];
        }



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

void parser::subReadFile(string bloque) {
    cout<<"------Este es el bloque-------"<<endl;
    cout <<bloque<<endl;

    ListaSimple listaLineas;



    string palabra,tipo,valor,etiqueta;


    int NumeroPalabra = 1;



    for(int posicion = 0; posicion <= sizeof(bloque); posicion++){

        if (bloque[posicion] == ' ' & NumeroPalabra == 1){

            if (palabra == "Class") {
                tipo = palabra;


            }else{
                tipo = palabra;
                palabra = "";
                NumeroPalabra ++;
            }




        }else if(NumeroPalabra == 2 & bloque[posicion ] == ' ' ) {
            etiqueta = palabra;
            palabra = "";
            NumeroPalabra++;
        }else if(bloque [posicion] == '=') {

            posicion++;


        }else if (NumeroPalabra == 3 & bloque[posicion] == ';'){
            if (bloque[posicion] == '='){
                posicion++;
            }
            valor = atoi(palabra.c_str());
            palabra = "";
        }



        if (bloque[posicion+1] == '\n'){
            if (tipo == "int" or tipo == "float") {

                listaLineas.insertarFinal(tipo, etiqueta, valor, NULL, 4);

            }else if(tipo == "char") {

                listaLineas.insertarFinal(tipo, etiqueta, valor, NULL, 1);

            }else if (tipo == "double" or tipo == "long") {

                listaLineas.insertarFinal(tipo, etiqueta, valor, NULL, 8);
            }
            palabra = "\n";
            NumeroPalabra = 1;
            palabra = "";
            cout <<"----------Lista De Lineas Matcho, Joder!---------"<<endl;
            listaLineas.imprimir();

            cout<<"Linea Completada"<<endl;

        }


        palabra += bloque[posicion];
    }

}

}




