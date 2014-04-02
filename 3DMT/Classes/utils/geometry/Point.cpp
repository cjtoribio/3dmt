#include "Point.h"

Point::Point()
{
    
}

Point::Point(float _x, float _y, float _z)
{
    setPosition(vec3(_x, _y, _z));
    radius = 0.3;
}

Point::~Point()
{
    
}

void Point::draw()
{
    glPushMatrix();
    glColor3f(_color.r, _color.g, _color.b);
    glTranslatef(getPosition().x, getPosition().y, getPosition().z);
    glutSolidSphere(radius, 3, 3);
    glPopMatrix();
}