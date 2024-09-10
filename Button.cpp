//
// Created by linglitel on 24-8-26.
//

#include "Button.h"

#include <iostream>

namespace myui {
    void Button::render(SDL_Renderer *renderer) {
        //std::cout << "Button X: " << posX << " Y: " << posY << std::endl;
        SDL_Rect rect = {posX, posY, width, height};
        SDL_SetRenderDrawColor(renderer, color_r, color_g, color_b, color_a); // 蓝色按钮
        SDL_RenderFillRect(renderer, &rect);
    }

    int Button::get_width() {
        return width;
    }

    int Button::get_height() {
        return height;
    }

    void Button::set_size(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void Button::set_position(int x, int y) {
        posX = x;
        posY = y;
    }

    void Button::set_color(int r, int g, int b, int a) {
        color_r = r;
        color_b = b;
        color_g = g;
        color_a = a;
    }
}
