#ifndef XPong_Drawable_h
#define XPong_Drawable_h

#include "DrawingContext.h"

namespace Pong {
	
	// Interface of an object that could be painted
	class Drawable {
		
	public:
		virtual ~Drawable() {}
		virtual void draw(DrawingContext &context) const = 0;
	};
	
}

#endif
