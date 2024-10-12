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
            NewNode->SetNext(head); //Si no está vacía
            head = NewNode;
        }
    };
    ListOfRegion::~ListOfRegion(){}//Destructor

}