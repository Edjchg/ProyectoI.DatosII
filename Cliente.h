//
// Created by Esteban Agüero Pérez  on 4/19/18.
//

#ifndef CLIENTESERVIDORSOCKETS_CLIENTE_H
#define CLIENTESERVIDORSOCKETS_CLIENTE_H

#include "stdio.h"
#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <thread>

using namespace std;

static std::string delimitador="*";

class Cliente {
    //Variables importantes del cliente
    int sock, portno, n;
    struct sockaddr_in ip_adress;
    struct hostent *server;

public:
    //Constructor
    Cliente() {}

    //Metodos de la clase Client
    void iniciarConexion(string ip, string port);

    void setVariables();

    bool escribirServidor(string data);

    string leerChar();

    string leerServidor();
};


#endif //CLIENTESERVIDORSOCKETS_CLIENTE_H
