#ifndef VEC2_H
#define VEC2_H

class Vec2{
public:
    float x,y;

    Vec2();
    Vec2(float value_x, float value_y);
    ~Vec2();

    Vec2 GetRotated(float angle);
    
    // Operador de atribuição tem de fazer parte da classe
    Vec2& operator= (Vec2& const v);

    // Operadores de soma e subtração 
    friend Vec2 operator+(Vec2 const &v1, Vec2 const &v2);
    friend Vec2 operator-(Vec2 const &v1, Vec2 const &v2);


};

#endif

