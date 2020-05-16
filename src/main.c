#include <gtk/gtk.h>
#include <libintl.h>
#include "func.h"

#define _(x) gettext(x)

int main(int argc, char *argv[])
{
    GtkWidget *window, *button, *button1, *vbox;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Игра быки и коровы");
    gtk_container_set_border_width(GTK_CONTAINER(window), 200);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
