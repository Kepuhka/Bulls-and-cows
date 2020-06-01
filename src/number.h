#ifndef NUMBER_H
#define NUMBER_H

void show_rules_number();
void number_activate(GtkMenuItem *menu_item);
void append_item_number(GtkWidget *widget, gpointer entry);
void number_settings(GtkMenuItem *menu_item, gpointer data);
int number_splitting(const char *str, int number_user[]);
void number_generate();
void game_number(int a[], int b[], int *bull, int *cow);

#endif