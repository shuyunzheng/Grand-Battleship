#include "UserShip.h"

UserShip::UserShip(): position(422, 190), velocity(0, 0)
{
  loadImage();
  draw();
}

UserShip::~UserShip()
{
  
}

void UserShip::loadImage()
{
  image = al_load_bitmap("resources/ship.png");
}

void UserShip::update()
{
}

void UserShip::draw()
{
  al_draw_bitmap(image, position.x, position.y, 0);
}

