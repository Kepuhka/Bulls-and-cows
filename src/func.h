#ifndef FUNC_H
#define FUNC_H

enum
{
    LIST_ITEM = 0,
    N_COLUMNS
};

int game_settings;
int *number_rand;
char *word_rand;
int num_length;

GtkWidget *list;
GtkWidget *entry;

void destroy(GtkWidget *widget, gpointer data);
void output_error();
void number_activate(GtkMenuItem *menu_item, gpointer data);
void settings(GtkWidget *widget, gpointer entry);
void word_activate(GtkMenuItem *menu_item, gpointer data);
void append_item_number(GtkWidget *widget, gpointer entry);
void append_item_word(GtkWidget *widget, gpointer entry);
void init_list(GtkWidget *list);
void number_settings(GtkMenuItem *menu_item, gpointer data);
void word_settings(GtkMenuItem *menu_item, gpointer data);
void close_settings(GtkWidget *widget, gpointer data);
int number_splitting(const char *str, int number_user[]);
void number_generate();
void game_number(int a[], int b[], int *bull, int *cow);
void string(const char *str, const char str2[], char str3[], int bull, int cow);
char *reading_file(char *way);
char *strtok_string(char *buffer);
int check_user_word(const char userWord[], const int num_length);
void word_comparison(const char randomWord[], const char userWord[], int *bull, int *cow);

#endif