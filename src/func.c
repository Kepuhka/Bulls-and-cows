#include <gtk/gtk.h>
#include <libintl.h>
#include "func.h"
#include <stdlib.h>

void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

void number_activate(GtkMenuItem *menu_item, gpointer data)
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
