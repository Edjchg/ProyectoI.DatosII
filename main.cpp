
#include <gtk/gtk.h>


static  void button_clicked(GtkWidget*widget, gpointer data){

    g_print("Boton presionado \n");



}

int main(int argc, char* argv[]) {

    gtk_init(&argc,&argv);

    GtkWidget*window,*button;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    button = gtk_button_new_with_label("Hola");

    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit),NULL);

    g_signal_connect(button, "clicked",G_CALLBACK(button_clicked),NULL);

    gtk_container_add(GTK_CONTAINER(window),button );

    gtk_widget_show_all(window);

    gtk_main();

    return  0;





}