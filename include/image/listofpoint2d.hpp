/*
 Class ListOfPoint2D
*/
# include "image/nodepoint2d.hpp"

namespace image {
	class ListOfPoint2D{
	private:
	NodePoint2D* head;
	public:		
	ListOfPoint2D();
	void Insert();
	virtual ~ListOfPoint2D();
	};
}
