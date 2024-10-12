/* implementation of the class NodePoint2D
 */

# include "image/nodepoint2d.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
namespace image{

    NodePoint2D::NodePoint2D(int x, int y) : point(x,y), next(nullptr){}

    NodePoint2D::~NodePoint2D(){}
}