#include <iostream>

#include "src/core/HyprlandIPC.hpp"
#include "src/ui/SettingsWindow.hpp"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char **argv)
{
    auto app = Gtk::Application::create("org.gtkmm.examples.base");

    SettingsWindow window;

    // window.SetOverlayLayer();

    return app->make_window_and_run<SettingsWindow>(argc, argv);
}