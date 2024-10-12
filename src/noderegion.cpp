/* implementation of the class NodeRegion
 */
# include "image/noderegion.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>

namespace image{
    NodeRegion::NodeRegion(Region* r):region(r), next(nullptr){} //constructor
    Region* NodeRegion::getData(){return region;} //Obtiene toda la región
    void NodeRegion::SetNext(NodeRegion* nxt){next = nxt;}// Pone próximo nodo
    NodeRegion* NodeRegion::GetNext(){return next;}//Obtiene próximo nodo
    NodeRegion::~NodeRegion(){}
}