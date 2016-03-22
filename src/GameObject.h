#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H

class GameObject 
{
  public:
    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif
