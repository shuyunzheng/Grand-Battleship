#ifndef __APPLICATION_H
#define __APPLICATION_H

#include <memory>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "allegro5/allegro_image.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "FileSettings.h"
#include "MainUI.h"
#include "SettingsUI.h"
#include "Game.h"

class Application 
{
  std::shared_ptr<Settings> settings;
  std::shared_ptr<Game> game;
  
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_EVENT_QUEUE *eventQueue;  // event storage 
  ALLEGRO_TIMER *timer;             // generates events for the simulation
  int w_width, w_height;
  int fps;
  
  public:
    Application(); 
    ~Application();
    void run();
};

#endif 
