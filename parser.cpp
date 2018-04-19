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




void parser::readfile(string expresion) {


    cout << expresion << endl;

    string bloque, tipo, etiqueta, valor;
    int NumeroPalabra = 1;
    int referencias;

    bool corcheteAbierto = FALSE;
    bool corcheteCerrado = TRUE;

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


        //if (corcheteAbierto == FALSE and corcheteCerrado == TRUE) {
          //  corcheteCerrado = FALSE;

            if (expresion[posicion] == '{' and corcheteAbierto == FALSE and corcheteCerrado == TRUE and
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

void parser::subReadFile(string bloque) {
    cout<<"------Este es el bloque-------"<<endl;
    cout <<bloque<<endl;

    for(int posicion = 0; posicion <= sizeof(bloque); posicion++){
        continue;
    }

}




