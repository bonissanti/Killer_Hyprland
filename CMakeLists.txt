cmake_minimum_required(VERSION 4.1)
project(GTK)

find_package(PkgConfig REQUIRED)

#pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(GTK_LAYER_SHELL REQUIRED gtk-layer-shell-0)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

#include_directories(${GTK4_INCLUDE_DIRS})
#link_directories(${GTK4_LIBRARY_DIRS})

#include_directories(${GTKMM-4.0_LIBRARY_DIRS})
#link_directories(${GTKMM-4.0_LIBRARY_DIRS})

set(CMAKE_CXX_STANDARD 26)

add_executable(Killer main.cpp
        src/ui/SettingsWindow.cpp
        src/ui/SettingsWindow.hpp
        src/core/HyprlandIPC.cpp
        src/core/HyprlandIPC.hpp) #TODO: o .hpp vem junto aqui? checar depois

#target_include_directories(Killer PRIVATE ${GTK4_INCLUDE_DIRS})
#target_link_libraries(Killer PRIVATE ${GTK4_LIBRARIES})

target_include_directories(Killer PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_libraries(Killer PRIVATE ${GTKMM_LIBRARIES})
