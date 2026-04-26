//
// Created by bbro on 3/19/26.
//

#ifndef GTK_OVERLAYWINDOW_HPP
#define GTK_OVERLAYWINDOW_HPP
#include <gtkmm-4.0/gtkmm.h>

/*  SettingsWindow:
 *
 *  m_overlay: Gtk::Overlay for managing window layers
 *  m_main_widget: Main content widget displayed within the overlay
 *
*/

class SettingsWindow : public Gtk::Window
{
private:
    Gtk::Overlay m_overlay;
    Gtk::Label m_main_widget{"The enemy #1 from @#$%"};

public:
    SettingsWindow();
    ~SettingsWindow() override;
    void SetKeyboardLayer();
    void ShowWindow();
};

#endif //GTK_OVERLAYWINDOW_HPP