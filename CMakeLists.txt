cmake_minimum_required(VERSION 4.1)
project(GTK)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(GTK_LAYER_SHELL REQUIRED gtk-layer-shell-0)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})

set(CMAKE_CXX_STANDARD 26)

add_executable(Killer main.cpp
        src/Killer.cpp
        src/Killer.hpp)

target_include_directories(Killer PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_libraries(Killer PRIVATE ${GTK4_LIBRARIES})