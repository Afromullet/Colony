#include <math.h>
#include <stdio.h>

#ifndef MVECTOR_HPP
#define MVECTOR_HPP
class MVector
{

private:
    float x;
    float y;
    
public:
    MVector();
    MVector(int _x,int _y);
    MVector(const MVector &v);

    void add(MVector v);
    void sub(MVector v);
    void mult(float n);
    void div(float n);
    float mag();
    float dotProduct(MVector v2);
    static float angleBetween(MVector v1,MVector v2);
    
    
    float normalize();
    void limit(float max);
    
    void setX(float x);
    void setY(float y);
    void setVector(MVector v);

    float getX();
    float getY();
    
    static MVector sub(MVector v1, MVector v2);
    static float distance(MVector v1, MVector v2);

};

#endif