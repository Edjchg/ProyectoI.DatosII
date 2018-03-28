//
// Created by Edgar Chaves on 27/3/18.
//

#ifndef PROYECTO1_SINGLETONMEMORY_H
#define PROYECTO1_SINGLETONMEMORY_H


class SingletonMemory {
/*
 * Este patrón de diseño se establecerá para la petición de memoria,
 * el cual es un recurso costoso y solo se debería pedir
 * una vez al servidor.
 */

    public:
        static SingletonMemory& Instancia();

        SingletonMemory(const SingletonMemory&) = delete;

        SingletonMemory& operator = (const SingletonMemory&)= delete;

        int TomarMemoria(int espacio);

        bool MemoriaLLena(int referencia);



    private:
        SingletonMemory ();
        int memoria;



};


#endif //PROYECTO1_SINGLETONMEMORY_H
