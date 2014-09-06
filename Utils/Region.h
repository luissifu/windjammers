#pragma once
#include <vector>

struct point {
	float x;
	float y;
	float z;
};

class Region {
	public::
		Region();
		Region(float x, float y, float z, float width, float height, float depth);
		//
		float x;
		float y;
		float z;
		float width;
		float height;
		float depth;
		//
		std::vector<Region> split();
		void inside(float x, float y, float z);
		void inside(point p);
		point getMidPoint();
};