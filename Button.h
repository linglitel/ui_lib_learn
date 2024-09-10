//
// Created by linglitel on 24-8-26.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "Widget.h"

namespace myui {
    class Button : public Widget {
        void render(SDL_Renderer *renderer) override;

    public:
        int get_width() override;

        int get_height() override;

        void set_size(int width, int height) override;

        void set_position(int x, int y) override;

        void set_color(int r, int g, int b, int a);

        int color_r = 0;
        int color_g = 0;
        int color_b = 0;
        int color_a = 255;
    };
}


#endif //BUTTON_H
