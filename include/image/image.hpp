/**
 * Class Image
 */

#pragma once
#include "image/listofregion.hpp"
#include "image/noderegion.hpp"
#include "image/point2D.hpp"
#include "image/listofpoint2d.hpp"
#include "image/region.hpp"
#include "image/nodepoint2d.hpp"
#include <string>

namespace image {
	class Image; 
	typedef unsigned char uchar;
	

	class Image{
	private:
		int width;
		int height;
		int th_value;
		uchar* data;
		void exploreRegion(int row, int col, bool** visited, Region& region);
	public:
		Image();
		Image(int w, int h);
		Image(int w, int h, uchar* _data);
		void threshold(); 
    	int getValue(int row, int col);
		void show();
		ListOfRegion getRegions();
        virtual ~Image(); 
		static Image* readImage(std::string &path);        
	};
}
