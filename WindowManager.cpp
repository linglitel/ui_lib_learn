//
// Created by linglitel on 24-9-3.
//

#include "WindowManager.h"

#include <cstring>

void WindowManager::create_window() {
    wl_surface *surface = wl_compositor_create_surface(compositor);
    std::cout << "Window created successfully." << std::endl;
}
bool WindowManager::init_wayland() {
    display = wl_display_connect(nullptr);
    if (!display) {
        std::cerr << "Failed to connect to Wayland display" << std::endl;
        return false;
    }

    registry = wl_display_get_registry(display);
    if (!registry) {
        std::cerr << "Failed to get Wayland registry" << std::endl;
        return false;
    }

    wl_registry_listener registry_listener = {handle_global};
    wl_registry_add_listener(registry, &registry_listener, nullptr);

    // 等待 compositor 对象获取完成
    if (wl_display_dispatch(display) == -1 || wl_display_roundtrip(display) == -1) {
        std::cerr << "Failed to dispatch or roundtrip Wayland display" << std::endl;
        return false;
    }

    if (!compositor) {
        std::cerr << "Failed to get Wayland compositor" << std::endl;
        return false;
    }

    return true;
}

// 事件处理回调函数
void WindowManager::handle_global(void *data, wl_registry *registry, uint32_t id, const char *interface, uint32_t version) {
    if (strcmp(interface, wl_compositor_interface.name) == 0) {
        compositor = (wl_compositor *)wl_registry_bind(registry, id, &wl_compositor_interface, 1);
    }
}