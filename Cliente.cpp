//
// Created by Esteban Agüero Pérez  on 4/19/18.
//

#include "Cliente.h"

void error(const char *msg) {
    perror(msg);
    exit(0);
}

/**
 * Inicia la conexion con el servidor
 * @param ip del servidor
 * @param puerto del servidor
 */
void Cliente::iniciarConexion(string ip, string port) {
    portno = atoi(port.c_str());
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        error("ERROR opening socket");
    server = gethostbyname(ip.c_str());
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    setVariables();
}

/**
 * Ajusta ciertas variables
 */
void Cliente::setVariables() {
    bzero((char *) &ip_adress, sizeof(ip_adress));
    ip_adress.sin_family = AF_INET;
    bcopy(server->h_addr,
          (char *) &ip_adress.sin_addr.s_addr,
          server->h_length);
    ip_adress.sin_port = htons(portno);
    if (connect(sock, (struct sockaddr *) &ip_adress, sizeof(ip_adress)) < 0)
        error("ERROR connecting");
}

/**
 * Se encarga de enviar mensajes al servidor
 * @param dato a enviar
 * @return boolean
 */
bool Cliente::escribirServidor(string data) {
    data += delimitador;
    n = send(sock, data.c_str(), data.length(), 0);
    if (n < 0) {
        error("ERROR writing to socket");
        return false;
    }
    return true;
}

/**
 * Lee un char del servidor
 * @return string (un caracter)
 */
string Cliente::leerChar() {
    char buffer[1];
    string reply;
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        puts("recv failed");
    }
    reply = buffer;
    return reply;

}

/**
 * Concatena los char recibidos del servidor
 * @return el mensaje completo recibido
 */

string Cliente::leerServidor() {
    string message = "";
    string character = "";
    while (true) {
        character = leerChar();
        if (character == delimitador) { // delimitador para saber cuando recibi toda la palabra
            break;
        } else message += character;
    }
    return message;
}