#ifndef __USERSHIP_H
#define __USERSHIP_H

#include <allegro5/allegro.h>

#include "Point.h"
#include "Vector.h"
#include "GameObject.h"

class UserShip: public GameObject 
{
    const double MAX_SPEED = 80; // 80 pixels per sec
    
    ALLEGRO_BITMAP *image;
    Point position;
    Vector velocity;
    
  public:
    UserShip();
    ~UserShip();
    void loadImage();
    void update();
    void draw();
};

#endif
 
