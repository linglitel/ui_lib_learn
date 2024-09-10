//
// Created by linglitel on 24-8-26.
//

#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <iostream>

#include "LayoutManager.h"
#include "Widget.h"

namespace myui {
    class Container;
    class Widget;
    class LayoutManager;

    class Container : public Widget {
    public:
        int get_width() override;
        int get_height() override;
        std::vector<Widget *> children;

        void add_child(Widget *child);

        void set_size(int width, int height) override;
        void set_position(int x, int y) override;

        void remove_child(const Widget *child);

        void set_layoutManager(LayoutManager *layoutManager);

        void layout() const;

        void render(SDL_Renderer* renderer) override;

        std::vector<Widget *> &get_children();

        ~Container() override;

        LayoutManager *layoutManager = nullptr;
    };
}


#endif //CONTAINER_H
