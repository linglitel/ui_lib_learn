//
// Created by linglitel on 24-8-26.
//

#include "Widget.h"

#include <iostream>

namespace myui {

    int myui::Widget::get_position_x() const {
        return posX;
    }

    int myui::Widget::get_position_y() const {
        return posY;
    }

    void Widget::set_position(int x, int y) {
        posX = x;
        posY = y;
    }
}
