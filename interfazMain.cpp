#include <iostream>
#include <gtk/gtk.h>


void funcion_hi ( GtkWidget *widget,
          GtkWidget *fixed ) {
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
        g_print("Activado\n");
    } else {
        g_print("Desactivado\n");
    }
}



int main( int   argc,
           char *argv[] ) {

    // GtkWidget es el tipo utilizado para widgets
    GtkWidget *window, *fixed, *btnRun, *table, *lblRam, *btnClear,
            *lblLog, *txtBar;
    GtkEntryBuffer * txt;

    // Inicializa GTK
    gtk_init(&argc, &argv);

    // Crea una ventana
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    lblRam = gtk_label_new("RAM Live View");
    lblLog = gtk_label_new("Application Log");
    //txtBar = gtk_entry_new();

    //txtBar = gtk_text_view_new();
    txt = gtk_entry_buffer_new("hola", 4);

    gtk_text_view_set_indent(GTK_TEXT_VIEW(txtBar), 100);

    gtk_window_set_title(GTK_WINDOW (window), "C! - IDE");
    table = gtk_grid_new();
    gtk_grid_insert_column(GTK_GRID(table), 0);
    gtk_grid_insert_row(GTK_GRID(table), 0);
    // Conecta el evento "destroy" a un manejador de señales
    g_signal_connect (G_OBJECT(window), "destroy",
                      G_CALLBACK(gtk_main_quit), NULL);

    // Establece la anchura del borde de la ventana.
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);

    // Crea un Contenedor Fixed
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER (window), fixed);
    //gtk_widget_show (fixed);
    btnRun = gtk_toggle_button_new_with_label("RUN");
    btnClear = gtk_toggle_button_new_with_label("Clear");
    g_signal_connect(G_OBJECT(btnRun), "clicked", G_CALLBACK(funcion_hi), (gpointer) fixed);
    g_signal_connect(G_OBJECT(btnClear), "clicked", G_CALLBACK(funcion_hi), (gpointer) fixed);
    gtk_fixed_put(GTK_FIXED(fixed), btnRun, 0, 0);
    //gtk_fixed_put(GTK_FIXED(fixed), txtBar, 50, 50);
    //gtk_widget_set_size_request(txtBar, 650, 350);



    gtk_fixed_put(GTK_FIXED(fixed), lblRam, 800, 0);
    gtk_fixed_put(GTK_FIXED(fixed), lblLog, 0, 480);
    gtk_fixed_put(GTK_FIXED(fixed), btnClear, 500, 480);
    gtk_widget_show_all(window);
    //gtk_widget_show(window);
    //gtk_widget_show(lblRam);

    gtk_main();
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