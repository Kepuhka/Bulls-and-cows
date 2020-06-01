#ifndef WORD_H
#define WORD_H

void show_rules_word();
void word_activate(GtkMenuItem* menu_item);
void append_item_word(GtkWidget* widget, gpointer entry);
void word_settings(GtkMenuItem* menu_item, gpointer data);
char* reading_file(char* way);
char* strtok_string(char* buffer);
int check_user_word(const char userWord[], const int num_length);
void word_comparison(const char randomWord[], const char userWord[], int* bull, int* cow);

#endif