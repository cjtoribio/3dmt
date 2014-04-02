//
//  GLFileReader.h
//  3DMT
//
//  Created by Victor Manuel Polanco on 3/19/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef ___DMT__GLFileReader__
#define ___DMT__GLFileReader__

#include <string>
#include "rapidjson/document.h"
#include "rapidjson/filestream.h"

using std::string;

using rapidjson::Document;
using rapidjson::FileStream;
using rapidjson::Value;
using rapidjson::SizeType;

class GLFileReader
{
public:
	static void getDocumentFromFile(Document* document, string filename);
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "GLFileReader.cpp"
#endif

#endif /* defined(___DMT__GLFileReader__) */
