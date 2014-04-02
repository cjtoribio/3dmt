//
//  SpecialKeys.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/10/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef OpenGL_SpecialKeys_h
#define OpenGL_SpecialKeys_h

#if defined(__APPLE__) && defined(__MACH__)
#   include <OpenGL/gl.h>
#   include <OpenAL/al.h>
#   include <OpenAL/alc.h>
#   include <GLUT/glut.h>
#else
#   include <GL/glut.h>
#   include <GL/gl.h>
#endif

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 980
#define WINDOW_TITLE "3D Modeling Tool"
#define BUFFMAX 256
#define ENDOFLN '\n'
#define TIMEOUT 5000

#define glv3(x, y, z) GLVec3(x, y, z)
#define glv4(x, y, z, w) GLVec4(x, y, z, w)

#define GLVEC3_ZERO glv3(0.0, 0.0, 0.0)
#define GLVEC4_ZERO glv4(0.0, 0.0, 0.0, 0.0)
#define GLCAMERA_VEC3ZERO glv3(0.0, 0.0, -100.0)
#define GLCAMERA_VEC3UP glv3(0.0, 1.0, 0.0)

#define SYNTHESIZE_BOOLEAN(varType, varName, funName)\
protected: varType varName;\
public: virtual varType is##funName(void) const { return varName; }\
public: virtual void set##funName(varType var){ varName = var; }

#define SYNTHESIZE(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void) const { return varName; }\
public: virtual void set##funName(varType var){ varName = var; }

#define CREATE_METHOD(className, initFunc, methodArgs, constructorArgs, initArgs) \
static className* create methodArgs \
{ \
    className *instance = new className constructorArgs; \
    if(instance->initFunc initArgs) \
        return instance; \
    else return 0; \
}; \

#define glc(r, g, b) GLColor(r, g, b)
#define BLACK glc(0.0, 0.0, 0.0)
#define WHITE glc(1.0, 1.0, 1.0)
#define RED glc(1.0, 0.0, 0.0)
#define GREEN glc(0.0, 1.0, 0.0)
#define BLUE glc(0.0, 0.0, 1.0)

#define DEGREES_TO_RAD(deg) deg * M_PI / 180
#define dsin(deg) sin(DEGREES_TO_RAD(deg))
#define dcos(deg) cos(DEGREES_TO_RAD(deg))

#define PORT "/dev/cu.usbmodem1421"

#define PYRAMID_FILE_VIC "/Users/vmp2408/Workspace/Development/C++/OpenGL/3dmt/3DMT/Resources/pyramid.points"
#define G_FILE_VIC "/Users/vmp2408/Workspace/Development/C++/OpenGL/3dmt/3DMT/Resources/Gs.txt"
#define PYRAMID_FILE_TOR "C:\\Users\\CarlosJose\\Documents\\EclipseWorkspaces\\Kepler\\Alpha\\GLUT\\src\\Resources\\pyramid.points"
#define G_FILE_TOR "Gs.txt"

#define LEFTARROWKEY GLUT_KEY_LEFT
#define RIHGTARROWKEY GLUT_KEY_RIHGT
#define UPARROWKEY GLUT_KEY_UP
#define DOWNARROWKEY GLUT_KEY_DOWN
#define ENDKEY GLUT_KEY_END
#define PAGEDOWNKEY GLUT_KEY_PAGE_DOWN
#define PAGEUPKEY GLUT_KEY_PAGE_UP

#endif
