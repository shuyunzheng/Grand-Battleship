#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(): position(0, 0), width(960), height(80)
{
  loadFont();
  draw();
}

ScoreBoard::~ScoreBoard()
{
  
}

void ScoreBoard::loadFont()
{
  font = al_load_ttf_font("resources/OpenSans-Regular.ttf", 24, 0);
}

void ScoreBoard::update()
{
}

void ScoreBoard::draw()
{
  al_draw_filled_rectangle(position.x + 1, position.y + 1, position.x + width - 1, position.y + 80 - 1,  al_map_rgb(223, 230, 192));
  al_draw_rectangle(position.x, position.y, position.x + width, position.y + 80,  al_map_rgb(255, 128, 0), 1);
  al_draw_text(font, al_map_rgb(25,25,25), 480, 10, ALLEGRO_ALIGN_CENTRE, "Scoreboard");
}

 
