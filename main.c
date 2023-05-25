#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

static gchar *operation, *op1, *op2;
double operand1, operand2, result;

void initializare_butoane(GtkWidget *button[32]) {
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
    button[30] = gtk_button_new_with_label("exp");
    button[31] = gtk_button_new_with_label("x^y");
}

void get_text(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    if (strcmp(operation, "add") == 0) {
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        result = addition(operand1, operand2);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%.4f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "sub") == 0) {
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        result = 0;
        result = operand1 - operand2;
        // cast din double in gchar
        gchar *result = g_strdup_printf("%.4f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "mult") == 0) {
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        result = 0;
        result = multiplication(operand1, operand2);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%.4f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "div") == 0) {
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        result = 0;
        result = division(operand1, operand2);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%.4f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "modulo") == 0) {
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        result = 0;
        result = (int)modulo((int)operand1, (int)operand2);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%.4f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "bit_and") == 0) {
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        result = (int)result;
        result = (int)bit_and((int)operand1, (int)operand2);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%.4f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "bit_or") == 0) {
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        result = (int)result;
        result = (int)bit_or((int)operand1, (int)operand2);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%.4f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "bit_xor") == 0) {
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        result = (int)result;
        result = (int)bit_xor((int)operand1, (int)operand2);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%.4f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "bit_xor") == 0) {
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        result = (int)result;
        result = (int)bit_xor((int)operand1, (int)operand2);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%.4f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "log") == 0) {
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        // cast din gchar in double
        operand2 = atof(op2);
        int imposibil;
        result = logarithm(operand1, operand2, &imposibil);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%.4f", result);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
    }
    if (strcmp(operation, "power") == 0) {
        op2 = gtk_entry_get_text(GTK_ENTRY(entry));
        operand2 = atof(op2);
        int imposibil;
        result = power(operand1, operand2, &imposibil);
        // cast din double in gchar
        gchar *result = g_strdup_printf("%.4f", result);
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
    operation = "add";
}

void make_sub(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "sub";
}

void make_mult(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "mult";
}

void make_div(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "div";
}

void make_modulo(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");

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
    operation = "negation";
    gchar *result = g_strdup_printf("%.4f", operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), result);
}

void make_bit_and(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "bit_and";
}

void make_bit_or(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "bit_or";
}

void make_bit_xor(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "bit_xor";
}

void make_fact(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    operand1 = (int)operand1;
    // clear the text box
    operand1 = factorial(operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "fact";
    gchar *result = g_strdup_printf("%.4f", operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), result);
}

void make_ln(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    int imposibil;
    operand1 = ln(operand1, &imposibil);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "ln";
    gchar *result = g_strdup_printf("%.4f", operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), result);
}

void make_logarithm(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "log";
}

void make_exp(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    operand1 = exponential(operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "exp";
    gchar *result = g_strdup_printf("%.4f", operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), result);
}

void make_power(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "power";
}

void make_sinus(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    int imposibil;
    operand1 = sinus(operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "sinus";
    gchar *result = g_strdup_printf("%.4f", operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), result);
}

void make_cosinus(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    int imposibil;
    operand1 = cosinus(operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "cosinus";
    gchar *result = g_strdup_printf("%.4f", operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), result);
}

void make_tangent(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    int imposibil;
    operand1 = tangent(operand1, &imposibil);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "tan";
    gchar *result = g_strdup_printf("%.4f", operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), result);
}

void make_cotangent(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    int imposibil;
    operand1 = cotangent(operand1, &imposibil);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "cotan";
    gchar *result = g_strdup_printf("%.4f", operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), result);
}

void make_arcsin(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    int imposibil;
    operand1 = arcsin(operand1, &imposibil);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "arcsin";
    gchar *result = g_strdup_printf("%.4f", operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), result);
}

void make_arccos(GtkButton *button, gpointer data) {
    GtkWidget *entry = GTK_WIDGET(data);
    op1 = gtk_entry_get_text(GTK_ENTRY(entry));
    operand1 = atof(op1);
    // clear the text box
    int imposibil;
    operand1 = arccos(operand1, &imposibil);
    gtk_entry_set_text(GTK_ENTRY(entry), "");
    operation = "arccos";
    gchar *result = g_strdup_printf("%.4f", operand1);
    gtk_entry_set_text(GTK_ENTRY(entry), result);
}

void pozitionare_elemente(GtkWidget *grid, GtkWidget *box,
                          GtkWidget *button[32]) {
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
    gtk_grid_attach(GTK_GRID(grid), button[31], 0, 17, 2, 1);

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
    g_signal_connect(button[19], "clicked", G_CALLBACK(make_bit_or), box);
    g_signal_connect(button[20], "clicked", G_CALLBACK(make_bit_xor), box);
    g_signal_connect(button[21], "clicked", G_CALLBACK(make_fact), box);
    g_signal_connect(button[28], "clicked", G_CALLBACK(make_ln), box);
    g_signal_connect(button[29], "clicked", G_CALLBACK(make_logarithm), box);
    g_signal_connect(button[30], "clicked", G_CALLBACK(make_exp), box);
    g_signal_connect(button[31], "clicked", G_CALLBACK(make_power), box);
    g_signal_connect(button[22], "clicked", G_CALLBACK(make_sinus), box);
    g_signal_connect(button[23], "clicked", G_CALLBACK(make_cosinus), box);
    g_signal_connect(button[24], "clicked", G_CALLBACK(make_tangent), box);
    g_signal_connect(button[25], "clicked", G_CALLBACK(make_cotangent), box);
    g_signal_connect(button[26], "clicked", G_CALLBACK(make_arcsin), box);
    g_signal_connect(button[27], "clicked", G_CALLBACK(make_arccos), box);
}

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

    // functie de setare semnal inchidere
    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    // functie de afisare fereastra
    gtk_widget_show_all(main_window);
    // functie de executie
    gtk_main();

    return 0;
}