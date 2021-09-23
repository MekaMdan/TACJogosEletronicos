#ifndef RECT_H
#define RECT_H

#include <list>

class Rect{
public:
    float x,y,w,h;

    Rect();
    Rect(float value_x, float value_y, float value_w, float value_h);
    ~Rect();

    bool Contains(std::list <float>);
};

#endif