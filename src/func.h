#ifndef FUNC_H
#define FUNC_H

enum
{
    LIST_ITEM = 0,
    N_COLUMNS
};

GtkWidget *list;

void destroy(GtkWidget *widget, gpointer data);
void number_activate(GtkMenuItem *menu_item, gpointer data);
void word_activate(GtkMenuItem *menu_item, gpointer data);
void append_item(GtkWidget *widget, gpointer entry);
void init_list(GtkWidget *list);
void number_settings(GtkMenuItem *menu_item, gpointer data);
void close_settings(GtkWidget *widget, gpointer data);

#endif