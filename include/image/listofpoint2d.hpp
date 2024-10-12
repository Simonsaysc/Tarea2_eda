/*
 Class ListOfPoint2D
*/
#pragma once
#include "image/nodepoint2d.hpp"
#include <vector>

namespace image {
	class NodePoint2D;

	class ListOfPoint2D{
	private:
	NodePoint2D* head;//ptr al primero de la lista
	NodePoint2D* tail;//ptr al último de la lista
	public:		
	ListOfPoint2D(); //constructor
	void addPoint(int x, int y);//agrega un punto a la lista
	void ShowPoints();//mostrar puntos en la consola
	std::vector<Point2D> getPoints();//devuelve los puntos del vector
	~ListOfPoint2D();//destructor
	};
}
