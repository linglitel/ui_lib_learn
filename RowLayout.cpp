//
// Created by linglitel on 24-8-26.
//

#include "RowLayout.h"

#include "Container.h"

namespace myui {
    void RowLayout::layout() {
        totalWidth = get_layout_width();
        childCount = int(container->get_children().size());
        int containerWidth = container->width;

        //TODO 内边距与外边距需要添加

        int positionY = container->get_position_y();
        int currentX = container->get_position_x();
        std::cout << totalWidth << " " << containerWidth << std::endl;
        float scaleFactor = 1.0f;
        if (totalWidth > containerWidth) {
            scaleFactor = float(containerWidth) / float(totalWidth);
        }
        for (auto *child: container->get_children()) {
            int c_height = child->get_height();
            int c_widht = child->get_width();
            totalWidth += child->get_width();
            int width = int(float(c_widht) * scaleFactor);
            child->set_position(currentX, positionY);
            child->set_size(width, c_height);
            currentX += width;
        }
    }

    void RowLayout::init(Container *container) {
        this->container = container;
    }

    void RowLayout::set_spacing(int spacing) {
        this->spacing = spacing;
    }

    int RowLayout::get_layout_width() {
        totalWidth = 0;
        totalSpacing = (childCount - 1) * spacing;
        for (auto *child: container->get_children()) {
            if (child == nullptr) {
                continue;
            }
            std::cout << child->get_width() << std::endl;
            totalWidth += child->get_width();
        }
        int totalContentWidth = totalWidth + totalSpacing;
        return totalContentWidth;
    }

    int RowLayout::get_layout_height() {
        totalHeight = 0;
        for (auto *child: container->get_children()) {
            if (child == nullptr) {
                continue;
            }
            totalHeight += child->get_height();
        }
        int totalContentHeight = totalHeight;
        return totalContentHeight;
    }
}
