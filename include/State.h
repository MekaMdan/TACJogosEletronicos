#ifndef STATE_H
#define STATE_H


#include "Sprite.h"
#include "Music.h"
#include <memory>

class State{
public:
    State();
    ~State();

    void Input();
    void AddObject(int mouseX, int mouseY);
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
private:
    Sprite bg;
    Music music;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;
};

#endif