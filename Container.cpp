//
// Created by linglitel on 24-8-26.
//

#include "Container.h"

namespace myui {
    Container::~Container() {
        for (auto *child: children) {
            delete child;
        }
    }

    std::vector<Widget *> &Container::get_children() {
        return children;
    }

    void Container::remove_child(const Widget *child) {
        auto it = std::find(children.begin(), children.end(), child);
        if (it != children.end()) {
            children.erase(it);
            delete child;
        }
    }

    int Container::get_width() {
        return layoutManager->get_layout_width();
    }

    int Container::get_height() {
        return layoutManager->get_layout_height();
    }

    void Container::add_child(Widget *child) {
        children.push_back(child);
    }

    void Container::set_size(int width, int height) {
        this->width=width;
        this->height=height;
    }

    void Container::set_position(int x, int y) {
        posX=x;
        posY=y;
        if (layoutManager==nullptr) {
            return;
        }
        layoutManager->layout();
    }

    void Container::set_layoutManager(LayoutManager *layoutManager) {
        this->layoutManager = layoutManager;
        this->layoutManager->init(this);
    }

    void Container::layout() const {
        if (layoutManager) {
            layoutManager->layout();
        }
    }

    void Container::render(SDL_Renderer *renderer) {
        for (auto *child: children) {
            child->render(renderer); // 渲染每个子控件
        }
    }
}
