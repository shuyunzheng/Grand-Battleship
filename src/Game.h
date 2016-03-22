#ifndef __GAME_H
#define __GAME_H

#include <allegro5/allegro.h>

class Game 
{
  ALLEGRO_BITMAP *background;
  
  public:
    Game();
    ~Game();
    void loadBackground();
    void drawBackground();
    
    void update();
    void draw();
};

#endif
