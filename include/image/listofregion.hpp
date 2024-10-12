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
	NodeRegion* tail;
	public:		
	ListOfRegion();
	void Insert(Region* region);
	void showRegions();
	virtual ~ListOfRegion();
	};
}
