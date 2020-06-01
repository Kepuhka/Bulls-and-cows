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
void settings(GtkWidget *widget, gpointer entry);
void init_list(GtkWidget *list);
void close_settings(GtkWidget *widget, gpointer data);
void string(const char *str, const char str2[], char str3[], int bull, int cow);

#endif