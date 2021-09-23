#include "Rect.h"

Rect::Rect(){
    
}

Rect::Rect(float value_x, float value_y, float value_w, float value_h){
    x = value_x;
    y = value_y;
    w = value_w;
    h = value_h;
}

Rect::~Rect(){
    
}

Rect& Rect::operator= (Rect& const r){
    x = r.x;
    y = r.y;
    w = r.w;
    h = r.h;
    return *this;
}
 
Rect operator+(Rect const &r1, Rect const &r2){
    Rect resul;
    resul.x = r1.x + r2.x;
    resul.y = r1.y + r2.y;
    resul.w = r1.w + r2.w;
    resul.h = r1.h + r2.h;
    return resul;
}

Rect operator-(Rect const &r1, Rect const &r2){
    Rect resul;
    resul.x = r1.x - r2.x;
    resul.y = r1.y - r2.y;
    resul.w = r1.w - r2.w;
    resul.h = r1.h - r2.h;
    return resul;
}
