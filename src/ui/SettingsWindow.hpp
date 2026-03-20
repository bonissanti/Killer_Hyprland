//
// Created by bbro on 3/19/26.
//

#ifndef GTK_OVERLAYWINDOW_HPP
#define GTK_OVERLAYWINDOW_HPP
// #include <gtk/gtktypes.h>
#include <gtkmm-4.0/gtkmm.h>

class SettingsWindow : public Gtk::Window
{
public:
    SettingsWindow();
    ~SettingsWindow();
    void SetOverlayLayer();
    void SetKeyboardLayer();
    void ShowWindow();
};

#endif //GTK_OVERLAYWINDOW_HPP