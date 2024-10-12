/*
 Class Point2D
*/

#pragma once
namespace image {
	class Point2D{
	private:
		int x;
		int y;		
	public:
		Point2D();
		Point2D(int _x, int _y);

        void setX(int _x);
        void setY(int _y);
		
        int getX() const;
        int getY() const;
        virtual ~Point2D(); 		
	};
}
