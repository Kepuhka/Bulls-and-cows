#include <gtk/gtk.h>
#include <libintl.h>
#include "func.h"

void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}