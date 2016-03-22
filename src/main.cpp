#include <memory>
#include <allegro5/allegro.h>
#include "Application.h"

int main()
{
  std::shared_ptr<Application> app = std::make_shared<Application>();
  
  app->run();
  
  return 0;
}

