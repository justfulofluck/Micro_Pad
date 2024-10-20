#include <gtk/gtk.h>

static void app_button_one(GtkWidget *app, gpointer user_data) {
    g_print("Button one clicked !!\n");
}

static void app_button_two(GtkWidget *app, gpointer user_data) {
    g_print("Button two clicked !!\n");
}

static void app_button_three(GtkWidget *app, gpointer user_data) {
    g_print("Button three clicked !!\n");
}

static void app_button_four(GtkWidget *app, gpointer user_data) {
    g_print("Button four clicked !!\n");
}

static void app_button_five(GtkWidget *app, gpointer user_data) {
    g_print("Button five clicked !!\n");
}

static void app_button_six(GtkWidget *app, gpointer user_data) {
    g_print("Button six clicked !!\n");
}

static void window_module(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button_one;
    GtkWidget *button_two;
    GtkWidget *button_three;
    GtkWidget *button_four;
    GtkWidget *button_five;
    GtkWidget *button_six;
    GtkWidget *label;
    GtkWidget *grid;

    // Create a new application window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "MicroPad");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);


    grid = gtk_grid_new();
    // Create a label to display text
    label = gtk_label_new("Microprocessor name");

    // Create the first button
    button_one = gtk_button_new_with_label("Button 1");
    g_signal_connect(button_one, "clicked", G_CALLBACK(app_button_one), NULL);
    // Create the second button
    button_two = gtk_button_new_with_label("Button 2");
    g_signal_connect(button_two, "clicked", G_CALLBACK(app_button_two), NULL);
    // Create the third button
    button_three = gtk_button_new_with_label("Button 3");
    g_signal_connect(button_three, "clicked", G_CALLBACK(app_button_three), NULL);
    // Create the fourth button
    button_four = gtk_button_new_with_label("Button 4");
    g_signal_connect(button_four, "clicked", G_CALLBACK(app_button_four), NULL);
    // Create the fifth button
    button_five = gtk_button_new_with_label("Button 5");
    g_signal_connect(button_five, "clicked", G_CALLBACK(app_button_five), NULL);
    // Create the sixth button
    button_six = gtk_button_new_with_label("Button 6");
    g_signal_connect(button_six, "clicked", G_CALLBACK(app_button_six), NULL);


    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 2,1);
    gtk_grid_attach(GTK_GRID(grid), button_one, 0, 1, 1,1);
    gtk_grid_attach(GTK_GRID(grid), button_two, 1, 1, 1,1);
    gtk_grid_attach(GTK_GRID(grid), button_three, 2, 1, 1,1);
    gtk_grid_attach(GTK_GRID(grid), button_four, 0, 2, 1,1);
    gtk_grid_attach(GTK_GRID(grid), button_five, 1, 2, 1,1);
    gtk_grid_attach(GTK_GRID(grid), button_six, 2, 2, 1,1);

    gtk_container_add(GTK_CONTAINER(window), grid);

    // Set margins for the label and buttons
    gtk_widget_set_margin_top(label, 20);
    gtk_widget_set_margin_bottom(label, 20);
    gtk_widget_set_margin_start(label, 20);
    
    gtk_widget_set_margin_top(button_one, 20);
    gtk_widget_set_margin_bottom(button_one, 10);
    gtk_widget_set_margin_start(button_one, 20);
    gtk_widget_set_margin_end(button_one, 10);

    gtk_widget_set_margin_top(button_two, 20);
    gtk_widget_set_margin_bottom(button_two, 10);
    gtk_widget_set_margin_start(button_two, 20);
    gtk_widget_set_margin_end(button_two, 10);
    
    gtk_widget_set_margin_top(button_three, 20);
    gtk_widget_set_margin_bottom(button_three, 10);
    gtk_widget_set_margin_start(button_three, 20);
    gtk_widget_set_margin_end(button_three, 10);

    gtk_widget_set_margin_top(button_four, 20);
    gtk_widget_set_margin_bottom(button_four, 10);
    gtk_widget_set_margin_start(button_four, 20);
    gtk_widget_set_margin_end(button_four, 10);

    gtk_widget_set_margin_top(button_five, 20);
    gtk_widget_set_margin_bottom(button_five, 10);
    gtk_widget_set_margin_start(button_five, 20);
    gtk_widget_set_margin_end(button_five, 10);

    gtk_widget_set_margin_top(button_six, 20);
    gtk_widget_set_margin_bottom(button_six, 10);
    gtk_widget_set_margin_start(button_six, 20);
    gtk_widget_set_margin_end(button_six, 10);

    // Show all widgets in the window
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("pynatic.com", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(window_module), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    
    return status;
}