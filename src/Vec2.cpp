#include "Vec2.h"

Vec2::Vec2(){
    x = 0;
    y = 0;
}

Vec2::Vec2(float value_x, float value_y){
    x = value_x;
    y = value_y;
}

Vec2::~Vec2(){

}

Vec2& Vec2::operator= (Vec2& const v){
    x = v.x;
    y = v.y;
    return *this;
}

// Operadores que tem que ser amigos 

Vec2 operator+(Vec2 const &v1, Vec2 const &v2){
    Vec2 resul;
    resul.x = v2.x + v1.x;
    resul.y = v2.y + v1.y;
    return resul;
}

Vec2 operator-(Vec2 const &v1, Vec2 const &v2){
    Vec2 resul;
    resul.x = v1.x - v2.x;
    resul.y = v1.y - v2.y;
    return resul;
}

