#ifndef FUNC_H
#define FUNC_H

enum
{
    LIST_ITEM = 0,
    N_COLUMNS 
};

int *number_user;
int *number_rand;
int num_length;
int cow, bull;

GtkWidget *list;
GtkWidget *entry;

void destroy(GtkWidget *widget, gpointer data);
void number_activate(GtkMenuItem *menu_item, gpointer data);
void word_activate(GtkMenuItem *menu_item, gpointer data);
void append_item_number(GtkWidget *widget, gpointer entry);
void init_list(GtkWidget *list);
void number_settings(GtkMenuItem *menu_item, gpointer data);
void close_settings(GtkWidget *widget, gpointer data);
int number_splitting(const char *str);
void number_generate();
int game_number(int a[], int b[]);
char *string(const char *str, char str2[], char str3[]);

#endif