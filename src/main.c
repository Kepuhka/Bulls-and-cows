#include "func.h"

int main(int argc, char* argv[])
{
    GtkWidget* vbox;
    GtkWidget* hbox;
    GtkWidget* window;
    GtkWidget* button_ok;
    GtkWidget* label;
    GtkWidget* sw;
    GtkWidget* menubar;
    GtkWidget *game_menu, *game_m;
    GtkWidget *settingMenu, *setting;
    GtkWidget* sep;
    GtkWidget *num, *word;
    GtkWidget *num_rules, *word_rules;
    GtkWidget* quitMi;
    GtkWidget *help_m, *help_menu;
    GtkWidget *rules_menu, *rulesMi;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Bulls and cows");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 330, 400);
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    sw = gtk_scrolled_window_new(NULL, NULL);
    list = gtk_tree_view_new();
    gtk_container_add(GTK_CONTAINER(sw), list);

    gtk_scrolled_window_set_policy(
            GTK_SCROLLED_WINDOW(sw), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(sw), GTK_SHADOW_ETCHED_IN);
    gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list), FALSE);

    hbox = gtk_hbox_new(FALSE, 15);
    vbox = gtk_vbox_new(FALSE, 0);

    label = gtk_label_new("Ответ:");
    button_ok = gtk_button_new_with_label("OK");
    entry = gtk_entry_new();
    gtk_widget_set_size_request(entry, 120, 35);
    gtk_widget_set_size_request(button_ok, 130, 35);

    menubar = gtk_menu_bar_new();
    game_menu = gtk_menu_new();
    game_m = gtk_menu_item_new_with_label("Игра");

    settingMenu = gtk_menu_new();
    setting = gtk_menu_item_new_with_label("Настройки");
    sep = gtk_separator_menu_item_new();
    quitMi = gtk_menu_item_new_with_label("Выход");
    num = gtk_menu_item_new_with_label("Игра с числами");
    word = gtk_menu_item_new_with_label("Игра со словами");

    help_menu = gtk_menu_new();
    help_m = gtk_menu_item_new_with_label("Помощь");

    rules_menu = gtk_menu_new();
    rulesMi = gtk_menu_item_new_with_label("Правила");
    num_rules = gtk_menu_item_new_with_label("Игра с числами");
    word_rules = gtk_menu_item_new_with_label("Игра со словами");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(setting), settingMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(settingMenu), num);
    gtk_menu_shell_append(GTK_MENU_SHELL(settingMenu), word);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(rulesMi), rules_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(rules_menu), num_rules);
    gtk_menu_shell_append(GTK_MENU_SHELL(rules_menu), word_rules);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(game_m), game_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(game_menu), setting);
    gtk_menu_shell_append(GTK_MENU_SHELL(game_menu), sep);
    gtk_menu_shell_append(GTK_MENU_SHELL(game_menu), quitMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), game_m);

    gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), entry, FALSE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), button_ok, FALSE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), sw, TRUE, TRUE, 4);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, TRUE, 5);

    gtk_container_add(GTK_CONTAINER(window), vbox);

    init_list(list);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(help_m), help_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), rulesMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help_m);

    g_signal_connect(G_OBJECT(quitMi), "activate", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(num), "activate", G_CALLBACK(number_activate), NULL);
    g_signal_connect(G_OBJECT(word), "activate", G_CALLBACK(word_activate), NULL);
    g_signal_connect(G_OBJECT(button_ok), "clicked", G_CALLBACK(settings), entry);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(G_OBJECT(num_rules), "activate", G_CALLBACK(show_rules_number), NULL);
    g_signal_connect(G_OBJECT(word_rules), "activate", G_CALLBACK(show_rules_word), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}