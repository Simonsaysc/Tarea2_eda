/*
 Class NodeRegion
*/
# include "image/region.hpp"

namespace image {
	class NodeRegion{
	private:	
	Region* region;
	NodeRegion* next;
	public:
	NodeRegion();
	void SetNext();
	NodeRegion* GetNext();
	};
}
