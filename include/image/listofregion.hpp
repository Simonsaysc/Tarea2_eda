/*
 Class ListOfRegion
*/
# include "image/noderegion.hpp"

namespace image {
	class ListOfRegion{
	private:
	NodeRegion* head;
	public:		
	ListOfRegion();
	void Insert();
	virtual ~ListOfRegion();
	};
}
