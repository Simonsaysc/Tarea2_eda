/* implementation of the class ListOfPoint2D
 */
#include "image/listofpoint2d.hpp"
#include "image/nodepoint2d.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
namespace image{
    ListOfPoint2D::ListOfPoint2D():head(nullptr), tail(nullptr){}

    void ListOfPoint2D::Insert(int x, int y){
        NodePoint2D* newNode = new NodePoint2D(x, y);
        if(!head){ //si la lista está vacía 
            head = tail = newNode;
        }
        else{ //si hay elementos agergo al final
            tail->next = newNode;
            tail = newNode;
        }
    }

    void ListOfPoint2D::ShowPoints(){
        NodePoint2D* current = head;
        while(current){
            std::cout<<"("<<current->point.getX()<<","<< current->point.getY()<<")";
            current = current->next;
        }
        std::cout<<std::endl;
    }
    std::vector<Point2D> ListOfPoint2D::getPoints(){
        std::vector<Point2D> points;
        NodePoint2D* current = head;

        while (current){
            points.push_back(current->point)//copiar cada punto al vector
            current = current->next;
        }
        return points;
    }
    ListOfPoint2D::~ListOfPoint2D(){
        NodePoint2D* current = head;
        while (current){
            NodePoint2D* temp = current;
            current = current->next;
            delete temp;
        }
    }
}