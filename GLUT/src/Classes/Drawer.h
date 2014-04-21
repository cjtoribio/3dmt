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
#include <map>
#include "utils/geometry/Plane.h"
#include "utils/geometry/Point.h"
#include "utils/geometry/Line.h"
#include "utils/math/SignalFilter.cpp"
#include "utils/math/Integrator.h"
#include "utils/math/BiasDiscriminator.h"
#include "utils/math/PittySignalCanceller.h"
#include "utils/math/WindowAverager.h"
#include "utils/math/Amplifier.h"
#include "utils/primitives/GLObject.h"
#include "ArduinoBuffer.h"
#include "utils/math/Formulas.h"
#include "Graphics/Drawing.h"

class Drawer: public GLObject
{
    
    PROPERTY_PRIVATE(int, cursor, cursor);
    
    PROPERTY_PRIVATE(map<char COMMA vector<IProcessor*> >, processors, Processors);
    
    PROPERTY_PRIVATE(vector<vec3>, activePoints, ActivePoints);
    
    PROPERTY_PRIVATE(ArduinoBuffer , buff, Buff);

    PROPERTY_PRIVATE(Drawing , drawing, Drawing);
    
public:
    
    
    PROPERTY(Plane, planexy, XYPlane);
    PROPERTY(Plane, planexz, XZPlane);
    PROPERTY(Plane, planeyz, YZPlane);
    
    
    Drawer();
    ~Drawer();
    
    virtual void collectPoints();
    virtual void draw();
    
    void init();
    void drawPlanes();
    void drawCursor();
    void drawPoints();
    void drawDrawings();

    void pressKey(int,int,int);
    
    static void process1(SignalFilter::CD *VEC, int SZ);
    static void process2(SignalFilter::CD *VEC, int SZ);
    static void process3(SignalFilter::CD *VEC, int SZ);
    static void process4(SignalFilter::CD *VEC, int SZ);
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Drawer.cpp"
#endif

#endif /* defined(___DMT__Drawer__) */
