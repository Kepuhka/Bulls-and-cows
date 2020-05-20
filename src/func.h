#ifndef FUNC_H
#define FUNC_H

enum
{
    LIST_ITEM = 0,
    N_COLUMNS
};

int *number_rand;
int num_length;

GtkWidget *list;
GtkWidget *entry;

void destroy(GtkWidget *widget, gpointer data);
void number_activate(GtkMenuItem *menu_item, gpointer data);
void word_activate(GtkMenuItem *menu_item, gpointer data);
void append_item_number(GtkWidget *widget, gpointer entry);
void init_list(GtkWidget *list);
void number_settings(GtkMenuItem *menu_item, gpointer data);
void close_settings(GtkWidget *widget, gpointer data);
int number_splitting(const char *str, int number_user[]);
void number_generate();
void game_number(int a[], int b[], int *bull, int *cow);
void string(const char *str, const char str2[], char str3[], int bull, int cow);

#endif