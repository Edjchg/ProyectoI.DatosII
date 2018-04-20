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
#include "prueba.h"

#include <gtksourceview/gtksource.h>


using namespace std;

void printLog(string error){
    cout<<"error"<<endl;
}

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

GtkWidget *lbl, *table, *lbl1, *lbl2, *lbl3, *lblAppliText, *lblShellText, *txtBar;
gint columna = 0;
gint fila = 0;

/**
 * @brief agrega una fila a el ram live view
 * @param memoria direccion de memoria
 * @param valor de la variable que guarda
 * @param etiqueta de la variable
 * @param conteo de referencias que tiene la variable
 */
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
/**
 * @brief borra lo que tenga el application log
 * @param widget la ventana principal
 * @param data son los datos de application log
 */
void borrarAppliLog(GtkWidget *widget, gpointer data) {
    gtk_label_set_text(GTK_LABEL(data), "");

}

/**
 * @brief obtiene lo que esta en el text view para parsear
 * @param widget la ventana principal
 * @param data los datos del text view
 * @return retorna el texto parseado
 */

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



    parser1.logError();
    if (parser1.logError() == FALSE){
        gtk_label_set_text(GTK_LABEL(lblAppliText), "Syntaxis Error");
    }
    return text;
}
char *getTextEnter(GtkWidget *widget, gpointer data) {
    GtkTextIter start, end;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(data));
    gchar *text;
    gint lineas = gtk_text_buffer_get_line_count(buffer);
    cout << "------Numero de lineas--------" << endl;
    cout << lineas << endl;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    parser parser1;
    if (parser1.miniParserCA(text) == TRUE){
        gtk_source_view_indent_lines (GTK_SOURCE_VIEW(txtBar), &end, &end);
    }

}

/**
 * @brief cuando se toca enter se llama al parser para que la ram view se actualice
 * @param widget ventana principañ
 * @param pKey envento
 * @param userdata la informacion de text view
 * @return si es true, obtiene lo del text view, si no no hace nada
 */
gboolean on_key_press (GtkWidget * widget, GdkEventKey* pKey,gpointer userdata){
    if (pKey->type == GDK_KEY_PRESS){
        g_print("%i\n", pKey->keyval);
        if (pKey->keyval == GDK_KEY_Return) {
            getTextEnter(widget, userdata);
        }
    }
    return FALSE;
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

    prueba prueba2;
    prueba2.prueba1();


    thread p(cliente);
    p.detach();



    // GtkWidget es el tipo utilizado para widget


    GtkWidget *scrolledRam, * window, *fixed, *btnRun,*lblRam, *btnClear,
            *lblLog, *lbl, *box, *lblShell,
             *scrollWindows, *scrollAppli, *scrollShell,
            *boxAppli, *boxShell;

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
    scrollAppli = gtk_scrolled_window_new(NULL, NULL);
    scrollShell = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_set_border_width (GTK_CONTAINER (scrollWindows), 10);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW (scrollWindows),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    lblRam = gtk_label_new("RAM Live View");
    lblLog = gtk_label_new("Application Log");
    lblShell = gtk_label_new(">>");
    lblShellText = gtk_label_new("");
    lblAppliText = gtk_label_new("");
    txtBar = gtk_source_view_new();
    fixed = gtk_fixed_new();
    table = gtk_grid_new();
    gtk_source_view_set_show_line_numbers(GTK_SOURCE_VIEW(txtBar), true);
    btnRun = gtk_toggle_button_new_with_label("RUN");
    btnRun = gtk_button_new_with_label("RUN");

    btnClear = gtk_toggle_button_new_with_label("Clear");
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    //conectando señales/eventos
    g_signal_connect (G_OBJECT(window), "destroy",
                      G_CALLBACK(gtk_main_quit), NULL);
    //gtk_widget_set_events (txtBar, GDK_ENTER_NOTIFY_MASK);
    g_signal_connect(G_OBJECT(btnRun), "clicked", G_CALLBACK(getTextOfTextview), txtBar);
    g_signal_connect(G_OBJECT(btnClear), "clicked", G_CALLBACK(borrarAppliLog), lblAppliText);
   //g_signal_connect(txtBar, "key_press_event", G_CALLBACK(on_key_press), txtBar);


    //colocando coordenadas y tamaño
    gtk_text_view_set_indent(GTK_TEXT_VIEW(txtBar), 100);
    gtk_grid_insert_column(GTK_GRID(table), 0);
    gtk_grid_insert_row(GTK_GRID(table), 0);
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
    gtk_container_add(GTK_CONTAINER(scrollWindows), txtBar);
    gtk_container_add(GTK_CONTAINER(scrolledRam), box);
    gtk_container_add(GTK_CONTAINER(scrollShell), lblShellText);
    gtk_container_add(GTK_CONTAINER(scrollAppli), lblAppliText);
    gtk_container_add(GTK_CONTAINER (window), fixed);
    gtk_fixed_put(GTK_FIXED(fixed), btnRun, 0, 0);
    gtk_fixed_put(GTK_FIXED(fixed), scrollWindows, 50, 50);
    gtk_widget_set_size_request(scrollWindows, 650, 350);
    gtk_widget_set_size_request(scrollShell,650, 50);
    gtk_widget_set_size_request(scrollAppli, 650, 50);
    gtk_fixed_put(GTK_FIXED(fixed), lblRam, 800, 0);
    gtk_fixed_put(GTK_FIXED(fixed), lblLog, 0, 480);
    gtk_fixed_put(GTK_FIXED(fixed), scrollAppli, 0, 500);
    gtk_fixed_put(GTK_FIXED(fixed), lblShell, 0, 400);
    gtk_fixed_put(GTK_FIXED(fixed), scrollShell, 40, 400);
    gtk_fixed_put(GTK_FIXED(fixed), btnClear, 500, 480);
    gtk_box_pack_start(GTK_BOX(box), table, false, false, 0);
    //gtk_container_add(GTK_CONTAINER(window), box);
    gtk_fixed_put(GTK_FIXED(fixed), scrolledRam, 750, 50);
    gtk_widget_set_size_request(scrolledRam, 300, 300);

    //EJEMPLO DE COMO AGREGAR UNA FILA
    //agregarFila(memoria.c_str(), valor.c_str(), etiqueta.c_str(), conteo.c_str());
    gtk_source_view_set_auto_indent (GTK_SOURCE_VIEW(txtBar), true);
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
