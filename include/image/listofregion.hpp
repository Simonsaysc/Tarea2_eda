/*
 Class ListOfRegion
*/
#pragma once
# include "image/noderegion.hpp"
# include "image/region.hpp"

namespace image {
	class ListOfRegion{
	private:
	NodeRegion* head;
	public:		
	ListOfRegion();
	void Insert(Region* region);
	virtual ~ListOfRegion();
	};
}
