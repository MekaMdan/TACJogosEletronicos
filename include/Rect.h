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

    // Operador de atribuição tem de fazer parte da classe
    Rect& operator= (Rect& const r);

    // Operadores de soma e subtração 
    friend Rect operator+(Rect const &r1, Rect const &r2);
    friend Rect operator-(Rect const &r1, Rect const &r2);
};

#endif