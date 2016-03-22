#ifndef __POINT_H
#define __POINT_H

#include "Vector.h"

struct Point 
{
  double x;
  double y;
  
  // Constructor, takes two params
  Point(double a=0.0, double b=0.0): x(a), y(b) 
  {
  };
  
  // Method to overload + operator
  Point operator +(Vector v) 
  {
    return Point(x+v.x, y+v.y);
  }
};

#endif
