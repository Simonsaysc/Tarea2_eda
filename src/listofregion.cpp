/* implementation of the class ListOfRegion
 */
# include "image/listofregion.hpp"
# include "image/noderegion.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
namespace image{
    ListOfRegion::ListOfRegion():head(nullptr){}; //Constructor
    void ListOfRegion::Insert(Region* region){
        NodeRegion* NewNode = new NodeRegion(region);//Declarar región

        if(head == nullptr){ //Insertar región
            head = NewNode; //Si la lista está vacía
            tail = NewNode;
        }
        else {
            tail -> SetNext(NewNode);
            tail = NewNode;           
        }
    };
    ListOfRegion::~ListOfRegion(){
        NodeRegion* current = head;
        while(current != head){
            NodeRegion* next = current-> GetNext();
            delete current -> getData();
            delete current;
        }
    }//Destructor
    NodeRegion* ListOfRegion::getHead(){return head;}
    void ListOfRegion::showRegions(){
        NodeRegion* current = head;
        while(current != nullptr){
            Region *region = current -> getData();
            region -> showRegion();
            current = current-> GetNext();
        }
    }
}