#ifndef XPong_DrawingContext_h
#define XPong_DrawingContext_h

#include "Geometry.h"

namespace Pong {
	
	struct RGBColor {
		float red;
		float green;
		float blue;
		
		RGBColor(float ared, float agreen, float ablue) : red(ared), green(agreen), blue(ablue) {}
		RGBColor(float color) : red(color), green(color), blue(color) {}
	};
	
	// Decouples game objects from the OS-specific painting routines
	class DrawingContext {
		
	public:
		DrawingContext() : _fillColor(RGBColor(1)) {}
		virtual ~DrawingContext() {}
		RGBColor fillColor() const { return _fillColor; }
		virtual void setFillColor(RGBColor const &color) { _fillColor = color; }
		virtual void fillRectangle(Rectangle bounds) = 0;
		virtual void fillOval(Rectangle bounds) = 0;
		
	private:
		RGBColor _fillColor;
	};
	
}

#endif
