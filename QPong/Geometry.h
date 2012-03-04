#ifndef XPong_Geometry_h
#define XPong_Geometry_h

#include <cmath>
#include <algorithm>
#include <iostream>

namespace Pong {
	
	using std::min;
	using std::max;

	struct Point {
		float x;
		float y;
		
		Point(float ax, float ay) : x(ax), y(ay) {}
		
		friend std::ostream & operator<< (std::ostream &s, Point const &v) {
			return s << "{" << v.x << "," << v.y << "}";
		}
	};
	
	struct Rectangle {
		float x;
		float y;
		float width;
		float height;

		Rectangle(float ax, float ay, float awidth, float aheight) :
		x(ax), y(ay), width(awidth), height(aheight) {}

		inline Point center() const { return Point(x + width / 2, y + height / 2); }
		inline float right() const { return x + width; }
		inline float bottom() const { return y + height; }
		
		inline Rectangle enclosingRectangle(Rectangle const &rectangle) const {
			const float ex = min(x, rectangle.x);
			const float ey = min(y, rectangle.y);
			const float eright = max(right(), rectangle.right());
			const float ebottom = max(bottom(), rectangle.bottom());
			return Rectangle(ex, ey, eright - ex, ebottom - ey);
		}
		
		inline bool intersectsRectangle(Rectangle const &rectangle) const {
			return x < rectangle.right() && right() > rectangle.x && y < rectangle.bottom() && bottom() > rectangle.y;
		}

		friend std::ostream & operator<< (std::ostream &s, Rectangle const &v) {
			return s << "{" << v.x << "," << v.y << "," << v.width << "," << v.height << "(" << v.right() << "," << v.bottom() << ")" << "}";
		}
	};

}

#endif
