#ifndef __SCOREBOARD_H
#define __SCOREBOARD_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "Point.h"
#include "GameObject.h"

class ScoreBoard: public GameObject 
{
    ALLEGRO_FONT *font;
    
    Point position;
    int width, height;
    
  public:
    ScoreBoard();
    ~ScoreBoard();
    
    void loadFont();
    
    void update();
    void draw();
};

#endif
 
 
