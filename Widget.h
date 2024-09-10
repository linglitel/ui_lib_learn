//
// Created by linglitel on 24-8-26.
//

#ifndef WIDGET_H
#define WIDGET_H

#include <SDL2/SDL.h>

namespace myui {
    class Container;
    class Widget;
    class LayoutManager;

    class Widget {
    public:
        virtual ~Widget() = default;

        virtual void set_position(int x, int y) =0;

        virtual void set_size(int width, int height) =0;

        virtual int get_width() =0;

        virtual int get_height() =0;

        [[nodiscard]] int get_position_x() const;

        [[nodiscard]] int get_position_y() const;

        virtual void render(SDL_Renderer *renderer) =0;
        int posX = 0, posY = 0;
        int width = 50, height = 10;
    };
}


#endif //WIDGET_H
