//
// Created by linglitel on 24-8-26.
//

#ifndef LAYOUTMANAGER_H
#define LAYOUTMANAGER_H


namespace myui {
    class Container;
    class Widget;
    class LayoutManager;

    class LayoutManager {
    public:
        virtual void layout() =0;
        virtual void init(Container *) = 0;
        virtual int get_layout_width() =0;
        virtual int get_layout_height() =0;

        virtual ~LayoutManager() = default;
    };
}

#endif //LAYOUTMANAGER_H
