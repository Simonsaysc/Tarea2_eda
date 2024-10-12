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
        }
        else {
            NodeRegion* current = head;
            while(current -> GetNext() != nullptr){
                current = current -> GetNext();
            }
            current -> SetNext(NewNode);
        }
    };
    ListOfRegion::~ListOfRegion(){}//Destructor

    void ListOfRegion::showRegions(){
        NodeRegion* current = head;
        while(current != nullptr){
            Region *region = current -> getData();
            region -> showRegion();
            current = current-> GetNext();
        }
    }
}