#include "Submarine.h"

Submarine::Submarine(): position(375, 520), velocity(0, 0)
{
  type = YELLOW;
  loadImage();
  draw();
}

Submarine::~Submarine()
{
  
}

void Submarine::loadImage()
{
  image1 = al_load_bitmap("resources/sub_1.png");
  image2 = al_load_bitmap("resources/sub_2.png");
  image3 = al_load_bitmap("resources/sub_3.png");
  image4 = al_load_bitmap("resources/sub_4.png");
  image5 = al_load_bitmap("resources/sub_5.png");
  /*
  switch(static_cast<int>(type))
  {
    case 1:
      image = al_load_bitmap("resources/sub_1.png");
      break;
    case 2:
      image = al_load_bitmap("resources/sub_2.png");
      break;
    case 3:
      image = al_load_bitmap("resources/sub_3.png");
      break;
    case 4:
      image = al_load_bitmap("resources/sub_4.png");
      break;
    case 5:
      image = al_load_bitmap("resources/sub_5.png");
      break;
  }
  */
}

void Submarine::update()
{
}

void Submarine::draw()
{
  al_draw_bitmap(image1, position.x, position.y, 0);
  al_draw_bitmap(image2, 20, position.y, 0);
  al_draw_bitmap(image3, 160, position.y, 0);
  al_draw_bitmap(image4, 520, position.y, 0);
  al_draw_bitmap(image5, 700, position.y, 0);
}

 
