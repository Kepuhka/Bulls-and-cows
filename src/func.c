#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "func.h"
#include "word.h"
#include "number.h"

void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

void output_error()
{
    GtkWidget *window;
    GtkListStore *store;
    GtkWidget *label;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    label = gtk_label_new("Ошибка!");
    gtk_window_set_title(GTK_WINDOW(window), "");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 230, 50);
    gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);

    gtk_container_add(GTK_CONTAINER(window), label);
    gtk_widget_show_all(window);
}

void close_settings(GtkWidget *widget, gpointer data)
{
    gtk_widget_destroy(data);
}

void settings(GtkWidget *widget, gpointer entry)
{
    if (game_settings == 0)
        append_item_number(widget, entry);
    else
        append_item_word(widget, entry);
}

void init_list(GtkWidget *list)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Input_text", renderer, "text", LIST_ITEM, NULL);

    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    store = gtk_list_store_new(N_COLUMNS, G_TYPE_STRING);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
    g_object_unref(store);
}

void string(const char *str, const char str2[], char str3[], int bull, int cow)
{
    int i;
    for (i = 0; i < num_length; i++)
    {
        str3[i] = str[i];
    }

    strcat(str3, str2);
    i = 0;
    while (str3[i] != '\0')
    {
        if (str3[i] == '*')
        {
            str3[i] = bull + '0';
            break;
        }
        i++;
    }
    while (str3[i] != '\0')
    {
        if (str3[i] == '*')
        {
            str3[i] = cow + '0';
            break;
        }
        i++;
    }
}