/* implementation of the class ListOfRegion
 */
# include "image/listofregion.hpp"
# include "image/noderegion.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
namespace image{
    ListOfRegion::ListOfRegion():head(nullptr){};
    void ListOfRegion::Insert(Region* region){
        NodeRegion* NewNode = new NodeRegion(region);

        if(head == nullptr){
            head = NewNode;
        }
        else {
            NewNode->SetNext(head);
            head = NewNode;
        }
    };
    ListOfRegion::~ListOfRegion(){}

}