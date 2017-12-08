#include "MVector.hpp"
#include <math.h>
#include "Constants.hpp"

MVector::MVector():x(0),y(0)
{
    
}

MVector::MVector(int _x,int _y)
{
    x = _x;
    y = _y;
}

MVector::MVector(const MVector &v)
{
    x = v.x;
    y = v.y;
}

//Basic vector operations
void MVector::add(MVector v)
{
    x += v.getX();
    y += v.getY();
}

void MVector::sub(MVector v)
{
    x -= v.getX();
    y -= v.getY();
}

void MVector::mult(float n)
{
    x *= n;
    y *= n;
}

void MVector::div(float n)
{
    x /= n;
    y /= n;
}

float MVector::mag()
{
    return sqrt(x*x + y*y);
}

float MVector::dotProduct(MVector v2)
{
    return (x * v2.getX()) + (y * v2.getY());
}

float MVector::angleBetween(MVector v1,MVector v2)
{
    return acos(v1.dotProduct(v2) / (v1.mag() * v2.mag())) * 180 / PI;
}

float MVector::normalize()
{
    float m = mag();
    if(m != 0)
    {
        div(m);
    }
}

void MVector::limit(float max)
{
    if(mag() > max)
    {
        normalize();
        mult(max);
    }
  
    
    
}


MVector MVector::sub(MVector v1, MVector v2)
{
    MVector newVector(v1.getX() - v2.getX(),v1.getY()-v2.getY());
    return newVector;
    
}

float MVector::distance(MVector v1, MVector v2)
{
    
    int x = pow((v1.getX() - v2.getX()),2);
    int y = pow((v1.getY() - v2.getY()),2);
    return sqrt(x + y);
}

//Setters

void MVector::setX(float _x){x = _x;};

void MVector::setY(float _y){y = _y;};

void MVector::setVector(MVector v)
{
    x = v.getX();
    y = v.getY();
}


//Getters
float MVector::getX(){return x;}
float MVector::getY(){return y;}