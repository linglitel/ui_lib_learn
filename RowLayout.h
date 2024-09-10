//
// Created by linglitel on 24-8-26.
//

#ifndef ROWLAYOUT_H
#define ROWLAYOUT_H

#include <iostream>
#include "LayoutManager.h"

namespace myui {
    class RowLayout : public LayoutManager {
    public:
        void layout() override;

        void init(Container *) override;

        void set_spacing(int);

        int get_layout_width() override;
        int get_layout_height() override;

        int spacing = 0;
        int childCount = 0;
        int totalWidth = 0;
        int totalHeight = 0;
        int totalSpacing = 0;
        Container *container = nullptr;
    };
}

#endif //ROWLAYOUT_H
