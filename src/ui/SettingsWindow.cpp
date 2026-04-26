#include "SettingsWindow.hpp"
#include <gtk4-layer-shell/gtk4-layer-shell.h>

SettingsWindow::SettingsWindow()
{
    auto css_provider = Gtk::CssProvider::create();

    css_provider->load_from_string("window { background-color: rgba(9, 0, 31, 0.8); border: 3px solid rgba(21, 210, 235, 1); border-radius: 10px; }");
    Gtk::StyleContext::add_provider_for_display(
        get_display(),
        css_provider,
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_layer_init_for_window(this->gobj());
    gtk_layer_set_layer(this->gobj(), GTK_LAYER_SHELL_LAYER_OVERLAY);
    set_default_size(1000, 800);
    set_title("Killer");
    set_opacity(0.85);

    //TODO: m_main_widget needs to be more white
    m_overlay.set_child(m_main_widget);
    set_child(m_overlay);
}

SettingsWindow::~SettingsWindow()
= default;

// void SettingsWindow::SetOverlayLayer()    // m_overlay.set_child(m_main_widget);
//    // set_child(m_overlay);
// {
//     gtk_layer_set_layer(this->gobj(), GTK_LAYER_SHELL_LAYER_OVERLAY);
//
//     gtk_layer_set_anchor(this->gobj(), GTK_LAYER_SHELL_EDGE_LEFT, false);
//     gtk_layer_set_anchor(this->gobj(), GTK_LAYER_SHELL_EDGE_RIGHT, false);
//     gtk_layer_set_anchor(this->gobj(), GTK_LAYER_SHELL_EDGE_TOP, false);
//     gtk_layer_set_anchor(this->gobj(), GTK_LAYER_SHELL_EDGE_BOTTOM, false);
//
//     set_default_size(600, 400);
//     set_title("Killer");
//     set_opacity(0.85);
// }
//
void SettingsWindow::SetKeyboardLayer()
{
    gtk_layer_set_keyboard_mode(this->gobj(), GTK_LAYER_SHELL_KEYBOARD_MODE_ON_DEMAND);
}

void SettingsWindow::ShowWindow()
{
    present();
}