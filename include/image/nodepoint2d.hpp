/*
 Class NodePoint2D
*/
#pragma once
#include "image/point2D.hpp"

namespace image {
	class NodePoint2D {
	public:
		Point2D point; //el punto guarda las coords x,y
		NodePoint2D* next; //ptr next al sgte nodo

		NodePoint2D(int x, int y); //constructor
		~NodePoint2D(); //destructor
	};
}

