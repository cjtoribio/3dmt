#include "Point.h"

Point::Point()
{
    x = 0;
    y = 0;
    z = 0;
    radius = 0.5;
}

Point::Point(vec3 v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    radius = 0.5;
}

Point::Point(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
    radius = 0.5;
}

Point::~Point()
{
    
}

void Point::draw()
{
    glPushMatrix();
    glColor3f(_color.r, _color.g, _color.b);
    glTranslatef(x, y, z);
    glutSolidSphere(radius, 5, 5);
    glPopMatrix();
}
