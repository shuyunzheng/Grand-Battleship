#ifndef __VECTOR_H
#define __VECTOR_H

struct Vector 
{
  double x;
  double y;
  
  // Constructor, takes two scalar values
  Vector(double a=0.0, double b=0.0) : x(a), y(b) 
  {
  };

  // Method to overload * operator, returns a new Vector object
  Vector operator *(double scalar)
  {
    return Vector(x*scalar, y*scalar);
  }
}; 

#endif
