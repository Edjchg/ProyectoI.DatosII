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
#include <thread>
#include <pthread.h>

using namespace std;



void funcion_hi ( GtkWidget *widget,
          GtkWidget *fixed ) {
    int hola = 2;
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
        //g_print("Activado\n");
        cout<< "Hola *"<< endl;
    } else {
        g_print("Desactivado\n");
    }
}

GtkWidget *lbl, *table, *lbl1, *lbl2, *lbl3;
gint columna = 0;
gint fila = 0;

void agregarFila(const char *memoria, const char *valor, const char *etiqueta, const char *conteo) {
    lbl = gtk_label_new(memoria);
    lbl1 = gtk_label_new(valor);
    lbl2 = gtk_label_new(etiqueta);
    lbl3 = gtk_label_new(conteo);
    gtk_grid_attach(GTK_GRID(table), lbl, columna, fila , 1, 1);
    gtk_grid_attach(GTK_GRID(table), lbl1, columna + 1, fila , 1, 1);
    gtk_grid_attach(GTK_GRID(table), lbl2, columna + 2, fila , 1, 1);
    gtk_grid_attach(GTK_GRID(table), lbl3, columna + 3, fila , 1, 1);
    fila += 1;
}

void borrarAppliLog(GtkWidget *widget, gpointer data) {
    gtk_label_set_text(GTK_LABEL(data), "");

}
char *getTextOfTextview(GtkWidget *widget, gpointer data) {

    GtkTextIter start, end;

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(data));
    gchar *text;



    gint lineas = gtk_text_buffer_get_line_count (buffer);
    cout<<"------Numero de lineas--------"<<endl;
    cout <<lineas<<endl;






    gtk_text_buffer_get_bounds(buffer, &start, &end);
    text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);



    parser parser1;
    parser1.readfile(text);


    return text;
}

void *cliente(){
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



    //if(connect(client, ((struct sockaddr*)&serverAddr), sizeof(serverAddr)) == 0){
        cout << "Conectando con el servidor..."<< endl;

    //}
    connect(client, ((struct sockaddr*)&serverAddr), sizeof(serverAddr));
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

}


int main( int   argc,
           char *argv[] ) {

    //cliente();

    thread p(cliente);
    p.detach();



    // GtkWidget es el tipo utilizado para widget


    GtkWidget *scrolledRam, * window, *fixed, *btnRun,*lblRam, *btnClear,
            *lblLog, *txtBar, *lbl, *box, *btnObtText, *lblShell,
            *lblAppliText, *lblShellText, *scrollWindows;



    GtkTextIter iter;

    GtkTextBuffer *buffer;

    // Inicializa GTK
    gtk_init(&argc, &argv);

    // Creando componentes
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW (window), "C! - IDE");
    gtk_window_set_default_size(GTK_WINDOW(window),220, 200 );
    buffer = gtk_text_buffer_new (NULL);
    gtk_text_buffer_get_iter_at_line (buffer, &iter,0);
    scrollWindows = gtk_scrolled_window_new(NULL, NULL);
    scrolledRam = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_set_border_width (GTK_CONTAINER (scrollWindows), 10);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW (scrollWindows),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    lblRam = gtk_label_new("RAM Live View");
    lblLog = gtk_label_new("Application Log");
    lblShell = gtk_label_new(">>");
    lblShellText = gtk_label_new("HOLA");
    lblAppliText = gtk_label_new("HOLA X2");
    txtBar = gtk_text_view_new();
    fixed = gtk_fixed_new();
    table = gtk_grid_new();
    btnRun = gtk_toggle_button_new_with_label("RUN");
    btnObtText = gtk_button_new_with_label("Obtener");

    btnClear = gtk_toggle_button_new_with_label("Clear");
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    //conectando señales/eventos
    g_signal_connect (G_OBJECT(window), "destroy",
                      G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(btnRun), "clicked", G_CALLBACK(funcion_hi), (gpointer) fixed);
    g_signal_connect(G_OBJECT(btnClear), "clicked", G_CALLBACK(borrarAppliLog), lblAppliText);
    g_signal_connect(G_OBJECT(btnObtText), "clicked", G_CALLBACK(getTextOfTextview), txtBar);


    /*gint curr_row = 0;
    gint curr_col = 0;
    for (gint i = 0; i < 40; i++) {
        lbl = gtk_label_new(" HOLA \n");
        gtk_grid_attach(GTK_GRID(table), lbl, curr_row % 4, curr_col % 8, 1, 1);
        if (++curr_row % 4 == 0)
            curr_col++;

    }*/
    //gtk_grid_set_column_homogeneous(GTK_GRID(table), true);
    //gtk_grid_set_row_homogeneous(GTK_GRID(table), true);



    //colocando coordenadas y tamaño
    gtk_text_view_set_indent(GTK_TEXT_VIEW(txtBar), 100);
    gtk_grid_insert_column(GTK_GRID(table), 0);
    gtk_grid_insert_row(GTK_GRID(table), 0);
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
    gtk_container_add(GTK_CONTAINER(scrollWindows), txtBar);
    gtk_container_add(GTK_CONTAINER(scrolledRam), box);
    gtk_container_add(GTK_CONTAINER (window), fixed);
    gtk_fixed_put(GTK_FIXED(fixed), btnRun, 0, 0);
    gtk_fixed_put(GTK_FIXED(fixed), btnObtText, 50, 0);
    gtk_fixed_put(GTK_FIXED(fixed), scrollWindows, 50, 50);
    gtk_widget_set_size_request(scrollWindows, 650, 350);
    gtk_fixed_put(GTK_FIXED(fixed), lblRam, 800, 0);
    gtk_fixed_put(GTK_FIXED(fixed), lblLog, 0, 480);
    gtk_fixed_put(GTK_FIXED(fixed), lblAppliText, 0, 500);
    gtk_fixed_put(GTK_FIXED(fixed), lblShell, 0, 400);
    gtk_fixed_put(GTK_FIXED(fixed), lblShellText, 40, 400);
    gtk_fixed_put(GTK_FIXED(fixed), btnClear, 500, 480);
    gtk_box_pack_start(GTK_BOX(box), table, false, false, 0);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_fixed_put(GTK_FIXED(fixed), scrolledRam, 750, 50);
    gtk_widget_set_size_request(scrolledRam, 300, 300);

    //EJEMPLO DE COMO AGREGAR UNA FILA
    //agregarFila(memoria.c_str(), valor.c_str(), etiqueta.c_str(), conteo.c_str());

    gtk_grid_set_column_homogeneous(GTK_GRID(table), true);
    gtk_grid_set_row_homogeneous(GTK_GRID(table), true);
    gtk_widget_show_all(window);
    gtk_main ();


    return 0;

}











    //parser parse;
    //parse.readfile();




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
    gtk_main ();


    return 0;




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
