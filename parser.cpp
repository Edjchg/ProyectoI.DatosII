//
// Created by Edgar Chaves on 27/3/18.
//

#include "parser.h"
#include <fstream>
#include <iostream>
#include "ListaSimple.h"
using namespace std;
string file = "/Users/edgarchaves/Desktop/C!.txt";


void parser::readfile(string expresion) {


    cout<<expresion<<endl;

    string palabra, tipo, etiqueta, valor;
    int NumeroPalabra = 1;
    int referencias;

    char lista [3];

    char ListaGrande [50];

    for(int posicion = 0; posicion <= sizeof(expresion); posicion ++){

        if (expresion[posicion] == ' ' & NumeroPalabra == 1){

            tipo = palabra;
            palabra = "";
            NumeroPalabra ++;

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




