#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include <string>
#include "Component.h"

using namespace std;

class Sprite : public Component{
public:
    Sprite(GameObject& associated);
    Sprite(GameObject& associated, string file);
    ~Sprite();
    void Open(string file);
    void SetClip(int x, int y, int w, int h);
    void Render();
    bool Is(string type);
    void Update(float dt);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
private:
    SDL_Texture* texture;
    int width;
    int height;                                                
    SDL_Rect clipRect;
};

#endif