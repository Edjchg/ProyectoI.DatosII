//
// Created by Edgar Chaves on 27/3/18.
//

#include "parser.h"
#include <fstream>
#include <iostream>
#include "ListaSimple.h"
using namespace std;
string file = "/Users/edgarchaves/Desktop/C!.txt";


void parser::readfile() {
    int MAXLINE = 256;
    ifstream infile;
    infile.open(file);

    string oneline;

    string line;


    while(infile){
        getline(infile,oneline);
        string tipo;
        string etiqueta;
        string valor;
        int referencia;

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

}




