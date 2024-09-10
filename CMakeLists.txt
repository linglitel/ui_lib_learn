cmake_minimum_required(VERSION 3.28)
project(ui_lib_learn)

set(CMAKE_CXX_STANDARD 26)

find_package(SDL2 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(WAYLAND_CLIENT REQUIRED wayland-client)

include_directories(${WAYLAND_CLIENT_INCLUDE_DIRS})
link_directories(${WAYLAND_CLIENT_LIBRARY_DIRS})


add_executable(ui_lib_learn main.cpp
        library.cpp
        Container.cpp
        Container.h
        Widget.cpp
        Widget.h
        LayoutManager.h
        RowLayout.cpp
        RowLayout.h
        Button.cpp
        Button.h
        Window.cpp
        Window.h
        WindowManager.cpp
        WindowManager.h
        VulkanManager.cpp
        VulkanManager.h
)

target_link_libraries(ui_lib_learn SDL2::SDL2  ${WAYLAND_CLIENT_LIBRARIES})

#[[add_library(ui_lib_learn SHARED library.cpp
        Container.cpp
        Container.h
        Widget.cpp
        Widget.h
        LayoutManager.h
        RowLayout.cpp
        RowLayout.h
        Button.cpp
        Button.h)]]

