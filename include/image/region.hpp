/*
 Class Region
*/
#pragma once
# include "image/listofpoint2d.hpp"
namespace image {
	class Region{
	private:
		int id;//identificador de la región
		int size;//tamaño de la región
		ListOfPoint2D points;//Puntos q conforman la región		
	public:
		Region(int _id);//constructor
		void addPoint(int x, int y);//Agrega un punto a la región
		void showRegion();//muestra la región en la consola
		int getSize();//tamaño de la región
		std::vector<Point2D> getPoints();
        ~Region(); 		
	};
}
