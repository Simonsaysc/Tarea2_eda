# include "image/region.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>

namespace image {
    Region::Region(int _id):id(_id), size(0){}
    void Region::addPoint(int x, int y){
        points.addPoint(x,y); //agregar punto a la lista enlazada
        size++;//incrementar tamaño
    }

    void Region::showRegion(){
        std::cout <<"Region "<< id <<" with size "<< size << std::endl;
        points.ShowPoints(); //muestra los puntos de la región
    }

    int Region::getSize(){
        return size;
    }
    std::vector<Point2D> Region::getPoints(){
        return point.getPoints();//Devuelve los puntos como vector
    }
    Region::~Region(){
        //No hay q liberar nada pq points (ListOfPoint2D) ya maneja su propia memoria
        std::cout<<"Destruyendo región id" << id <<std::endl;
    }
}