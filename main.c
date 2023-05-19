#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

static gchar *operation, *op1, *op2;
double operand1, operand2, result;

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

void get_text(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    printf("Entry Box Text: %s\n", text);
    printf("Operation: %s\n", operation);
    if (strcmp(operation, "add") == 0) {
        printf("Am intrat in add\n");
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        printf("Am luat numarul: %s\n", op2);
        // cast din gchar in double
        operand2 = atof(op2);
        result = addition(operand1, operand2);
        printf("Result is: %f\n", result);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "sub") == 0) {
        printf("Am intrat in sub\n");
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        printf("Am luat numarul: %f\n", operand2);
        result = 0;
        printf("op1 is %f, op2 is %f\n", operand1, operand2);
        result = operand1 - operand2;
        printf("Result is: %f\n", result);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "mult") == 0) {
        printf("Am intrat in mult\n");
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        printf("Am luat numarul: %f\n", operand2);
        result = 0;
        printf("op1 is %f, op2 is %f\n", operand1, operand2);
        result = multiplication(operand1, operand2);
        printf("Result is: %f\n", result);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "div") == 0) {
        printf("Am intrat in div\n");
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        printf("Am luat numarul: %f\n", operand2);
        result = 0;
        printf("op1 is %f, op2 is %f\n", operand1, operand2);
        result = division(operand1, operand2);
        printf("Result is: %f\n", result);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "modulo") == 0) {
        printf("Am intrat in mod\n");
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        printf("Am luat numarul: %f\n", operand2);
        result = 0;
        printf("op1 is %f, op2 is %f\n", operand1, operand2);
        result = (int)modulo((int)operand1, (int)operand2);
        printf("Result is: %f\n", result);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "bit_and") == 0) {
        printf("Am intrat in bit_and\n");
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        printf("Am luat numarul: %f\n", operand2);
        result = (int)result;
        printf("op1 is %f, op2 is %f\n", operand1, operand2);
        result = (int)bit_and((int)operand1, (int)operand2);
        printf("Result is: %d\n", result);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
}

void add_text(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    const gchar *button_label = gtk_button_get_label(button);
    gchar *current_text = gtk_entry_get_text(GTK_ENTRY(entry));

    gchar *new_text = g_strconcat(current_text, button_label, NULL);
    gtk_entry_set_text(GTK_ENTRY(entry), new_text);

    g_free(new_text);
}

void make_add(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    printf("Am luat numarul: %f\n", operand1);
    operation = "add";
}

void make_sub(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    printf("Am luat numarul: %f\n", operand1);
    operation = "sub";
}

void make_mult(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    printf("Am luat numarul: %f\n", operand1);
    operation = "mult";
}

void make_div(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    printf("Am luat numarul: %f\n", operand1);
    operation = "div";
}

void make_modulo(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    printf("Am luat numarul: %f\n", operand1);

    operation = "modulo";
}

void make_negation(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    operand1 = (int)operand1;
    // clear the text box
    operand1 = negation(operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    printf("Am luat numarul: %f\n", operand1);
    operation = "negation";
    gchar *result = g_strdup_printf("%f", operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), result);
}

void make_bit_and(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    printf("Am luat numarul: %f\n", operand1);
    operation = "bit_and";
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

    g_signal_connect(button[15], "clicked", G_CALLBACK(get_text), box);
    g_signal_connect(button[1], "clicked", G_CALLBACK(add_text), box);
    g_signal_connect(button[2], "clicked", G_CALLBACK(add_text), box);
    g_signal_connect(button[3], "clicked", G_CALLBACK(add_text), box);
    g_signal_connect(button[4], "clicked", G_CALLBACK(add_text), box);
    g_signal_connect(button[5], "clicked", G_CALLBACK(add_text), box);
    g_signal_connect(button[6], "clicked", G_CALLBACK(add_text), box);
    g_signal_connect(button[7], "clicked", G_CALLBACK(add_text), box);
    g_signal_connect(button[8], "clicked", G_CALLBACK(add_text), box);
    g_signal_connect(button[9], "clicked", G_CALLBACK(add_text), box);
    g_signal_connect(button[14], "clicked", G_CALLBACK(add_text), box);
    g_signal_connect(button[10], "clicked", G_CALLBACK(make_add), box);
    g_signal_connect(button[11], "clicked", G_CALLBACK(make_sub), box);
    g_signal_connect(button[12], "clicked", G_CALLBACK(make_mult), box);
    g_signal_connect(button[13], "clicked", G_CALLBACK(make_div), box);
    g_signal_connect(button[16], "clicked", G_CALLBACK(make_modulo), box);
    g_signal_connect(button[17], "clicked", G_CALLBACK(make_negation), box);
    g_signal_connect(button[18], "clicked", G_CALLBACK(make_bit_and), box);
}

/*void calculare(GtkWidget *button) {
    // functie de calculare
    const gchar *text = gtk_button_get_label(button);
    if (strcmp(text, "+") == 0) {
        actual = atof(input);
        printf("%f\n", actual);
    }
    if (strcmp(text, "=") == 0) {
        printf("%f\n", actual);
    } else {
        strcat(input, text);
    }
}*/

int main(int argc, char **argv) {
    // declarare fereastra
    GtkWidget *main_window;
    GtkWidget *box;
    GtkWidget *grid;
    GtkWidget *button[31];

    operation = "nothing";

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

    // put in box value of 0
    // calculare(button);
    // return the value entered in box when button

    // calculare(button, box);

    // functie de setare semnal inchidere
    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    // functie de afisare fereastra
    gtk_widget_show_all(main_window);
    // functie de executie
    gtk_main();

    return 0;
}