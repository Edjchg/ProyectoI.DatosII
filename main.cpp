
#include <gtk/gtk.h>
#include <iostream>
#include <cstdlib>



#include <iostream>
#include<string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;

using namespace std;



static  void button_clicked(GtkWidget*widget, gpointer data){

    g_print("Boton presionado \n");



}

int main(int argc, char* argv[]) {



    /*
     * Cliente del servidor.
     */
    int client, server;
    int portNum = 1500;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    //char *ip = "127.0.0.1";
    struct sockaddr_in serverAddr;
    socklen_t size;

    client = socket(AF_INET,SOCK_STREAM,  0);
    if (client < 0){
        cout << "Error creando el socket ..."<< endl;
        exit(1);
    }

    cout <<"Socket de cliente creado ..." << endl;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(portNum);

    /*
     * Conectando al socket del servidor
     *
     */

    if(connect(client, ((struct sockaddr*)&serverAddr), sizeof(serverAddr)) == 0){
        cout << "Conectando con el servidor..."<< endl;

    }

    recv(client, buffer,  bufsize, 0);

    cout<< "Conexión confirmada..."<< endl;
    cout <<"Ingrese # si quiere terminar la conexión" << endl;

    do{
        cout<< "Cliente: ";
        do{
            cin >> buffer;
            send (client, buffer, bufsize, 0);
            if(* buffer == '#'){
                send (client, buffer, bufsize, 0);
                *buffer = '*';
                isExit = true;

            }
        }while (*buffer != 42);
        cout<< "Servidor:";
        do{
            recv(client, buffer,bufsize,0);
            cout << buffer << "";
            if(*buffer == '#'){
                *buffer = '*';
                isExit = true;
            }
        }while (*buffer != 42);
        cout << endl;
    }while(!isExit);

    cout<< "Conexión terminada"<< endl;
    close(client);

    /*
     * Hasta aqui es el código necesario para el cliente.
     */
    return 0;
    /*
    int *ptr = (int*)malloc(5*sizeof(int));
    ptr[0] = 10;
    ptr[1] = 45;
    ptr[2] = 2;
    ptr[3] = 500;
    ptr[4] = 1;
    ptr[5]= 2;
    ptr[333] = 2;



    if(ptr != NULL){
        for (int i = 0; i < 6; i++ ){
            if (ptr[i] != NULL){
                cout<<ptr[i]<< endl;

            }
        }

    }else{
        cout<<"no agarré memoria"<<endl;
    }

*/


   /* gtk_init(&argc,&argv);

    GtkWidget*window,*button;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    button = gtk_button_new_with_label("Hola");

    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit),NULL);

    g_signal_connect(button, "clicked",G_CALLBACK(button_clicked),NULL);

    gtk_container_add(GTK_CONTAINER(window),button );

    gtk_widget_show_all(window);

    gtk_main();*/

    return  0;





}