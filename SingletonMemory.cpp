//
// Created by Edgar Chaves on 27/3/18.
//

#include "SingletonMemory.h"
#include <iostream>
using namespace std;

SingletonMemory::SingletonMemory() {
    memoria = 0;
}

SingletonMemory& SingletonMemory::Instancia() {
    static SingletonMemory instancia;
    return instancia;

}

int SingletonMemory::TomarMemoria(int espacio) {


}

bool SingletonMemory::MemoriaLLena(int referencia) {

    if (referencia != 0){
        return true;
    }else{
        int cantidadMemoria;
        TomarMemoria(cantidadMemoria);
        return true;
    }
}
