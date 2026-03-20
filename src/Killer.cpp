//
// Created by bbro on 3/19/26.
//

#include "Killer.hpp"
#include <gtk-4.0/gtk/gtk.h>
#include <gtk4-layer-shell/gtk4-layer-shell.h>
#include <gtk-4.0/gtk/gtkwidget.h>
#include <gtk-4.0/gtk/gtkapplicationwindow.h>

Killer::Killer()
{
    GtkWidget *widget = gtk_application_window_new("Hello World");
}
