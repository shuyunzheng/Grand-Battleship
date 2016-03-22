#ifndef __SUBMARINE_H
#define __SUBMARINE_H

#include <allegro5/allegro.h>

#include "Point.h"
#include "Vector.h"
#include "GameObject.h"

class Submarine: public GameObject 
{
    const double MAX_SPEED = 80; // 80 pixels per sec
    
    enum Sub_Type {YELLOW, YELLOW_BLUE, GREY, ORANGE, RED};
    
    ALLEGRO_BITMAP *image1, *image2, *image3, *image4, *image5;
    Sub_Type type;
    Point position;
    Vector velocity;
    
  public:
    Submarine();
    ~Submarine();
    void loadImage();
    void update();
    void draw();
};

#endif
 
 
