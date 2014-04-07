//
//  DataBuffer.h
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/2/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef ___DMT__DataBuffer__
#define ___DMT__DataBuffer__

#include "../SpecialKeys.h"

class DataBuffer: public string
{
public:
    
    DataBuffer();
    ~DataBuffer();
    
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "DataBuffer.cpp"
#endif

#endif /* defined(___DMT__DataBuffer__) */
