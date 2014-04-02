//
//  Drawer.h
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/2/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef ___DMT__Drawer__
#define ___DMT__Drawer__

#include <vector>
#include "utils/geometry/Plane.h"
#include "utils/geometry/Point.h"
#include "utils/hardware/Arduino.h"
#include "utils/math/SignalFilter.cpp"
#include "utils/primitives/GLObject.h"

class Drawer: public GLObject
{
public:
    
    PROPERTY(vector<double>, XX, XX);
    PROPERTY(vector<double>, YY, YY);
    PROPERTY(vector<double>, ZZ, ZZ);
    
    PROPERTY(Arduino, arduino, Arduino);
    
    PROPERTY(Plane, planexy, XYPlane);
    PROPERTY(Plane, planexz, XZPlane);
    PROPERTY(Plane, planeyz, YZPlane);
    
    
    Drawer();
    ~Drawer();
    
    virtual void draw();
    
    void init();
    void drawPlanes();
    void drawPoints();
    
    static void process1(SignalFilter::CD *VEC, int SZ);
    static void process2(SignalFilter::CD *VEC, int SZ);
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Drawer.cpp"
#endif

#endif /* defined(___DMT__Drawer__) */
