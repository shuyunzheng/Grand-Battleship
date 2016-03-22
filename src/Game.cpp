#include "Game.h"

Game::Game()
{
  loadBackground();
  drawBackground();
  
  list.insert(list.begin(), std::make_shared<UserShip>());
  list.insert(list.begin(), std::make_shared<ScoreBoard>());
  list.insert(list.begin(), std::make_shared<Submarine>());
  
  al_flip_display();
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
