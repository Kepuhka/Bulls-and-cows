#include "func.h"

void number_settings(GtkMenuItem* menu_item, gpointer data)
{
    num_length = gtk_spin_button_get_value(GTK_SPIN_BUTTON((GtkWidget*)data));
    gtk_entry_set_max_length(GTK_ENTRY(entry), num_length);
    game_settings = 0;
    number_generate();
    gtk_widget_set_sensitive(entry, TRUE);
    clear_list();
    UNUSED(menu_item);
}

void show_rules_number()
{
    GtkWidget* window;
    GtkWidget* label;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    label = gtk_label_new(
            " Компьютер задумывает n различных\n цифр от 0 до 9."
            "Игрок делает ходы,\n чтобы узнать эти цифры и их порядок.\n Каждый ход состоит из n "
            "цифр,"
            "\n 0 может стоять на первом месте.\n В ответ компьютер показывает число\n отгаданных "
            "цифр, стоящих "
            "на своих\n местах (число быков) и число отгаданных \n цифр, стоящих не на своих "
            "местах\n (число коров).\n"
            " n - выбранное кол-во цифр в числе\n");
    gtk_window_set_title(GTK_WINDOW(window), "Правила игры с числами ");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 230, 50);
    gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);

    gtk_container_add(GTK_CONTAINER(window), label);
    gtk_widget_show_all(window);
}

void number_activate(GtkMenuItem* menu_item)
{
    GtkWidget* window;
    GtkWidget *vbox, *hbox;
    GtkWidget *label_1, *label_2;
    GtkWidget* button;
    GtkWidget* spinner;
    GtkAdjustment* spinner_adj;

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
    spinner_adj = (GtkAdjustment*)gtk_adjustment_new(2.0, 2.0, 7.0, 1.0, 1.0, 0);
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
    UNUSED(menu_item);
}

void number_generate()
{
    number_rand = malloc(sizeof(int) * num_length);
    int i, j;
    srand(time(NULL));
    for (i = 0; i < num_length; i++) {
        number_rand[i] = (rand() % 10);
        for (j = 0; j < num_length; j++) {
            if (number_rand[i] == number_rand[j] && i != j) {
                i--;
                break;
            }
        }
    }
}

int number_splitting(const char* str, int number_user[])
{
    int count = 0;
    int i, j;
    for (i = 0; i < num_length; i++) {
        if ((str[i] >= '0') && (str[i] <= '9')) {
            number_user[count] = str[i] - '0';
            count++;
        } else {
            return 1;
        }
    }

    for (i = 0; i < num_length; i++) {
        for (j = 0; j < num_length; j++) {
            if (number_user[i] == number_user[j] && i != j) {
                return 1;
            }
        }
    }
    return 0;
}

void append_item_number(GtkWidget* widget, gpointer entry)
{
    GtkListStore* store;
    GtkTreeIter iter;
    const char* str = gtk_entry_get_text(entry);
    const char str2[] = ": Быков *, коров *";
    char str3[50] = "\0";
    const char str4[] = "Вы выиграли!";
    int number_user[num_length];

    struct result {
        int bull;
        int cow;
    } num;

    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(list)));
    gtk_list_store_append(store, &iter);

    if (number_splitting(str, number_user) == 0) {
        game_number(number_rand, number_user, &num.bull, &num.cow);
        if (num.bull == num_length) {
            gtk_list_store_set(store, &iter, LIST_ITEM, str4, -1);
            gtk_widget_set_sensitive(entry, FALSE);
            num_length = 0;
        } else {
            string(str, str2, str3, num.bull, num.cow);
            gtk_list_store_set(store, &iter, LIST_ITEM, str3, -1);
        }
    } else {
        const char* fail = "Число введено не правильно!";
        gtk_list_store_set(store, &iter, LIST_ITEM, fail, -1);
    }
    gtk_entry_set_text(entry, "");
    UNUSED(widget);
}

void game_number(int a[], int b[], int* bull, int* cow)
{
    int i, j;

    *bull = 0;
    *cow = 0;
    for (i = 0; i < num_length; i++) {
        for (j = 0; j < num_length; j++) {
            if (a[i] == b[j] && i == j) {
                (*bull)++;
            }
            if (a[i] == b[j] && i != j) {
                (*cow)++;
            }
        }
    }
}