#include <gtk/gtk.h>
#include <libintl.h>
#include "func.h"
#define _(x) gettext(x)

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