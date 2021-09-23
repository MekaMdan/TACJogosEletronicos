#ifndef VEC2_H
#define VEC2_H

class Vec2{
public:
    float x,y;

    Vec2();
    Vec2(float value_x, float value_y);
    ~Vec2();

    Vec2 GetRotated(float angle);        
};

#endif

