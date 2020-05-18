#include <gtk/gtk.h>
#include <libintl.h>
#include "func.h"
#include <stdlib.h>

void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

void close_settings(GtkWidget *widget, gpointer data)
{
    gtk_widget_destroy(data);
}

void number_activate(GtkMenuItem *menu_item, gpointer data)
{
    GtkWidget *window;
    GtkWidget *vbox, *hbox;
    GtkWidget *label_1, *label_2;
    GtkWidget *button;
    GtkWidget *entry;
    GtkWidget *spinner;
    GtkAdjustment *spinner_adj;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Игра с числами");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 120);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    vbox = gtk_vbox_new(FALSE, 3);
    hbox = gtk_hbox_new(FALSE, 0);
    label_1 = gtk_label_new("Введите длину числа от 2 до 7");
    label_2 = gtk_label_new("Длина числа:");
    entry = gtk_entry_new();
    button = gtk_button_new_with_label("OK");
    spinner_adj = (GtkAdjustment *) gtk_adjustment_new (2.0, 2.0, 7.0, 1.0, 1.0, 0);
    spinner = gtk_spin_button_new(spinner_adj, 1.0, 0);
    gtk_widget_set_size_request(spinner, 90, 36);
    
    gtk_box_pack_start(GTK_BOX(hbox), label_2, FALSE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(hbox), spinner, FALSE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(vbox), label_1, FALSE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 3);

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(number_settings), spinner);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(close_settings), window);

    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);
}

void number_settings(GtkMenuItem *menu_item, gpointer data)
{
    int num = gtk_spin_button_get_value(GTK_SPIN_BUTTON((GtkWidget *)data));
    printf("%d\n", num);
}

void word_activate(GtkMenuItem *menu_item, gpointer data)
{
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Игра с числами");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);
    gtk_widget_show(window);
}

void append_item(GtkWidget *widget, gpointer entry)
{
    GtkListStore *store;
    GtkTreeIter iter;
    const gchar *str = gtk_entry_get_text(entry);

    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, LIST_ITEM, str, -1);
    gtk_entry_set_text(entry, "");
}

void init_list(GtkWidget *list)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("List Item", renderer, "text", LIST_ITEM, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    store = gtk_list_store_new(N_COLUMNS, G_TYPE_STRING);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
    g_object_unref(store);
}
