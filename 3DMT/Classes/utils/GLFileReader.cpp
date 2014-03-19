//
//  GLFileReader.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 3/19/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "GLFileReader.h"

void GLFileReader::getDocumentFromFile(Document* document, string filename)
{
	FILE * pFile = fopen(filename.c_str(), "r");
	
    assert(pFile!=NULL);
    
	rapidjson::FileStream text(pFile);
    
	document->ParseStream<0>(text);
    
	fclose(pFile);
}