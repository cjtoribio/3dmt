#include "Point.h"

Point::Point()
{
    
}

Point::Point(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
    radius = 0.3;
}

Point::~Point()
{
    
}

void Point::draw()
{
    glPushMatrix();
    glColor3f(_color.r, _color.g, _color.b);
    glTranslatef(x, y, z);
    glutSolidSphere(radius, 3, 3);
    glPopMatrix();
}