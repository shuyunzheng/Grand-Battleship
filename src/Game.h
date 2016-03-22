#ifndef __GAME_H
#define __GAME_H

#include <memory>
#include <vector>
#include <allegro5/allegro.h>

#include "GameObject.h"
#include "UserShip.h"
#include "ScoreBoard.h"
#include "Submarine.h"


class Game 
{
  ALLEGRO_BITMAP *background;
  
  std::vector<std::shared_ptr<GameObject>> list;
  
  public:
    Game();
    ~Game();
    void loadBackground();
    void drawBackground();
    
    void update();
    void draw();
};

#endif
