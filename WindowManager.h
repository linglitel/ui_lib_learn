//
// Created by linglitel on 24-9-3.
//

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <wayland-server.h>
#include <wayland-client.h>
#include <wayland-util.h>
#include <iostream>
#include <string>

static wl_display *display;
static wl_registry *registry;
static wl_compositor *compositor;
static wl_surface *surface;

class WindowManager {
public:
    static void create_window();
    static bool init_wayland();
    static void handle_global(void *data, wl_registry *registry, uint32_t id, const char *interface, uint32_t version);
};



#endif //WINDOWMANAGER_H
