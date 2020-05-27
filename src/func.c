#include <gtk/gtk.h>
#include "func.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

void close_settings(GtkWidget *widget, gpointer data)
{
    gtk_widget_destroy(data);
}

void settings(GtkWidget *widget, gpointer entry)
{
    if (game_settings == 0)
        append_item_number(widget, entry);
    else
        append_item_word(widget, entry);
}

void number_activate(GtkMenuItem *menu_item, gpointer data)
{
    GtkWidget *window;
    GtkWidget *vbox, *hbox;
    GtkWidget *label_1, *label_2;
    GtkWidget *button;
    GtkWidget *spinner;
    GtkAdjustment *spinner_adj;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Игра с числами");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 120);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    vbox = gtk_vbox_new(FALSE, 3);
    hbox = gtk_hbox_new(FALSE, 0);
    label_1 = gtk_label_new("Введите длину числа от 2 до 7");
    label_2 = gtk_label_new("Длина числа:");
    button = gtk_button_new_with_label("OK");
    spinner_adj = (GtkAdjustment *)gtk_adjustment_new(2.0, 2.0, 7.0, 1.0, 1.0, 0);
    spinner = gtk_spin_button_new(spinner_adj, 1.0, 0);
    gtk_widget_set_size_request(spinner, 90, 36);

    gtk_box_pack_start(GTK_BOX(hbox), label_2, FALSE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(hbox), spinner, FALSE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(vbox), label_1, FALSE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 3);

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(number_settings), spinner);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(close_settings), window);

    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);
}

void word_activate(GtkMenuItem *menu_item, gpointer data)
{
    gint size2 = 2;
    gint size3 = 3;

    GtkWidget *window;
    GtkWidget *vbox, *hbox;
    GtkWidget *label;
    GtkWidget *button_3words, *button_4words;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Игра со словами");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 80);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    vbox = gtk_vbox_new(FALSE, 3);
    hbox = gtk_hbox_new(FALSE, 0);
    label = gtk_label_new("Выберите длину слова:");
    button_3words = gtk_button_new_with_label("3 буквы");
    button_4words = gtk_button_new_with_label("4 буквы");
    gtk_widget_set_size_request(button_3words, 100, 30);
    gtk_widget_set_size_request(button_4words, 100, 30);

    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(hbox), button_3words, FALSE, FALSE, 8);
    gtk_box_pack_start(GTK_BOX(hbox), button_4words, FALSE, FALSE, 8);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, TRUE, 3);

    g_signal_connect(G_OBJECT(button_3words), "clicked", G_CALLBACK(word_settings), "3");
    g_signal_connect(G_OBJECT(button_3words), "clicked", G_CALLBACK(close_settings), window);
    g_signal_connect(G_OBJECT(button_4words), "clicked", G_CALLBACK(word_settings), "4");
    g_signal_connect(G_OBJECT(button_4words), "clicked", G_CALLBACK(close_settings), window);

    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);
}

void number_generate()
{
    number_rand = malloc(sizeof(int) * num_length);
    int i, j;
    srand(time(NULL));
    for (i = 0; i < num_length; i++)
    {
        number_rand[i] = (rand() % 10);
        for (j = 0; j < num_length; j++)
        {
            if (number_rand[i] == number_rand[j] && i != j)
            {
                i--;
                break;
            }
        }
    }
}

void number_settings(GtkMenuItem *menu_item, gpointer data)
{
    num_length = gtk_spin_button_get_value(GTK_SPIN_BUTTON((GtkWidget *)data));
    gtk_entry_set_max_length(GTK_ENTRY(entry), num_length);
    game_settings = 0;
    number_generate();
}

void word_settings(GtkMenuItem *menu_item, gpointer data)
{
    char *buffer;
    char way_free_file[] = "src/LibraryFreeWords.txt";
    char way_four_file[] = "src/LibraryFourWords.txt";

    num_length = atoi((char *)data);
    gtk_entry_set_max_length(GTK_ENTRY(entry), num_length);

    if (num_length == 3)
    {
        buffer = reading_file(way_free_file);
    }
    if (num_length == 4)
    {
        buffer = reading_file(way_four_file);
    }
    free(buffer);

    game_settings = 1;
}

int number_splitting(const char *str, int number_user[])
{
    int count = 0;
    int i, j;
    for (i = 0; i < num_length; i++)
    {
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            number_user[count] = str[i] - '0';
            count++;
        }
        else
        {
            return 1;
        }
    }

    for (i = 0; i < num_length; i++)
    {
        for (j = 0; j < num_length; j++)
        {
            if (number_user[i] == number_user[j] && i != j)
            {
                return 1;
            }
        }
    }
    return 0;
}

void append_item_number(GtkWidget *widget, gpointer entry)
{
    GtkListStore *store;
    GtkTreeIter iter;
    const char *str = gtk_entry_get_text(entry);
    const char str2[] = ": Быков *, коров *";
    char str3[50] = "\0";
    const char str4[] = "Вы выиграли!";
    int number_user[num_length];

    struct result
    {
        int bull;
        int cow;
    } num;

    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));
    gtk_list_store_append(store, &iter);

    if (number_splitting(str, number_user) == 0)
    {
        game_number(number_rand, number_user, &num.bull, &num.cow);
        if (num.bull == num_length)
        {
            gtk_list_store_set(store, &iter, LIST_ITEM, str4, -1);
        }
        else
        {
            string(str, str2, str3, num.bull, num.cow);
            gtk_list_store_set(store, &iter, LIST_ITEM, str3, -1);
        }
    }
    else
    {
        const char *fail = "Число введено не правильно!";
        gtk_list_store_set(store, &iter, LIST_ITEM, fail, -1);
    }
    gtk_entry_set_text(entry, "");
}

void append_item_word(GtkWidget *widget, gpointer entry)
{
}

void init_list(GtkWidget *list)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Input_text", renderer, "text", LIST_ITEM, NULL);

    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    store = gtk_list_store_new(N_COLUMNS, G_TYPE_STRING);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
    g_object_unref(store);
}

void game_number(int a[], int b[], int *bull, int *cow)
{
    int i, j;

    *bull = 0;
    *cow = 0;
    for (i = 0; i < num_length; i++)
    {
        for (j = 0; j < num_length; j++)
        {
            if (a[i] == b[j] && i == j)
            {
                (*bull)++;
            }
            if (a[i] == b[j] && i != j)
            {
                (*cow)++;
            }
        }
    }
}

void string(const char *str, const char str2[], char str3[], int bull, int cow)
{
    int i;
    for (i = 0; i < num_length; i++)
    {
        str3[i] = str[i];
    }

    strcat(str3, str2);
    i = 0;
    while (str3[i] != '\0')
    {
        if (str3[i] == '*')
        {
            str3[i] = bull + '0';
            break;
        }
        i++;
    }
    while (str3[i] != '\0')
    {
        if (str3[i] == '*')
        {
            str3[i] = cow + '0';
            break;
        }
        i++;
    }
}

char *reading_file(char *way)
{
    FILE *fileLibrary;

    fileLibrary = fopen(way, "r");
    if (fileLibrary == NULL)
        return NULL;

    const int size = 200;
    char *buffer;
    buffer = (char *)malloc(size * sizeof(char));
    char *n = fgets(buffer, size, fileLibrary);
    fclose(fileLibrary);
    return buffer;
}