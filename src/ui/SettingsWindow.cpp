#include "SettingsWindow.hpp"
#include <gtk4-layer-shell/gtk4-layer-shell.h>

SettingsWindow::SettingsWindow()
{
    gtk_layer_init_for_window(this->gobj());
}

SettingsWindow::~SettingsWindow()
= default;

void SettingsWindow::SetOverlayLayer()
{
    gtk_layer_set_layer(this->gobj(), GTK_LAYER_SHELL_LAYER_OVERLAY);

    gtk_layer_set_anchor(this->gobj(), GTK_LAYER_SHELL_EDGE_LEFT, false);
    gtk_layer_set_anchor(this->gobj(), GTK_LAYER_SHELL_EDGE_RIGHT, false);
    gtk_layer_set_anchor(this->gobj(), GTK_LAYER_SHELL_EDGE_TOP, false);
    gtk_layer_set_anchor(this->gobj(), GTK_LAYER_SHELL_EDGE_BOTTOM, false);

    set_default_size(600, 400);
    set_opacity(0.85);
}

void SettingsWindow::SetKeyboardLayer()
{
    gtk_layer_set_keyboard_mode(this->gobj(), GTK_LAYER_SHELL_KEYBOARD_MODE_ON_DEMAND);
}

void SettingsWindow::ShowWindow()
{
    present();
}