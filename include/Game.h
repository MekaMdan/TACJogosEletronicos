#include "SDL.h"
#include "State.h"
#include <string>

#define WIDTH 800
#define HEIGHT 600

using namespace std;

class Game {
public:
    static Game& GetInstance();
    void Run();
    SDL_Renderer* GetRenderer(); 
    State& GetState();
    ~Game();
private:
    Game(string title, int width, int height);
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;
    static Game* instance;
};
