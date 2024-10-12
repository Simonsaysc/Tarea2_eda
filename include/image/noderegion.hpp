/*
 Class NodeRegion
*/
#pragma once
# include "image/region.hpp"

namespace image {
	class NodeRegion{
	private:	
	Region* region;
	NodeRegion* next;
	public:
	NodeRegion(Region* reg);
	void SetNext(NodeRegion* nxt);
	Region* getData();
	NodeRegion* GetNext();
	};
}
