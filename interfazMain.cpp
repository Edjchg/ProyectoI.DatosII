#include <iostream>

#include <gtk/gtk.h>

#include <cstdlib>

#include "parser.h"

#include<string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;

void funcion_hi ( GtkWidget *widget,
          GtkWidget *fixed ) {
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
        g_print("Activado\n");
    } else {
        g_print("Desactivado\n");
    }
}

static  void button_clicked(GtkWidget*widget, gpointer data){

    g_print("Boton presionado \n");



}

int main( int   argc,
           char *argv[] ) {

    // GtkWidget es el tipo utilizado para widgets
    GtkWidget *window, *fixed, *btnRun, *table, *lblRam, *btnClear,
                *lblLog, *txtBar, *lbl, *box;
    // Inicializa GTK
    gtk_init (&argc, &argv);

    // Crea una ventana
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    lblRam = gtk_label_new("RAM Live View");
    lblLog = gtk_label_new("Application Log");
    txtBar = gtk_text_view_new();
    gtk_text_view_set_indent(GTK_TEXT_VIEW(txtBar), 100);
    fixed = gtk_fixed_new ();
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_window_set_title (GTK_WINDOW (window), "C! - IDE");
    table = gtk_grid_new();
    gtk_grid_insert_column(GTK_GRID(table), 0);
    gtk_grid_insert_row(GTK_GRID(table), 0);
    // Conecta el evento "destroy" a un manejador de señales
    g_signal_connect (G_OBJECT (window), "destroy",
                     G_CALLBACK (gtk_main_quit), NULL);

    gint curr_row = 0;
    gint curr_col = 0;
    for(gint i = 0; i< 20; i++){
        lbl = gtk_label_new(" HOLA \n");
        gtk_grid_attach(GTK_GRID(table), lbl, curr_row % 4, curr_col % 8, 1, 1 );
        if (++curr_row % 4 == 0)
            curr_col ++;

    }
    gtk_grid_set_column_homogeneous(GTK_GRID(table), true);
    gtk_grid_set_row_homogeneous(GTK_GRID(table), true);






    // Establece la anchura del borde de la ventana.
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);

    // Crea un Contenedor Fixed
    gtk_container_add (GTK_CONTAINER (window), fixed);
    //gtk_widget_show (fixed);
    btnRun = gtk_toggle_button_new_with_label("RUN");
    btnClear = gtk_toggle_button_new_with_label("Clear");
    g_signal_connect(G_OBJECT(btnRun), "clicked", G_CALLBACK(funcion_hi), (gpointer) fixed);
    g_signal_connect(G_OBJECT(btnClear), "clicked", G_CALLBACK(funcion_hi), (gpointer) fixed);
    gtk_fixed_put(GTK_FIXED(fixed), btnRun, 0, 0);
    gtk_fixed_put(GTK_FIXED(fixed),txtBar, 50, 50 );
    gtk_widget_set_size_request(txtBar, 650, 350);

    gtk_fixed_put(GTK_FIXED(fixed), lblRam, 800, 0);
    gtk_fixed_put(GTK_FIXED(fixed), lblLog, 0, 480);
    gtk_fixed_put(GTK_FIXED(fixed), btnClear, 500, 480);
    gtk_box_pack_start(GTK_BOX(box), table, false, false, 0);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_fixed_put(GTK_FIXED(fixed), box, 750, 50);
    gtk_widget_set_size_request(box, 200, 100);
    gtk_widget_show_all(window);
    //gtk_widget_show(window);
    //gtk_widget_show(lblRam);

    gtk_main ();
    return 0;


    //parser parse;
    //parse.readfile();


    /*
     * Cliente del servidor.
     */

    /*
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

     */

    /*
     * Conectando al socket del servidor
     *
     */

/*

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

*/

    /*
     * Hasta aqui es el código necesario para el cliente.
     */
    // return 0;
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

    /*
    gtk_init(&argc,&argv);

    GtkWidget*window,*button, *table;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    button = gtk_button_new_with_label("Hola");




    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit),NULL);

    g_signal_connect(button, "clicked",G_CALLBACK(button_clicked),NULL);

    gtk_container_add(GTK_CONTAINER(window),button );

    gtk_widget_show_all(window);

    gtk_main();

     */

    // return  0;







}
/*
int main(int argc, char*argv[]) {

    gtk_init(&argc, &argv);
    GtkWidget *window, *button, *box, *button2, *button3;
    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
    button = gtk_button_new_with_label("Click me");
    button2 = gtk_button_new_with_label("Click si");
    button3 = gtk_button_new_with_label("Click no");
    gtk_box_pack_start(GTK_BOX(box), button, true, true, 0);
    gtk_box_pack_start(GTK_BOX(box), button2, false, false, 0);
    gtk_box_pack_start(GTK_BOX(box), button3, false, false, 0);
    gtk_container_add(GTK_CONTAINER(window), button);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_set_halign(button, GTK_ALIGN_START);
    gtk_widget_set_valign(button, GTK_ALIGN_CENTER);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;

}*/