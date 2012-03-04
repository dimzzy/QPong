#include "Paddle.h"
#include "Geometry.h"

namespace Pong {

	GameObject *Paddle::clone() const {
		return new Paddle(*this);
	}

	void Paddle::moveByFrame(float fieldWidth, float fieldHeight) {
		bounds().y += speed();
		
		// stop at the top and bottom edges
		if (bounds().y < 0) {
			bounds().y = 0;
			setSpeed(0);
		} else if (bounds().bottom() > fieldHeight) {
			bounds().y = fieldHeight - bounds().height;
			setSpeed(0);
		}
	}
	
	void Paddle::draw(DrawingContext &context) const {
		context.setFillColor(RGBColor(0));
		context.fillRectangle(bounds());
	}

}
