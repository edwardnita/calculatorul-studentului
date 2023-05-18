#include <gtk/gtk.h>
#include <stdio.h>

#include "functions.h"

void initializare_butoane(GtkWidget *button[31]) {
    // creare butoane
    button[0] = gtk_button_new_with_label(".");
    button[1] = gtk_button_new_with_label("1");
    button[2] = gtk_button_new_with_label("2");
    button[3] = gtk_button_new_with_label("3");
    button[4] = gtk_button_new_with_label("4");
    button[5] = gtk_button_new_with_label("5");
    button[6] = gtk_button_new_with_label("6");
    button[7] = gtk_button_new_with_label("7");
    button[8] = gtk_button_new_with_label("8");
    button[9] = gtk_button_new_with_label("9");
    button[10] = gtk_button_new_with_label("+");
    button[11] = gtk_button_new_with_label("-");
    button[12] = gtk_button_new_with_label("*");
    button[13] = gtk_button_new_with_label("/");
    button[14] = gtk_button_new_with_label("0");
    button[15] = gtk_button_new_with_label("=");
    button[16] = gtk_button_new_with_label("%");
    button[17] = gtk_button_new_with_label("not");
    button[18] = gtk_button_new_with_label("AND");
    button[19] = gtk_button_new_with_label("OR");
    button[20] = gtk_button_new_with_label("XOR");
    button[21] = gtk_button_new_with_label("fact");
    button[22] = gtk_button_new_with_label("sin");
    button[23] = gtk_button_new_with_label("cos");
    button[24] = gtk_button_new_with_label("tan");
    button[25] = gtk_button_new_with_label("ctg");
    button[26] = gtk_button_new_with_label("arcsin");
    button[27] = gtk_button_new_with_label("arccos");
    button[28] = gtk_button_new_with_label("ln");
    button[29] = gtk_button_new_with_label("log");
    button[30] = gtk_button_new_with_label("power");
}

void pozitionare_elemente(GtkWidget *grid, GtkWidget *box,
                          GtkWidget *button[31]) {
    // pozitionare automata continut in fereastra
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_attach(GTK_GRID(grid), box, 0, 0, 8, 2);
    gtk_grid_attach(GTK_GRID(grid), button[7], 0, 3, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[8], 2, 3, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[9], 4, 3, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[13], 6, 3, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[4], 0, 5, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[5], 2, 5, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[6], 4, 5, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[12], 6, 5, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[1], 0, 7, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[2], 2, 7, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[3], 4, 7, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[16], 6, 7, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[0], 0, 9, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[14], 2, 9, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[10], 4, 9, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[11], 5, 9, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[15], 6, 9, 2, 1);

    gtk_grid_attach(GTK_GRID(grid), button[17], 0, 11, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[18], 2, 11, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[19], 4, 11, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[20], 6, 11, 2, 1);

    gtk_grid_attach(GTK_GRID(grid), button[21], 0, 13, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[22], 2, 13, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[23], 4, 13, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[24], 6, 13, 2, 1);

    gtk_grid_attach(GTK_GRID(grid), button[25], 0, 15, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[26], 2, 15, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[27], 4, 15, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[28], 6, 15, 2, 1);

    gtk_grid_attach(GTK_GRID(grid), button[29], 2, 17, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button[30], 4, 17, 2, 1);
}

int main(int argc, char **argv) {
    // declarare fereastra
    GtkWidget *main_window;
    GtkWidget *box;
    GtkWidget *grid;
    GtkWidget *button[31];

    // functie de initializare
    gtk_init(&argc, &argv);

    // creare fereastra
    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // functie de setare titlu
    gtk_window_set_title(GTK_WINDOW(main_window), "Calculatorul Studentului");
    // functie de setare dimensiuni
    gtk_window_set_default_size(GTK_WINDOW(main_window), 400, 600);
    // functie de setare pozitie
    gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
    // functie prin care fereastra nu e resizable
    gtk_window_set_resizable(GTK_WINDOW(main_window), TRUE);

    // creare grid (container)
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(main_window), grid);
    // dimensiune grid
    gtk_grid_set_column_spacing(GTK_GRID(grid), 12);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);

    // creare input box
    box = gtk_entry_new();
    // setare editare
    gtk_editable_set_editable(GTK_EDITABLE(box), TRUE);

    initializare_butoane(button);

    // pozitionare butoane si input box
    pozitionare_elemente(grid, box, button);

    // functie de setare semnal inchidere
    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    // functie de afisare fereastra
    gtk_widget_show_all(main_window);
    // functie de executie
    gtk_main();

    return 0;
}