/*
 * Drawing.h
 *
 *  Created on: Apr 20, 2014
 *      Author: CarlosJose
 */

#ifndef DRAWING_H_
#define DRAWING_H_

#include "../utils/SpecialKeys.h"
#include "../utils/primitives/vec3.h"
#include "../utils/geometry/Line.h"

class Drawing {
	
	 vec3 lastPoint;
	 vector<vec3> referencePoints;


	PROPERTY(vec3 , mousePosition , MousePosition);
		
//	 IDrawingConcept concept = PolyLine(); --> Todos polytine
	
	//------------------
	// clone()
	// startDrag(punto)
	// endDrag(punto)
	
	
public:
	Drawing();
	virtual ~Drawing();
	void draw();
	void savePoint();
	void undo();
};

#endif /* DRAWING_H_ */
