#ifndef FUNC_H
#define FUNC_H
#define UNUSED(x) (void)x;
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "word.h"
#include "number.h"

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

void destroy(GtkWidget *widget);
void output_error();
void settings(GtkWidget *widget, gpointer entry);
void init_list(GtkWidget *list);
void close_settings(GtkWidget *widget, gpointer data);
void string(const char *str, const char str2[], char str3[], int bull, int cow);

#endif