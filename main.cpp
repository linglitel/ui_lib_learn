//
// Created by linglitel on 24-9-3.
//

#include <iostream>

#include "Button.h"
#include "Container.h"
#include "Widget.h"
#include "RowLayout.h"
#include "WindowManager.h"

int main(int argc, char *argv[])
{
    using namespace myui;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("LUI Framework",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          1500, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // 创建容器
    Container container;
    container.set_size(1500, 300); // 设置容器的大小
    container.set_position(0, 0); // 设置容器的位置

    // 创建按钮，并设置它们的大小
    auto *button1 = new Button();
    button1->set_size(100, 50);
    button1->set_color(255,0,0,255);

    auto button2 = new Button();
    button2->set_size(400, 50);
    button2->set_color(255,255,0,255);

    auto *button3 = new Button();
    button3->set_size(100, 50);
    button3->set_color(0,0,255,255);

    container.add_child(button1);
    container.add_child(button2);
    container.add_child(button3);

    auto *layout = new RowLayout();
    container.set_layoutManager(layout);
    container.layout();
    container.layout();

    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        container.render(renderer); // 渲染控件

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

int main1() {
    WindowManager::init_wayland();
    WindowManager::create_window();
    while (wl_display_dispatch(display) != -1) {
        // 处理事件
    }
    // 清理资源
    if (surface) {
        wl_surface_destroy(surface);
    }
    if (registry) {
        wl_registry_destroy(registry);
    }
    if (display) {
        wl_display_disconnect(display);
    }
}