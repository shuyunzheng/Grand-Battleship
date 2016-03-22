#include "Application.h"

Application::Application()
{
  
  // Create settings obect
  settings = std::make_shared<FileSettings>();
  
  // Initialize Allgero
  if(!al_init())
  {
    std::cerr << "Error! cannot initialize the allegro library!" << std::endl;
    exit(1); 
  }
  
  w_width  = 840;
  w_height = 560; 
  if((display = al_create_display(w_width, w_height)) == NULL) 
  {
    std::cerr << "Cannot initialize the display" << std::endl;
    exit(1); 
  }
  
  fps = 30;
  if((timer = al_create_timer(1.0 / fps)) == NULL)
  {
     throw std::runtime_error("Cannot create allegro timer");
  }

  if((eventQueue = al_create_event_queue()) == NULL)
  {
    throw std::runtime_error("Cannot create event queue");
  }
  
  if(!al_init_image_addon())
  {
    std::cerr << "Error! cannot initialize the image addon!" << std::endl;
    exit(1); 
  }

  al_register_event_source(eventQueue, al_get_display_event_source(display));
  al_register_event_source(eventQueue, al_get_timer_event_source(timer));
  al_start_timer(timer);
  
  game = std::make_shared<Game>();
}

Application::~Application()
{
  if(timer != NULL)
  {
    al_destroy_timer(timer);
  }
  
  if(eventQueue != NULL)
  {
    al_destroy_event_queue(eventQueue);
  }
  
  if(display != NULL)
  {
    al_destroy_display(display);
  }
}

void Application::run()
{
  while(1)
  {
    ALLEGRO_EVENT event;
    al_wait_for_event(eventQueue, &event);
    if(event.type == ALLEGRO_EVENT_TIMER)
    {
      game->update();
    } 
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
    {
      break;
    }
  }
}


