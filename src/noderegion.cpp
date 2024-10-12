/* implementation of the class NodeRegion
 */
# include "image/noderegion.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>

namespace image{
    NodeRegion::NodeRegion(Region* r):region(r), next(nullptr){}
    Region* NodeRegion::getData(){return region;}
    void NodeRegion::SetNext(NodeRegion* nxt){next = nxt;}
    NodeRegion* NodeRegion::GetNext(){return next;}
}