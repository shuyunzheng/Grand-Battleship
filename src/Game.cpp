#include "Game.h"

Game::Game()
{
  loadBackground();
  draw();
}

Game::~Game()
{
}

void Game::loadBackground()
{
  background = al_load_bitmap("resources/background.png");
}

void Game::drawBackground()
{
  al_draw_bitmap(background, 0, 0, 0);
}

void Game::update()
{
}

void Game::draw()
{
  drawBackground();
  
  al_flip_display();
}
