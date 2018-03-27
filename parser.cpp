//
// Created by Edgar Chaves on 27/3/18.
//

#include "parser.h"
#include <fstream>
#include <iostream>

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
        cout<<oneline<< endl;

    }
    infile.close();

}




